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

Muro& Muro::operator=(const Muro& m)
{
	if(this!=&m)
	{
		muro_x=m.muro_x;
		muro_y=m.muro_y;
		muro=m.muro;
	}
		
	return *this;
}
