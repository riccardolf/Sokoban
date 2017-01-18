#include"giocatore.h"

Giocatore::Giocatore(int x, int y)
{
	x_iniziale=x;
	y_iniziale=y;
	player_x=x_iniziale;
	player_y=y_iniziale;
	player=al_load_bitmap("player.png");
}

void Giocatore::spostaSU()
{
	player_y+=1.0;
}

void Giocatore::spostaGIU()
{
		player_y-=1.0;
}

void Giocatore::spostaDX()
{
		player_x+=1.0;
}

void Giocatore::spostaSX()
{
	player_x-=1.0;
}

void Giocatore::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

	ALLEGRO_TIMER* timer=al_create_timer(1/60);
	if(!timer)
	{
		cerr<<"no timer"<<endl;
	}

	ALLEGRO_EVENT_QUEUE* event_queue=al_create_event_queue();
	if(!event_queue)
	{
		cerr<<"no event_queue"<<endl;
	}
}
