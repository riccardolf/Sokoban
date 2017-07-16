#include"Livello.h"

Livello::Livello(const Coordinate& g, vector<Cassa*> c, vector<Coordinate*> m, ALLEGRO_BITMAP* PG, ALLEGRO_BITMAP* B, ALLEGRO_BITMAP* C, bool mod, bool a)
{
	this->inizializzaAllegro();
	
	// Si inizializza il livello	
	audio=a;
	player=g;
	modalita=mod;
	muri=m;
	casse=c;
	Box = B;
	Player = PG;
	BoxColor = C;
	
	mappa=new int*[12];
	for(int i=0; i<12; i++)
		mappa[i]=new int [10];
	
	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j] = niente;

	int x=g.getX();
	int y=g.getY();
	mappa[x][y] = giocatore;
	
	for(unsigned i=0; i<casse.size(); i++)
	{	
		x=casse[i]->getX();
		y=casse[i]->getY();		
		mappa[x][y] = cassa;
	}
	
	for(unsigned i=0; i<muri.size(); i++)
	{
		x=muri[i]->getX();
		y=muri[i]->getY();
		mappa[x][y] = wall;
	}

	mosse.push(new Mossa(player, mappa, 0));		// mossa: 0		Come inizia il livello
}

Livello::Livello(const Livello& l)
{
	audio=l.audio;
	modalita=l.modalita;
	player=l.player;
	muri=l.muri;
	casse=l.casse;
	Box = l.Box;
	Player = l.Player;
	BoxColor = l.BoxColor;
	
	mappa=new int*[12];
	for(int i=0; i<12; i++)
		mappa[i]=new int [10];
	
	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j] = l.mappa[i][j];

	display=l.display;
	timer=l.timer;
	event_queue=l.event_queue;
	Undo=l.Undo;
	Box=l.Box;
	BoxColor=l.BoxColor;
	Player=l.Player;
	Wall=l.Wall;
	sfondo=l.sfondo;
	Superato=l.Superato;
}

Livello& Livello::operator=(const Livello& l)
{
	if(this!=&l)
	{
		audio=l.audio;
		modalita=l.modalita;
		player=l.player;
		muri=l.muri;
		casse=l.casse;
		al_destroy_bitmap(Box);		
		al_destroy_bitmap(Player);
		al_destroy_bitmap(BoxColor);
		Box = l.Box;
		Player = l.Player;
		BoxColor = l.BoxColor;

		for(int i=0; i<12; i++)
			delete[] mappa[i];
		delete[]mappa;
		
		destroy();
		mappa=new int*[12];
		for(int i=0; i<12; i++)
			mappa[i]=new int [10];

		for(int i=0; i<12; i++)
			for(int j=0; j<10; j++)
				mappa[i][j] = l.mappa[i][j];

		display=l.display;
		timer=l.timer;
		event_queue=l.event_queue;
		Undo=l.Undo;
		Box=l.Box;
		BoxColor=l.BoxColor;
		Player=l.Player;
		Wall=l.Wall;
		sfondo=l.sfondo;
		Superato=l.Superato;
	}
	return *this;
}

Livello::~Livello()
{
	muri.clear();
	casse.clear();
	for(int i=0; i<12; i++)
		delete[] mappa[i];
	delete[]mappa;
}

//Distruttore oggetti Allegro
void Livello::destroy()
{
	clearMosse();
	mosse.pop();
	al_destroy_bitmap(Superato);
	al_destroy_bitmap(Undo);
	al_destroy_bitmap(Muto);
	al_destroy_bitmap(Torna);
	al_destroy_bitmap(Audio);
	al_destroy_bitmap(Rigioca);
	al_destroy_bitmap(sfondo);
	al_destroy_bitmap(Wall);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}

