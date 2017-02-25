#include"Livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa*> c, vector<Muro*> m)
{
	this->inizializzaAllegro();

	//Inizializzo il livello
	muri=m;
	casse=c;

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

	mosse.push(new Mossa(g, mappa));		// mossa 0		come inizia il livello
}

Livello::~Livello()
{
	for(int i=0; i<12; i++)
		delete[] mappa[i];
	delete[]mappa;
}
	
bool Livello::clear(stack<Mossa*>& mosse, unsigned dim)
{		
	if(dim<2)
		return false;
	
	while(dim>1)
	{
		mosse.pop();
		dim--;
	}

	return true;

}

const int undo_x = 570, undo_y = 0;//, rigioca_x = 576, rigioca_y = 0;
void Livello::drawMap(int dir) const
{
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(sfondo, 0, 0, 0);
	al_draw_bitmap(Undo, undo_x, undo_y, 0);
	//al_draw_bitmap(Rigioca, rigioca_x, rigioca_y, 0);

	for(unsigned i=0; i<casse.size(); i++)
		al_draw_filled_circle(casse[i]->getEndX()*64+32,casse[i]->getEndY()*64+32, 8, al_map_rgb(255,0,0));	
	
	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
		{		
			if(mappa[i][j] ==1)
				al_draw_bitmap(Wall, i * 64, j * 64, 0);
			else if(mappa[i][j]==2)
				al_draw_bitmap(Box, i * 64, j * 64, 0);
			else if(mappa[i][j]==3)
				al_draw_bitmap_region(Player, dir * 64, 0, 64, 64, i * 64, j * 64, 0);
		}
	
	for (unsigned i = 0; i < casse.size(); i++)
	 {
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] == 2)
			al_draw_bitmap(BoxColor, x * 64, y * 64, 0);
	}
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

bool Livello::gioca()
{
	//Posizioni iniziali del livello
	Giocatore player=mosse.top()->getPlayer();
	enum DIR {DOWN = 0, LEFT,UP, RIGHT};  
	int dir=0;
	ALLEGRO_KEYBOARD_STATE keystate;
	
	bool draw=false;
	
	drawMap(dir);
	
	//inizio timer e game loop
	al_start_timer(timer);

	while (true) 
	{	
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			clear(mosse, mosse.size());
			mosse.pop();
			al_destroy_bitmap(Undo);
		//	al_destroy_bitmap(Rigioca);
			al_destroy_bitmap(sfondo);
			al_destroy_bitmap(Box);
			al_destroy_bitmap(BoxColor);
			al_destroy_bitmap(Wall);
			al_destroy_bitmap(Player);
			al_destroy_timer(timer);
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			return false;
		}			
      
		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			int player_x=player.getX();
			int player_y=player.getY();
	
			// 0=Aria	 1=Muri	 2=Casse  3=Giocatore
			//Movimenti di Casse e Giocatore
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{	
				draw=true;
				dir=0;
				if (mappa[player_x][player_y + 1] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x][player_y+1] = 3;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x][player_y + 1] == 2 && mappa[player_x][player_y + 2] == 0) 
				{
					for(unsigned i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y+1 && casse[i]->getX() == player_x)
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
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				draw=true;
				dir=2;
				if (mappa[player_x][player_y - 1] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x][player_y - 1] = 3;
					mappa[player_x][player_y] = 0;
			
				}
				else if (mappa[player_x][player_y - 1] == 2 && mappa[player_x][player_y - 2] == 0)
				{
					for (unsigned i = 0; i<casse.size(); i++)
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
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				draw=true;
				dir=3;
				if (mappa[player_x + 1][player_y] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x + 1][player_y] = 3;
					mappa[player_x][player_y] = 0;
				
				}
				else if (mappa[player_x + 1][player_y] == 2 && mappa[player_x + 2][player_y] == 0)
				{
					for (unsigned i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x+1)
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
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				draw=true;
				dir=1;
				if (mappa[player_x - 1][player_y] == 0)
				{
					player.MovePlayer(dir);
					mappa[player_x - 1][player_y] = 3;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x - 1][player_y] == 2 && mappa[player_x - 2][player_y] == 0 )
				{
					for (unsigned i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x-1)
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

			//redraw della mappa
			if(draw && al_is_event_queue_empty(event_queue))
			{
				draw=false;

				drawMap(dir);
				//Inserimento ultima mossa fatta
				mosse.push(new Mossa(player, mappa));
			}
		}

		//Undo e Rigioca livello
		int a=0, b=0;
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			a=events.mouse.x;
			b=events.mouse.y;
			
			/*if(a>=rigioca_x && a<=rigioca_x+64 && b>=rigioca_y && b<=rigioca_y+64)
			{
				cout<<"prima: "<<mosse.size()<<endl;
				clear(mosse,mosse.size());
				mappa=mossaIniziale->getMappa();
				player=mossaIniziale->getPlayer();
				drawMap(0);
	
				for(int i=0; i<12; i++)
				{	for(int j=0; j<10; j++)
						cout<<mappa[i][j]<<" ";
					cout<<endl;}				
			}*/
		
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
			clear(mosse, mosse.size());
			mosse.pop();
			al_destroy_bitmap(Undo);
			//al_destroy_bitmap(Rigioca);
			al_destroy_bitmap(sfondo);
			al_destroy_bitmap(Box);
			al_destroy_bitmap(BoxColor);
			al_destroy_bitmap(Wall);
			al_destroy_bitmap(Player);
			al_destroy_timer(timer);
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			
			return true;
		}
	}

}

bool Livello::Done(vector<Cassa*> casse) const
{
	for (unsigned i = 0; i < casse.size(); i++) {
		int x = casse[i]->getEndX();
		int y = casse[i]->getEndY();
		if (mappa[x][y] != 2)
			return false;
	}
	return true;
}

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
	//Rigioca = al_load_bitmap("Ripeti.png");
	Box= al_load_bitmap("box.png");
	BoxColor = al_load_bitmap("boxColor.png");
	Player = al_load_bitmap("George.png");
	sfondo = al_load_bitmap("Background.jpg");	
}
