#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"GestoreGioco.h"

int main(int argc, char **argv)
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

	GestoreGioco sokoban;

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

	int arcade_x = 170, arcade_y = 360, levels_x = 430, levels_y = 360, x = 0, y = 0,  audio_x=692, audio_y=595, dim=64;;
	bool audio=true;	

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(Sfondo,0,0,0);	
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//Scelta Modalita
	while (x<arcade_x || x>levels_x+183 || x>arcade_x+183 && x<levels_x || y>arcade_y+85 || y<arcade_y)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			x = ev.mouse.x;
			y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			al_destroy_bitmap(Sfondo);
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			return 0;
		}

		if(x >= audio_x && x <= audio_x+dim && y >= audio_y && y <= audio_y+dim)
			sokoban.setAudio();

	}	

	// scelta personaggio
	int PGx[] = { 40,295,580 };
	int PGy = 310, x1 = 0, y1 = 0, indicePG = 0;
	ALLEGRO_BITMAP* Select = al_load_bitmap("Select.jpg");
	al_draw_bitmap(Select, 0, 0, 0);
	al_flip_display();
	al_clear_to_color(al_map_rgb(0, 0, 0));

	while (x1 < PGx[0] || x1 > PGx[2] + 100 || (x1 > PGx[0] + 100 && x1<PGx[1]) || (x1 > PGx[1] + 100 && x1<PGx[2]) || y1 < PGy || y1 > PGy + 120)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			x1 = ev.mouse.x;
			y1 = ev.mouse.y;
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			al_destroy_bitmap(Select);
			al_destroy_bitmap(Sfondo);
			al_destroy_event_queue(event_queue);
			return 0;
		}
	}
	
	for (unsigned i = 0; i < 3; i++)
		if (x1 >= PGx[i] && x1 <= PGx[i] + 100 && y1 >= PGy && y1 <= PGy + 120)
			indicePG = i;
	
	al_destroy_bitmap(Select);

	// modalita arcade
	if (x >= arcade_x && x <= arcade_x + 183 && y >= arcade_y && y <= arcade_y + 85)
	{
		al_destroy_bitmap(Sfondo);
		al_destroy_event_queue(event_queue);
		al_destroy_display(display);	

		//Creazione Livelli
		for(int i=0; i<9; i++)
			if(sokoban.creaLivello(i,indicePG, false) == -1)
				return 0;

		int risp= al_show_native_message_box(al_get_current_display(), "COMPLIMENTI", "Hai completato il gioco!", "Solo per te un livello bouns difficilissimo. Vuoi giocare? ",0,ALLEGRO_MESSAGEBOX_YES_NO);
		if(risp==1)
		{
			sokoban.creaLivello(9, indicePG, false);
			al_show_native_message_box(al_get_current_display(), "COMPLIMENTI DI NUOVO", " Passiamo al vero livello", "", 0, ALLEGRO_MESSAGEBOX_WARN);
			sokoban.creaLivello(10, indicePG, false);
		}
	}

	// modalita seleziona livello
	else 
	{
		int liv_x[] = {11,291,572};
		int liv_y[] = {10,232,453};
		int x2=0, y2=0, liv=0;

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
				al_destroy_bitmap(Sfondo);
				al_destroy_event_queue(event_queue);
				return 0;
			}
		}

		al_destroy_bitmap(Sfondo);
		al_destroy_event_queue(event_queue);
		al_destroy_bitmap(Levels);
		al_destroy_display(display);
		
		for(int j = 0; j < 3; j++)
			for(int i = 0; i < 3; i++)
				if (x2 >= liv_x[i] && x2 <= liv_x[i] + 215 && y2 >= liv_y[j] && y2 <= liv_y[j] + 215)
					liv = 3*j+i;

		while(liv >= 0 && liv <= 8)
		{
			liv = sokoban.creaLivello(liv,indicePG,true);
		}
	}
	
	return 0;
}