//Distruzioni mosse dallo stack
bool Livello::clearMosse()
{		
	if(mosse.size()<2)
		return false;
	
	while(mosse.size()>1)
	{
		mosse.pop();
	}

	return true;
}
const int undo_x = 580, audio_x = 520, rigioca_x = 640, torna_x=700;
//Disegno della mappa
void Livello::drawMap(int dir) 
{
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(sfondo, 0, 0, 0);

	al_draw_bitmap(Undo, undo_x, 0, 0);
	al_draw_bitmap(Rigioca, rigioca_x, 0, 0);

	if(audio)
		al_draw_bitmap(Audio, audio_x, 0, 0);
	else
		al_draw_bitmap(Muto, audio_x, 0, 0);

	if(modalita)	
		al_draw_bitmap(Torna, torna_x, 0, 0);

	for(unsigned i=0; i<casse.size(); i++)
		al_draw_filled_circle(casse[i]->getEndX()*64+42,casse[i]->getEndY()*64+32, 6.5, al_map_rgb(255,0,0));	

	// 0=niente	 1=muri	 2=casse  3=giocatore  4=undo  5=rigioca  6=mute  7=audio  8=seleziona liv
	for(unsigned i=0; i<12; i++)
		for(unsigned j=0; j<10; j++)
		{		
			if(mappa[i][j] == wall)
				al_draw_bitmap(Wall, i*64 +10, j * 64, 0);
			else if(mappa[i][j] == cassa)
				al_draw_bitmap(Box, i*64 +10, j * 64, 0);
			else if(mappa[i][j] == giocatore)
				al_draw_bitmap_region(Player, dir * 64, 0, 64, 64, i*64 +10, j*64, 0);
			
		}
	
	for (unsigned i = 0; i < casse.size(); i++)
	 {
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] == cassa)
			al_draw_bitmap(BoxColor, x*64 +10, y*64, 0);
	}
	al_flip_display();
	
}

