#include"cassa.h"

Cassa::Cassa(int xI, int yI, int xF, int yF)
{
	x_iniziale=xI;
	y_iniziale=yI;
	cassa_x=x_iniziale;
	cassa_y=y_iniziale;
	x_finale=xF;
	y_finale=yF;
}

Cassa& Cassa::operator=(const Cassa& c)
{
	if(this!=&c)
	{
		x_iniziale=c.x_iniziale;
		y_iniziale=c.y_iniziale;
		x_finale=c.x_finale;
		y_finale=c.y_finale;
		cassa_x=c.cassa_x;
		cassa_y=c.cassa_y;
	}
	
	return *this;
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

bool Cassa::verifica()
{
	if(cassa_x == x_finale && cassa_y == y_finale)
		return true;
	
	return false;
}
