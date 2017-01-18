#include"muro.h"

Muro::Muro(int x, int y)
{
	this->inizializzaAllegro();
	muro_x=x;
	muro_y=y;
	muro=al_load_bitmap("wall.png");
}

void Muro::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}
}
