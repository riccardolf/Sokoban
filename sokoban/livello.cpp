#include"livello.h"

Livello::Livello(const Giocatore& g, vector<Cassa> c, vector<Muro> m)
{
	this->inizializzaAllegro();
	player=g;
	for(int i=0; i<c.size(); i++)
		casse[i]=c[i];

	for(int i=0; i<m.size(); i++)	
		muri[i]=m[i];
}
	
void Livello::destroy()
{
	player.destroy();
	for(int i=0; i<c.size(); i++)
		casse[i].destroy();

	for(int i=0; i<m.size(); i++)
		muri[i].destroy();
	
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display();
}

void Livello::gioca()
{
// DISEGNA I MURI
	for(int i=0; i<muri.size(); i++)
		al_draw_bitmap(muri[i].getMuro(), muri[i].getX(), muri[i].getY(), 0);

// disegna le casse in posizione iniziale
	for(int i=0; i<casse.size(); i++)
		al_draw_bitmap(casse[i].getCassa(), casse[i].getX(), casse[i].getY(), 0);
	
	al_flip_display();
	
	enum Direction {DOWN = 0, LEFT,UP, RIGHT};  
	ALLEGRO_KEYBOARD_STATE keystate;
	
	ALLEGRO_BITMAP* giocatore = player.getPlayer();
	bool done = false, draw = true, active = false;
	int dir = DOWN, sourceX = 0, sourceY = 0;

	al_set_target_bitmap(giocatore);
	al_set_target_bitmap(al_get_backbuffer(display));

	int x=player.getX();
	int y=player.getY();
	
	al_draw_bitmap(giocatore,x,y,0);
	al_flip_display();
	
	al_start_timer(timer);

	while (!done) 
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;
      
		else if (events.type == ALLEGRO_EVENT_TIMER)
		{
			active = true;
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{
				y=player.spostaGIU();
				dir = DOWN;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				y=player.spostaSU();
				dir = UP;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				x=player.spostaDX();
				dir = RIGHT;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				x=player.spostaSX();
				dir = LEFT;
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
				al_draw_bitmap_region(giocatore, dir * al_get_bitmap_width(giocatore)/4, sourceY, al_get_bitmap_width(giocatore)/4, 										al_get_bitmap_height(giocatore) /4 , x, y, 0);
				
				for(int i=0; i<muri.size(); i++)
					al_draw_bitmap(muri[i].getMuro(), muri[i].getX(), muri[i].getY(), 0);

				for(int i=0; i<casse.size(); i++)
					al_draw_bitmap(casse[i].getCassa(), casse[i].getX(), casse[i].getY(), 0);

				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}
		// condizione di vittoria // da modificare
		for(int i=0; i<casse.size(); i++)
			if(!casse[i].verifica())
				done=false;
			

	}

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

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());	
	


