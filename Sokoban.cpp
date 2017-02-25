#include <iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"GestoreGioco.h"
using namespace std;

int main()
{
	if (!al_init())
	{
		cerr << "no allegro" << endl;
	}

	if (!al_init_image_addon())
	{
		cerr << "failed initialisation image" << endl;
	}

	if (!al_init_primitives_addon())
	{
		cerr << "failed initialisation primitives" << endl;
	}

	if (!al_init_native_dialog_addon())
	{
		cerr << "failed initialisation dialog" << endl;
	}

	if (!al_install_mouse())
	{
		cerr << "no mouse" << endl;
	}
	if(!al_install_audio() || !al_init_acodec_addon()) {
		cerr << "no audio" << endl;
   	}
	ALLEGRO_DISPLAY* display = al_create_display(800, 700);
	if (!display)
	{
		cerr << "no display" << endl;
	}
	al_set_window_title(display,"Sokoban");
	
	const float FPS = 30;
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		cerr << "no timer" << endl;
	}
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	if (!event_queue)
	{
		cerr << "no event_queue" << endl;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_reserve_samples(10);
	
	ALLEGRO_BITMAP* arcade = al_load_bitmap("arcade.png");
	ALLEGRO_BITMAP* scegli = al_load_bitmap("Livelli.png");
	ALLEGRO_BITMAP* sfondo = al_load_bitmap("sfondo.png");
	ALLEGRO_SAMPLE* song = al_load_sample("Song1.ogg");
	if(!song)
		cerr<<"no song"<<endl;
	ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);

	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

	GestoreGioco sokoban;

	int arcade_x = 185, arcade_y = 250, scegli_x = 405, scegli_y = 250, x = 0, y = 0;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(sfondo,0,0,0);	
	al_draw_bitmap(arcade, arcade_x, arcade_y, 0);
	al_draw_bitmap(scegli, scegli_x, scegli_y, 0);
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_play_sample_instance(songInstance);
	while (true)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				x = ev.mouse.x;
				y = ev.mouse.y;
				break;
			}
			else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				break;	
	}
	
	if (x >= arcade_x && x <= arcade_x + 183 && y >= arcade_y && y <= arcade_y + 85)
	{
		al_destroy_display(display);

		for(int i=0; i<11; i++)
			if(!sokoban.creaLivello(i))
				return 0;
	}
	else if(x>=scegli_x && x<=scegli_x+183 && y>=scegli_y && y<=scegli_y+85)	
	{		
		int liv_x[]={178,326,474,178,326,474,178,326,474};
		int liv_y[]={100,100,100,250,250,250,400,400,400};
		vector<ALLEGRO_BITMAP*> liv;
		for(int i=0; i<9; i++)
			liv.push_back(NULL);

		liv[0]=al_load_bitmap("1.png");
		liv[1]=al_load_bitmap("2.png");
		liv[2]=al_load_bitmap("3.png");
		liv[3]=al_load_bitmap("4.png");
		liv[4]=al_load_bitmap("5.png");
		liv[5]=al_load_bitmap("6.png");
		liv[6]=al_load_bitmap("7.png");
		liv[7]=al_load_bitmap("8.png");
		liv[8]=al_load_bitmap("9.png");
		al_clear_to_color(al_map_rgb(0,0,0));
	
		bool s=false;
		while(true)
		{	
			if(s)
			{
				s=false;
				ALLEGRO_DISPLAY* display = al_create_display(800, 700);
				al_set_window_title(display,"Sokoban");
			}
		
			al_draw_bitmap(sfondo,0,0, 0);	
			for(int i=0; i<9; i++)
				al_draw_bitmap(liv[i],liv_x[i],liv_y[i],0);
			al_flip_display();

			int x1=0, y1=0;
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
		
			if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				x1=ev.mouse.x;
				y1=ev.mouse.y;
			}
			for(int i=0; i<9; i++)
				if(x1>=liv_x[i] && x1<=liv_x[i]+128 && y1>=liv_y[i] && y1<=liv_y[i]+128)
				{
					s=true;
					al_destroy_display(display);
					sokoban.creaLivello(i);
					break;
				}	
			if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				break;	
		}	
			for(int i=0; i<9; i++)
				al_destroy_bitmap(liv[i]);
			
	}

	al_stop_sample_instance(songInstance);

	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
	al_destroy_bitmap(arcade);
	al_destroy_bitmap(scegli);
	al_destroy_bitmap(sfondo);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);	
}

