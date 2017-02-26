#include"Livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa*> c, vector<Muro*> m, ALLEGRO_BITMAP* PG, ALLEGRO_BITMAP* B, ALLEGRO_BITMAP* C)
{
	this->inizializzaAllegro();

	//Inizializzo il livello
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
			mappa[i][j] = 0;

	// 0=niente	 1=muri	 2=casse  3=giocatore
	int x=g.getX();
	int y=g.getY();
	mappa[x][y]=3;
	
	for(unsigned i=0; i<casse.size(); i++)
	{	
		x=casse[i]->getX();
		y=casse[i]->getY();		
		mappa[x][y]=2;
		}
	
	for(unsigned i=0; i<muri.size(); i++)
	{
		x=muri[i]->getX();
		y=muri[i]->getY();
		mappa[x][y]=1;
	}

	mosse.push(new Mossa(g, mappa));		// mossa: 0		Come inizia il livello
}


Livello::~Livello()
{
	muri.clear();
	casse.clear();
	for(int i=0; i<12; i++)
		delete[] mappa[i];
	delete[]mappa;
}

//Distruzioni mosse dallo stack
bool Livello::clear(stack<Mossa*>& mosse, unsigned dim)
{		
	if(dim<1)
		return false;
	
	while(dim>0)
	{
		mosse.pop();
		dim--;
	}

	return true;
}

//Disegno della mappa
const int undo_x = 720, undo_y = 0;
void Livello::drawMap(int dir) const
{
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(sfondo, 0, 0, 0);
	al_draw_bitmap(Undo, undo_x, undo_y, 0);

	for(unsigned i=0; i<casse.size(); i++)
		al_draw_filled_circle(casse[i]->getEndX()*64+42,casse[i]->getEndY()*64+32, 6.5, al_map_rgb(255,0,0));	
	
	for(unsigned i=0; i<12; i++)
		for(unsigned j=0; j<10; j++)
		{		
			if(mappa[i][j] ==1)
				al_draw_bitmap(Wall, i*64 +10, j * 64, 0);
			else if(mappa[i][j]==2)
				al_draw_bitmap(Box, i*64 +10, j * 64, 0);
			else if(mappa[i][j]==3)
				al_draw_bitmap_region(Player, dir * 64, 0, 64, 64, i*64 +10, j*64, 0);
		}
	
	for (unsigned i = 0; i < casse.size(); i++)
	 {
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] == 2)
			al_draw_bitmap(BoxColor, x*64 +10, y*64, 0);
	}
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

//Distruttore oggetti Allegro
void Livello::destroy()
{
	clear(mosse, mosse.size());
	al_destroy_bitmap(Undo);
	al_destroy_bitmap(sfondo);
	al_destroy_bitmap(Wall);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}


