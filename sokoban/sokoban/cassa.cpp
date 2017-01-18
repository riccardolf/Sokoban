#include"cassa.h"

Cassa::Cassa(int x, int y)
{
	this->inizializzaAllegro();
	x_iniziale=x;
	y_iniziale=y;
	cassa_x=x_iniziale;
	cassa_y=y_iniziale;
	cassa=al_load_bitmap("box.png");
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
	

}
