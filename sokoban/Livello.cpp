#include"Livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa*> c, vector<Muro*> m)
{
	this->inizializzaAllegro();
	muri=m;
	fine=new int*[12];
	mappa=new int*[12];
	for(int i=0; i<12; i++)
	{
		mappa[i]=new int [10];
		fine[i]=new int[10];
	}
	
	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
		{
			mappa[i][j] = 0;
			fine[i][j] = 0;
		}

	// 0=niente	 1=muri	 2=casse  4=giocatore
	int x=g.getX();
	int y=g.getY();
	mappa[x][y]=4;
	
	for(int i=0; i<c.size(); i++)
	{	
		x=c[i]->getX();
		y=c[i]->getY();		
		mappa[x][y]=2;
		
		x = c[i]->getEndX();
		y = c[i]->getEndY();
		fine[x][y] = 2;
	}
	
	for(int i=0; i<m.size(); i++)
	{
		x=m[i]->getX();
		y=m[i]->getY();
		mappa[x][y]=1;
	}

	for(int i=0; i<10; i++)
	{	for(int j=0; j<10; j++)
			cout<<mappa[j][i]<<" ";
	cout<<endl;}	

mosse.push(new Mossa(g, c, mappa));		// mossa 0		come inizia il livello
}
	
bool clear(stack<Mossa*> mosse)
{
	if(mosse.size()<2)
		return false;
	
	while(mosse.size()>1)
	{
		mosse.pop();
	}

	return true;

}
const int undo_x=600, undo_y=64, rigioca_x=0, rigioca_y=0;
void Livello::drawMap() const
{
	ALLEGRO_BITMAP* undo = al_load_bitmap("Indietro.png");
	//ALLEGRO_BITMAP* rigioca = al_load_bitmap("rigioca");

	for(int i=0; i<muri.size(); i++)
		al_draw_bitmap(muro, muri[i]->getX()*64, muri[i]->getY()*64, 0);

	vector<Cassa*> casse=mosse.top()->getCasse();	

	for(int i=0; i<casse.size(); i++)
		al_draw_filled_circle(casse[i]->getEndX()*64+32,casse[i]->getEndY()*64+32, 7, al_map_rgb(255,0,0));						

	for(int i=0; i<casse.size(); i++)
	{	
		ALLEGRO_BITMAP* cassa=NULL;
		if(casse[i]->verifica())
			cassa=al_load_bitmap("boxColor.png");
		else
			cassa=al_load_bitmap("box.png");
		al_draw_bitmap(cassa, casse[i]->getX()*64, casse[i]->getY()*64, 0);
		al_destroy_bitmap(cassa);
	}

	al_draw_bitmap(undo, undo_x, undo_y, 0);
//	al_draw_bitmap(rigioca, rigioca_x, rigioca_y,0);
	
	al_destroy_bitmap(undo);
//	al_destroy_bitmap(rigioca);	
}
void Livello::gioca()
{
	Giocatore player=mosse.top()->getPlayer();
	int x=player.getX();
	int y=player.getY();

	vector<Cassa*> casse=mosse.top()->getCasse();	
	enum DIR {DOWN = 0, LEFT,UP, RIGHT};  
	ALLEGRO_KEYBOARD_STATE keystate;
	
	bool active = false, draw=false;
	int dir = DOWN, sourceY = 0;

	drawMap();
	al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x*64, y*64, 0);
	
	al_flip_display();		
	al_clear_to_color(al_map_rgb(0,0,0));

	al_start_timer(timer);

	while (true) 
	{	
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
      
		if (events.type == ALLEGRO_EVENT_TIMER)
		{
			active = true;
			int player_x=player.getX();
			int player_y=player.getY();
	
			// 0=niente	 1=muri	 2=casse  4=giocatore
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{	
				draw=true;
				dir = DOWN;
				if (mappa[player_x][player_y + 1] == 0)
				{
					y = player.sposta(dir);
					mappa[player_x][player_y+1] = 4;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x][player_y + 1] == 2 && mappa[player_x][player_y + 2] == 0) 
				{
					for(int i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y+1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
				
					y = player.sposta(dir);
				
					mappa[player_x][player_y + 1] = 4;
					mappa[player_x][player_y] = 0;
					mappa[player_x][player_y + 2] = 2;
					
				}

			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				draw=true;
				dir = UP;
				if (mappa[player_x][player_y - 1] == 0)
				{
					y = player.sposta(dir);
					mappa[player_x][player_y - 1] = 4;
					mappa[player_x][player_y] = 0;
			
				}
				else if (mappa[player_x][player_y - 1] == 2 && mappa[player_x][player_y - 2] == 0)
				{
					for (int i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y - 1 && casse[i]->getX() == player_x)
						{
							casse[i]->sposta(dir);
							break;
						}
					y = player.sposta(dir);
					mappa[player_x][player_y - 1] = 4;
					mappa[player_x][player_y] = 0;
					mappa[player_x][player_y - 2] = 2;
				
				}

			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				draw=true;
				dir = RIGHT;
				if (mappa[player_x + 1][player_y] == 0)
				{
					x = player.sposta(dir);
					mappa[player_x + 1][player_y] = 4;
					mappa[player_x][player_y] = 0;
				
				}
				else if (mappa[player_x + 1][player_y] == 2 && mappa[player_x + 2][player_y] == 0)
				{
					for (int i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x+1)
						{
							casse[i]->sposta(dir);
							break;
						}
					x = player.sposta(dir);
					mappa[player_x + 1][player_y] = 4;
					mappa[player_x][player_y] = 0;
					mappa[player_x + 2][player_y] = 2;
		
				}
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				draw=true;
				dir = LEFT;
				if (mappa[player_x - 1][player_y] == 0)
				{
					x = player.sposta(dir);
					mappa[player_x - 1][player_y] = 4;
					mappa[player_x][player_y] = 0;
				}
				else if (mappa[player_x - 1][player_y] == 2 && mappa[player_x - 2][player_y] == 0 )
				{
					for (int i = 0; i<casse.size(); i++)
						if (casse[i]->getY() == player_y && casse[i]->getX() == player_x-1)
						{
							casse[i]->sposta(dir);
							break;
						}
					x = player.sposta(dir);
					mappa[player_x - 1][player_y] = 4;
					mappa[player_x][player_y] = 0;
					mappa[player_x - 2][player_y] = 2;
					
				}
			}
			else
				active = false;

			if (active)
				sourceY += al_get_bitmap_width(giocatore) / 4;
			if(!active || sourceY >= al_get_bitmap_width(giocatore))
				sourceY = 0;

			if(draw && al_is_event_queue_empty(event_queue))
			{
				draw=false;

				drawMap();
				al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x*64, y*64, 0);

				al_flip_display();		
				al_clear_to_color(al_map_rgb(0,0,0));
				mosse.push(new Mossa(player, casse, mappa));

			}
		}

		int a=0, b=0;
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			a=events.mouse.x;
			b=events.mouse.y;
			
		/*	if(a>=rigioca_x && a<=rigioca_x+64 && b>=rigioca_y && b<=rigioca_y+64)
			{
				clear(mosse);
				casse=mosse.top()->getCasse();			
				player=mosse.top()->getPlayer();
				x=player.getX();
				y=player.getY();	
			}
		*/
			if(a>=undo_x && a<=undo_x+64 && b>=undo_y && b<=undo_y+64 && mosse.size()>1)
			{
				mosse.pop();
				casse.clear();				
				casse=mosse.top()->getCasse();
				player=mosse.top()->getPlayer();
				x=player.getX();
				y=player.getY();
				mappa=mosse.top()->getMappa();
					
				drawMap();
				al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x*64, y*64, 0);
	
				al_flip_display();		
				al_clear_to_color(al_map_rgb(0,0,0));

			}
		}

		if(Superato())
		{
			clear(mosse);
			mosse.pop();
		//	delete muri;
			al_destroy_bitmap(muro);
			al_destroy_timer(timer);
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			al_destroy_bitmap(giocatore);
			break;
		}
	}

}
bool Livello::Superato() const
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 10; j++)
		{
			if (mappa[i][j] == 2 && fine[i][j] == 2)
				continue;
			else if (mappa[i][j] == 2 && fine[i][j] != 2)
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

	const float FPS=10;
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

	giocatore = al_load_bitmap("bgeorge.png");
	muro=al_load_bitmap("wall.png");
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());		
}


