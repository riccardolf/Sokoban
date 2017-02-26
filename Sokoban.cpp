#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"GestoreGioco.h"

int main()
{
	// Inizializzazione oggetti di Allegro
	if (!al_init())
	{
		cerr << "no allegro" << endl;
		return -1;
	}
	if (!al_init_image_addon())
	{
		cerr << "failed initialisation image" << endl;
		return -1;
	}
	if (!al_init_primitives_addon())
	{
		cerr << "failed initialisation primitives" << endl;
		return -1;
	}
	if (!al_init_native_dialog_addon())
	{
		cerr << "failed initialisation dialog" << endl;
		return -1;
	}
	if (!al_install_mouse())
	{
		cerr << "no mouse" << endl;
		return -1;
	}
	if(!al_install_audio() || !al_init_acodec_addon())
	{
		cerr << "no audio" << endl;
		return -1;
   	}

	ALLEGRO_DISPLAY* display = al_create_display(800, 700);
	if (!display)
	{
		cerr << "no display" << endl;
		return -1;
	}
	al_set_window_title(display,"Sokoban");

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	if (!event_queue)
	{
		cerr << "no event_queue" << endl;
		return -1;
	}
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_BITMAP* Sfondo = al_load_bitmap("Background_Init.jpg");
	if (!Sfondo)
	{
		cerr << "No Bitmap" << endl;
		return -1;
	}

	al_reserve_samples(10);
	ALLEGRO_SAMPLE* song = al_load_sample("Song.ogg");
	ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);
	if(!song || !songInstance)
	{	
		cerr<<"no song"<<endl;
		return -1;
	}
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

	GestoreGioco sokoban;

	int play_x = 170, play_y = 360, quit_x = 430, quit_y = 360, x = 0, y = 0;

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(Sfondo,0,0,0);	
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_play_sample_instance(songInstance);

	//Scelta Play o Quit
	while (x<play_x || x>quit_x+183 || x>play_x+183 && x<quit_x || y>play_y+85 || y<play_y)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			x=ev.mouse.x;
			y=ev.mouse.y;
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;

	}			

	int PGx[] = { 40,295,580 };
	int PGy = 310;
	ALLEGRO_BITMAP* Select = al_load_bitmap("Select.jpg");
	al_draw_bitmap(Select, 0, 0, 0);
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//Creazione livelli
	if (x >= play_x && x <= play_x + 183 && y >= play_y && y <= play_y + 85)
	{
		while (x < PGx[0] || x > PGx[2] + 100 || (x > PGx[0] + 100 && x<PGx[1]) || (x > PGx[1] + 100 && x<PGx[2]) || y < PGy || y > PGy + 120)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
			{
				x = ev.mouse.x;
				y = ev.mouse.y;
			}
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				al_destroy_bitmap(Select);
				return 0;
			}
		}
		int indice = 0;
		for (unsigned i = 0; i < 3; i++)
			if (x >= PGx[i] && x <= PGx[i] + 100 && y >= PGy && y <= PGy + 120)
				indice = i;
		al_destroy_bitmap(Select);
		al_destroy_display(display);

		for(int i=0; i<9; i++)
			if(!sokoban.creaLivello(i,indice))
			{
				al_stop_sample_instance(songInstance);
				al_destroy_sample(song);
				al_destroy_sample_instance(songInstance);
				al_destroy_bitmap(Sfondo);
				al_destroy_event_queue(event_queue);	
				return 0;
			}
		int risp= al_show_native_message_box(al_get_current_display(), "COMPLIMENTI", "Hai completato il gioco!", "Solo per te un livello bouns difficilissimo. Vuoi giocare? ",0,ALLEGRO_MESSAGEBOX_YES_NO);
		if(risp==1)
		{
			sokoban.creaLivello(9, indice);
			sokoban.creaLivello(10, indice);
		}

		else if(risp==2)
			al_show_native_message_box(al_get_current_display(), "", "Grazie per aver giocato!", "",0,ALLEGRO_MESSAGEBOX_WARN);

		
	}
	al_stop_sample_instance(songInstance);
	al_destroy_sample(song);
	al_destroy_sample_instance(songInstance);
	al_destroy_bitmap(Sfondo);
	al_destroy_event_queue(event_queue);
	return 0;
}