bool Livello::gioca()
{
	enum DIR {DOWN = 0, LEFT,UP, RIGHT};  
	bool keys[4] = { false, false, false, false };
	int x = 0, y = 0, dir = 0;
	
	//Posizioni iniziali del livello
	Giocatore player=mosse.top()->getPlayer();
	
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
			return false;
		}			
      
		else if (events.type == ALLEGRO_EVENT_TIMER)
		{
			int player_x = player.getX();
			int player_y = player.getY();

			// 0=Aria	 1=Muri	 2=Casse  3=Giocatore
			//Movimenti di Casse e Giocatore

			if (keys[DOWN])
			{
				draw = true;
				dir = 0;
				if (mappa[player_x][player_y + 1] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x][player_y + 1] = 3;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x][player_y + 1] == 2 && mappa[player_x][player_y + 2] == 0)
				{
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y + 1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.MovePlayer(dir);

					mappa[player_x][player_y + 1] = 3;
					mappa[player_x][player_y] = 0;
					mappa[player_x][player_y + 2] = 2;

				}

			}
			else if (keys[UP])
			{
				draw = true;
				dir = 2;
				if (mappa[player_x][player_y - 1] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x][player_y - 1] = 3;
					mappa[player_x][player_y] = 0;

				}
				else if (mappa[player_x][player_y - 1] == 2 && mappa[player_x][player_y - 2] == 0)
				{
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y - 1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.MovePlayer(dir);
					mappa[player_x][player_y - 1] = 3;
					mappa[player_x][player_y] = 0;
					mappa[player_x][player_y - 2] = 2;

				}

			}
			else if (keys[RIGHT])
			{
				draw = true;
				dir = 3;
				if (mappa[player_x + 1][player_y] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x + 1][player_y] = 3;
					mappa[player_x][player_y] = 0;

				}
				else if (mappa[player_x + 1][player_y] == 2 && mappa[player_x + 2][player_y] == 0)
				{
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x + 1)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.MovePlayer(dir);
					mappa[player_x + 1][player_y] = 3;
					mappa[player_x][player_y] = 0;
					mappa[player_x + 2][player_y] = 2;

				}
			}
			else if (keys[LEFT])
			{
				draw = true;
				dir = 1;
				if (mappa[player_x - 1][player_y] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x - 1][player_y] = 3;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x - 1][player_y] == 2 && mappa[player_x - 2][player_y] == 0)
				{
					for (unsigned i = 0; i < casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x - 1)
						{
							casse[i]->sposta(dir);
							break;
						}
					player.MovePlayer(dir);
					mappa[player_x - 1][player_y] = 3;
					mappa[player_x][player_y] = 0;
					mappa[player_x - 2][player_y] = 2;

				}
			}
		}

		else if (events.type == ALLEGRO_EVENT_KEY_DOWN)
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
			}
		}

		//Disegno della mappa
		if(draw && al_is_event_queue_empty(event_queue))
		{
				draw=false;

				drawMap(dir);
				
			//Inserimento ultima mossa fatta
				mosse.push(new Mossa(player, mappa));
		}

		//Undo
		int a=0, b=0;
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			a=events.mouse.x;
			b=events.mouse.y;
					
			if(a>=undo_x && a<=undo_x+64 && b>=undo_y && b<=undo_y+64 && mosse.size()>1)
			{
				mosse.pop();				
				player=mosse.top()->getPlayer();
				mappa=mosse.top()->getMappa();
					
				drawMap(dir);
			}
			
		}

		//Controllo fine livello
		if(Done(casse))
		{
			for (int i = 0; i < 4; i++)
				keys[i] = false;

			al_show_native_message_box(al_get_current_display(), "COMPLIMENTI", "LIVELLO SUPERATO!", "",0,ALLEGRO_MESSAGEBOX_WARN);
			destroy();
			return true;
		}
	}

}

//Controllo superamento livello
bool Livello::Done(vector<Cassa*> casse) const
{
	for (unsigned i = 0; i < casse.size(); i++)
	{
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] != 2)
			return false;
	}
	return true;
}

//Inizializzazione oggetti Allegro
void Livello::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

	if(!al_init_image_addon())
	{ 
	  cerr<<"failed initialisation image"<<endl;
	}
	
	if(!al_init_primitives_addon())
	{ 
	  cerr<<"failed initialisation primitives"<<endl;
	}

	if(!al_init_native_dialog_addon())
	{ 
	  cerr<<"failed initialisation dialog"<<endl;
	}

	if(!al_install_keyboard())
	{
		cerr<<"no keyboard"<<endl;
	}
	
	if(!al_install_mouse())
	{
		cerr<<"no mouse"<<endl;
	}		
	
	display=al_create_display(800,700);

	if(!display)
	{
		cerr<<"no display"<<endl;
	}
	al_set_window_title(display,"Sokoban");

	const float FPS=12;
	timer=al_create_timer(1/FPS);
	if(!timer)
	{
		cerr<<"no timer"<<endl;
	}

	event_queue=al_create_event_queue();
	if(!event_queue)
	{
		cerr<<"no event_queue"<<endl;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());	

	Wall = al_load_bitmap("wall.png");
	Undo = al_load_bitmap("Indietro.png");
	sfondo = al_load_bitmap("Background.jpg");	
}
