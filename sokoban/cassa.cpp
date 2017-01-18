#include"cassa.h"

Cassa::Cassa()
{
	this->inizializzaAllegro();
	x_iniziale=x;
	y_iniziale=y;
	cassa_x=x_iniziale;
	cassa_y=y_iniziale;
	cassa=al_load_bitmap("cassa.png");
}
void Cassa::spostaSU()
{
	cassa_y+=1.0;
}

void Cassa::spostaGIU()
{
	cassa_y-=1.0;
}

void Cassa::spostaDX()
{
	cassa_x+=1.0;
}

void Cassa::spostaSX()
{
	cassa_x-=1.0;
}

void Cassa::inizializzaAllegro()
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
