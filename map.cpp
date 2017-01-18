#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const int FPS = 60;
bool keys[] = { false, false, false, false };
enum KEYS { UP, DOWN, LEFT, RIGHT };

int main(void)
{
	
	bool done = false;
	bool render = false;

	int xOff = 0;
	int yOff = 0;

	int mapColumns = 9;
	int mapSize = 81;
	int tileSize = 64;

	int map[9][9] = {3,3,0,0,0,0,0,3,3,
					 0,0,0,2,2,2,0,3,3,
					 0,4,2,1,2,2,0,3,3,
					 0,0,0,2,1,4,0,3,3,
					 0,4,0,0,1,2,0,3,3,
					 0,2,0,2,4,2,0,0,3,
					 0,1,2,1,1,1,4,0,3,
					 0,2,2,4,4,2,2,0,3,
					 0,0,0,0,0,0,0,0,3};

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *wall = NULL;
	ALLEGRO_BITMAP *box = NULL;
	ALLEGRO_BITMAP *black = NULL;
	ALLEGRO_BITMAP *stone = NULL;
	ALLEGRO_BITMAP *win = NULL;

	
	if (!al_init())										
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			

	if (!display)										
		return -1;


	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	wall = al_load_bitmap("wall.png");
	box = al_load_bitmap("box.png");
	black = al_load_bitmap("black.png");
	stone = al_load_bitmap("Cobblestone.png");
	win = al_load_bitmap("win.png");
	


	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	while (!done)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			xOff -= keys[RIGHT] * 5;
			xOff += keys[LEFT] * 5;
			yOff -= keys[DOWN] * 5;
			yOff += keys[UP] * 5;

			render = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;

		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			for (int i = 0; i < mapColumns; i++)
				for(int j=0;j< mapColumns;j++)
			{
				if (map[i][j] == 0)
					al_draw_bitmap(wall, xOff + tileSize * (j % mapColumns), yOff + tileSize * (i% mapColumns),0);
				else if (map[i][j] == 1)
					al_draw_bitmap(box,xOff + tileSize * (j% mapColumns), yOff + tileSize * (i% mapColumns),0);
			    else if(map[i][j] == 2)
					al_draw_bitmap(stone, xOff + tileSize * (j % mapColumns), yOff + tileSize * (i% mapColumns), 0);
				else if (map[i][j] == 4)
					al_draw_bitmap(win, xOff + tileSize * (j % mapColumns), yOff + tileSize * (i% mapColumns), 0);
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	al_rest(10.0);
	al_destroy_bitmap(wall);
	al_destroy_bitmap(box);
	al_destroy_bitmap(black);
	al_destroy_bitmap(stone);
	al_destroy_bitmap(win);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);					

	return 0;
}