int Livello::gioca()
{
	enum KEYS {DOWN = 0, LEFT, UP, RIGHT, BACKSPACE, R, M, ALTGR};  
	bool keys[] = { false, false, false, false, false, false, false, false };
	int x = 0, y = 0, dir = 0, cont = 0;
	
	// start music
	if(audio)
		al_play_sample_instance(songInstance);

	bool draw=false;
	drawMap(dir);
	
	
	//Inizio timer e game loop
	al_start_timer(timer);

	while (true) 
	{	
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			destroy();
			return -1;
		}			
      
		int player_x = player.getX();
		int player_y = player.getY();

		// 0=Aria	 1=Muri	 2=Casse  3=Giocatore
		//Movimenti di Casse e Giocatore
		if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_BACKSPACE:
				keys[BACKSPACE] = true;
				break;
			case ALLEGRO_KEY_R:
				keys[R] = true;
				break;
			case ALLEGRO_KEY_M:
				keys[M] = true;
				break;
			case ALLEGRO_KEY_ALTGR:
				if(modalita)
					keys[ALTGR] = true;
				break;
			}
		
		 	if (keys[DOWN])
 		 	{
				dir = DOWN;
				if (mappa[player_x][player_y + 1] == niente)
				{
					draw = true;
					player.sposta(dir);
					mappa[player_x][player_y + 1] = giocatore;
					mappa[player_x][player_y] = niente;
				}
				else if (mappa[player_x][player_y + 1] == cassa && mappa[player_x][player_y + 2] == niente)
				{
					draw = true;			
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y + 1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.sposta(dir);

					mappa[player_x][player_y + 1] = giocatore;
					mappa[player_x][player_y] = niente;
					mappa[player_x][player_y + 2] = cassa;

				}

			}
			else if (keys[UP])
			{
				dir = UP;
				if (mappa[player_x][player_y - 1] == niente)
				{
					draw = true;
					player.sposta(dir);
					mappa[player_x][player_y - 1] = giocatore;
					mappa[player_x][player_y] = niente;

				}
				else if (mappa[player_x][player_y - 1] == cassa && mappa[player_x][player_y - 2] == niente)
				{
					draw = true;
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y - 1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.sposta(dir);
					mappa[player_x][player_y - 1] = giocatore;
					mappa[player_x][player_y] = niente;
					mappa[player_x][player_y - 2] = cassa;

				}

			}
			else if (keys[RIGHT])
			{
				dir = RIGHT;
				if (mappa[player_x + 1][player_y] == niente)
				{
					draw = true;
					player.sposta(dir);
					mappa[player_x + 1][player_y] = giocatore;
					mappa[player_x][player_y] = niente;

				}
				else if (mappa[player_x + 1][player_y] == cassa && mappa[player_x + 2][player_y] == niente)
				{
					draw = true;
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x + 1)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.sposta(dir);
					mappa[player_x + 1][player_y] = giocatore;
					mappa[player_x][player_y] = niente;
					mappa[player_x + 2][player_y] = cassa;

				}
			}
			else if (keys[LEFT])
			{
				dir = LEFT;
				if (mappa[player_x - 1][player_y] == niente)
				{
					draw = true;	
					player.sposta(dir);
					mappa[player_x - 1][player_y] = giocatore;
					mappa[player_x][player_y] = niente;
				}
				else if (mappa[player_x - 1][player_y] == cassa && mappa[player_x - 2][player_y] == niente)
				{
					draw = true;
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x - 1)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.sposta(dir);
					mappa[player_x - 1][player_y] = giocatore;
					mappa[player_x][player_y] = niente;
					mappa[player_x - 2][player_y] = cassa;

				}
			}
			else if (keys[BACKSPACE] && mosse.size()>1)		// Undo
			{
				cont++;
				mosse.pop();				
				player=mosse.top()->getPlayer();
				mappa=mosse.top()->getMappa();
				dir=mosse.top()->getDir();
	
				drawMap(dir);
			}
			else if (keys[R] && mosse.size()>1)		// Rigioca
			{	
				cont++;
				rigioca();

				drawMap(0);
			}
			else if (keys[M] && audio)	// mute
			{
				audio = false;
				al_play_sample_instance(songInstance);
			}				
			else if (keys[M] && !audio)	// riattiva volume
			{
				audio = true;
				al_stop_sample_instance(songInstance);
			}				
			else if (keys[ALTGR] && modalita)	// torna a seleziona livelli
			{
				return selezionaNuovoLivello();
			}
		}
		else if (events.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_BACKSPACE:
				keys[BACKSPACE] = false;
				break;
			case ALLEGRO_KEY_R:
				keys[R] = false;
				break;
			case ALLEGRO_KEY_M:
				keys[M] = false;
				break;
			case ALLEGRO_KEY_ALTGR:
				if(modalita)
					keys[ALTGR] = false;
				break;
			}
		}

		int a=0, b=0, dim=57;
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			a=events.mouse.x;
			b=events.mouse.y;
			
				// Undo					
			if(a >= undo_x && a <= undo_x+dim && b >= 0 && b <= dim && mosse.size()>1)
			{
				cont++;
				mosse.pop();				
				player=mosse.top()->getPlayer();
				mappa=mosse.top()->getMappa();
				dir=mosse.top()->getDir();

				drawMap(dir);
			}
				// Rigioca
			else if(a >= rigioca_x && a <= rigioca_x+dim && b >= 0 && b <= dim && mosse.size()>1)
			{	
				cont++;
				rigioca();

				drawMap(0);
			}
				// audio
			else if(a >= audio_x && a <= audio_x+dim && b >= 0 && b <= dim)
			{
				if (audio)	// mute
				{
					audio = false;				
					al_play_sample_instance(songInstance);
					al_draw_bitmap(Muto, audio_x, 0, 0);
					al_flip_display();
				}				
				else 		// riattiva volume
				{
					audio = true;
					al_stop_sample_instance(songInstance);
					al_draw_bitmap(Audio, audio_x, 0, 0);
					al_flip_display();
				}				
			}
			
			else if(a >= torna_x && a <= torna_x+dim && b >= 0 && b <= dim)
			{
				return selezionaNuovoLivello();	
			}
		}

		if (events.type == ALLEGRO_EVENT_TIMER && draw && al_is_event_queue_empty(event_queue))
		{
		//Inserimento ultima mossa fatta
			mosse.push(new Mossa(player, mappa, dir));
			
		//Disegno della mappa
			draw=false;
			drawMap(dir);
		}

		//Controllo fine livello
		if(Done())
		{
			int num=mosse.size()+cont;
			al_draw_bitmap(Superato,0,0,0);
			al_draw_textf(font,al_map_rgb(255,255,255), 240, 400, 0, "MOSSE: %i ", num);
			al_flip_display();
			al_rest(1.5);
			al_clear_to_color(al_map_rgb(0,0,0));
			
			if(!modalita) // modalita arcade
			{
				destroy();
				return 1;
			}
		
			// modalita seleziona livello			
			return selezionaNuovoLivello();
				
		}
	}
}

