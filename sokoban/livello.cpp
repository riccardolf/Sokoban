#include"livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa> c, vector<Muro> m)
{
	this->inizializzaAllegro();

	mosse.push(new Mossa(g, c);		// mossa 0		come inizia il livello
	muri=m;
}
	
void Livello::destroy()
{
	player.destroy();
	al_destroy_bitmap(cassa);
	al_destroy_bitmap(muro);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}

void Livello::gioca()
{
// DISEGNA I MURI
	for(int i=0; i<muri.size(); i++)
		al_draw_bitmap(muro, muri[i].getX(), muri[i].getY(), 0);

	vector<Cassa> casse;
	casse=mosse.top().getCasse();

// disegna le casse in posizione iniziale
	for(int i=0; i<casse.size(); i++)
		al_draw_bitmap(cassa, casse[i].getX(), casse[i].getY(), 0);
		
	al_flip_display();
	
	enum Direction {DOWN = 0, LEFT,UP, RIGHT};  
	ALLEGRO_KEYBOARD_STATE keystate;
	
	ALLEGRO_BITMAP* giocatore = al_load_bitmap("george.png");
	bool active = false;
	int dir = DOWN, sourceX = 0, sourceY = 0, movespeed=7;

	al_set_target_bitmap(giocatore);
	al_set_target_bitmap(al_get_backbuffer(display));

	Giocatore player=mosse.top().getPlayer();
	int x=player.getX();
	int y=player.getY();
	
	al_flip_display();
	
	al_start_timer(timer);

	while (true) 
	{	
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
      
		else if (events.type == ALLEGRO_EVENT_TIMER)
		{
			active = true;
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{
				for(int i=0; i<muri.size(); i++)
					if(y+movespeed < muri[i].getY()-64)
					{
						y=player.spostaGIU(movespeed);
						player.setY(y);						
						break;
					}
					
				dir = DOWN;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				for(int i=0; i<muri.size(); i++)
				{
					if(y-movespeed > muri[i].getY()+64)
					{
						y=player.spostaSU(movespeed);
						player.setY(y);
						break;
					}
				}
				dir = UP;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				for(int i=0; i<muri.size(); i++)
					if(x+movespeed < muri[i].getX()-64)
					{
						x=player.spostaDX(movespeed);
						player.setX(x);
						break;
					}
				dir = RIGHT;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				for(int i=0; i<muri.size(); i++)
					if(x-movespeed > muri[i].getX()+64)
					{
						x=player.spostaSX(movespeed);
						player.setX(x);
						break;
					}

				dir = LEFT;
			}
			else
				active = false;

			if (active)
				sourceY += al_get_bitmap_width(giocatore) / 4;
			else if(!active || sourceY >= al_get_bitmap_width(giocatore))
				sourceY = 0;
			
			mosse.push(new Mossa(player, casse));

			for(int i=0; i<muri.size(); i++)
				al_draw_bitmap(muro, muri[i].getX(), muri[i].getY(), 0);

			for(int i=0; i<casse.size(); i++)
			{
				al_draw_bitmap(cassa, casse[i].getX(), casse[i].getY(), 0);
				al_draw_filled_circle(casse[i].getEndX(),casse[i].getEndY(), 7, al_map_rgb(255,0,0));
			}
		
			al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x, y, 0);
		
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
		
	
		if(Superato())
			break;

	}

}
bool Livello::Superato()
{
	for(int i=0; i<casse.size(); i++)
		if(!casse[i].verifica())
			return false;
	
	return true;
}

const float FPS=30;
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

	display=al_create_display(800,600);

	if(!display)
	{
		cerr<<"no display"<<endl;
	}
	al_set_window_title(display,"Sokoban");

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
	
	cassa=al_load_bitmap("box.png");
	muro=al_load_bitmap("wall.png");
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());	
}


