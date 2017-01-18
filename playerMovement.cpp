enum Direction {DOWN = 0, LEFT,UP, RIGHT};  
ALLEGRO_KEYBOARD_STATE keystate;
	bool done = false, draw = true, active = false;
	float x = 10, y = 10;
	int movespeed = 5;
	int dir = DOWN, sourceX = 0, sourceY = 0;
  
while (!done) {
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keystate);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;
      
		else if (events.type == ALLEGRO_EVENT_TIMER) {
			active = true;
			if (al_key_down(&keystate, ALLEGRO_KEY_DOWN) && y<480 - al_get_bitmap_width(player) / 4) {
				y += movespeed;
				dir = DOWN;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_UP) && y>0) {
				y -= movespeed;
				dir = UP;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT) && x<640 - al_get_bitmap_width(player) / 4) {
				x += movespeed;
				dir = RIGHT;
			}
			else if (al_key_down(&keystate, ALLEGRO_KEY_LEFT) && x>0) {
				x -= movespeed;
				dir = LEFT;
			}
			else
				active = false;

			if (active)
				sourceY += al_get_bitmap_width(player) / 4;
			else
				sourceY = 0;

			if (sourceY >= al_get_bitmap_width(player))
				sourceY = 0;

			draw = true;

			if (draw) {
				al_draw_bitmap_region(player, dir * al_get_bitmap_width(player)/4, sourceY, al_get_bitmap_width(player)/4, al_get_bitmap_height(player) /4 , x, y, NULL);
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
		}


	}