void Livello::rigioca()
{
	clearMosse();
	player.restart();
	
	for(unsigned i=0; i<casse.size(); i++)
		casse[i]->restart();

	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j] = niente;

	int x=player.getX();
	int y=player.getY();
	mappa[x][y] = giocatore;
	
	for(unsigned i=0; i<casse.size(); i++)
	{	
		x=casse[i]->getX();
		y=casse[i]->getY();		
		mappa[x][y] = cassa;
	}
	
	for(unsigned i=0; i<muri.size(); i++)
	{
		x=muri[i]->getX();
		y=muri[i]->getY();
		mappa[x][y] = wall;
	}

}

int Livello::selezionaNuovoLivello()
{
	int liv_x[] = {11,291,572};
	int liv_y[] = {10,232,453};
	int x2=0, y2=0;

	ALLEGRO_BITMAP* Levels = al_load_bitmap("Levels.jpg");
	al_draw_bitmap(Levels,0,0,0);
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	// scelta livello
	while (x2<liv_x[0] || x2>liv_x[2]+208 || y2<liv_y[0] || y2>liv_y[2]+197 || x2>liv_x[0]+208 && x2<liv_x[1] || 
	x2>liv_x[1]+208 && x2<liv_x[2] || y2>liv_y[0]+197 && y2<liv_y[1] || y2>liv_y[1]+197 && y2<liv_y[2])
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			x2 = ev.mouse.x;
			y2 = ev.mouse.y;
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			al_destroy_bitmap(Levels);
			destroy();
			return -1;
		}
	}
	

	al_destroy_bitmap(Levels);
	destroy();
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++)
			if (x2 >= liv_x[i] && x2 <= liv_x[i] + 215 && y2 >= liv_y[j] && y2 <= liv_y[j] + 215)
				return (3*j+i);
}

//Controllo superamento livello
bool Livello::Done() const
{
	for (unsigned i = 0; i < casse.size(); i++)
	{
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] != cassa)
			return false;
	}
	return true;
}

//Inizializzazione oggetti Allegro
void Livello::inizializzaAllegro()
{
	if(!al_init())
		cerr<<"no allegro"<<endl;

	if(!al_init_image_addon())
	  cerr<<"failed initialisation image addon"<<endl;
	
	if(!al_init_primitives_addon())
	  cerr<<"failed initialisation primitives addon"<<endl;

	if(!al_init_native_dialog_addon())
	  cerr<<"failed initialisation dialog addon"<<endl;

	if(!al_init_font_addon() || !al_init_ttf_addon())
	  cerr<<"failed initialisation font addon"<<endl;

	if(!al_install_audio() || !al_init_acodec_addon())
		cerr << "no audio" << endl;

	if(!al_install_keyboard())
		cerr<<"no keyboard"<<endl;
	
	if(!al_install_mouse())
		cerr<<"no mouse"<<endl;
	
	display=al_create_display(800,700);

	if(!display)
		cerr<<"no display"<<endl;
	al_set_window_title(display,"Sokoban");

	const float FPS=30;
	timer=al_create_timer(1/FPS);
	if(!timer)
		cerr<<"no timer"<<endl;

	font=al_load_ttf_font("Rocko.ttf",70,0);
	if(!font)
		cerr<<"no font"<<endl;

	event_queue=al_create_event_queue();
	if(!event_queue)
		cerr<<"no event_queue"<<endl;

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());	

	Wall = al_load_bitmap("wall.png");
	Undo = al_load_bitmap("Indietro.png");
	Rigioca = al_load_bitmap("Ripeti.png");
	Audio = al_load_bitmap("volume.png");
	Muto = al_load_bitmap("muto.png");
	Torna = al_load_bitmap("SelezioneLivelli.png");
	sfondo = al_load_bitmap("Background.jpg");	
	Superato = al_load_bitmap("Superato.jpg");

	al_reserve_samples(10);
	song = al_load_sample("Song.ogg");
	songInstance = al_create_sample_instance(song);
	if(!song || !songInstance)
		cerr<<"no song"<<endl;

	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

}
