#include"GestoreGioco.h"

GestoreGioco::GestoreGioco(int C, int M)
{
	this->inizializzaAllegro();
	numCasse=C;
	numMuri=M;
}
	

void GestoreGioco::gioca()
{
	Giocatore pl(0,0); 		//  uso il costruttore di player;
	player=pl;

	for(int i=0; i<numCasse; i++)
	{
		Cassa c(2,8); // INSERIRE x e y iniziali delle casse
		casse.push_back(c);
	}
	for(int i=0; i<numMuri; i++)
	{
		Muro m(6,9); 		// inserire x e y iniziali del muro
		muri.push_back(m);
	}
	
//disegna il player	in posizione iniziale
	al_draw_bitmap(player.getPlayer(), player.getX(), player.getY(), 0);

// DISEGNA I MURI
	for(int i=0; i<numMuri; i++)
		al_draw_bitmap(muri[i].getMuro(), muri[i].getX(), muri[i].getY(), 0);

// disegna le casse in posizione iniziale
	for(int i=0; i<numCasse; i++)
		al_draw_bitmap(casse[i].getCassa(), casse[i].getX(), casse[i].getY(), 0);
	
	al_flip_display();
	
	enum Direction {DOWN = 0, LEFT,UP, RIGHT};  
	ALLEGRO_KEYBOARD_STATE keystate;
	
	ALLEGRO_BITMAP* giocatore = player.getPlayer();
	bool done = false, draw = true, active = false;
	int dir = DOWN, sourceX = 0, sourceY = 0;
  
	while (!done) 
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
				player.spostaGIU();
				dir=DOWN;
			}

			else if (al_key_down(&keystate, ALLEGRO_KEY_UP)) 
			{
				player.spostaSU();				
  			    dir=UP;
			}

			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				player.spostaDX();
				dir=RIGHT;
			}
		
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))	  
			{
				player.spostaSX();
				dir=LEFT;
			}

			else
				active = false;

			if (active)
				sourceY += al_get_bitmap_width(giocatore) / 4;
			else
				sourceY = 0;

			if (sourceY >= al_get_bitmap_width(giocatore))
				sourceY = 0;

			draw = true;

			if (draw)
			{
				al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 						al_get_bitmap_height(giocatore) /4 , player.getX(), player.getY(), 0);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}


	}

}

const float FPS=60;
void GestoreGioco::inizializzaAllegro()
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

	display=al_create_display(640,480);

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

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());	
	
}
