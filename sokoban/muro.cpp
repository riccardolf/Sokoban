#include"muro.h"

Muro::Muro(int x, int y)
{
	this->inizializzaAllegro();
	muro_x=x;
	muro_y=y;
	muro=al_load_bitmap("muro.png");
}

void Muro::disegnaMuro()
{
	al_draw_bitmap(muro, muro_x, muro_y, 0);
}

void Muro::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}
}
