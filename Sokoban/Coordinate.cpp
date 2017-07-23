#include"Coordinate.h"

Coordinate& Coordinate::operator=(const Coordinate& c)
{
	if(this!=&c)
	{
		x_iniziale=c.x_iniziale;
		y_iniziale=c.y_iniziale;		
		x=c.x;
		y=c.y;
	}

	return *this;
}

void Coordinate::restart()
{
	x=x_iniziale;
	y=y_iniziale;
}

//Movimenti
void Coordinate::sposta(int dir)
{
	//DOWN = 0, LEFT=1,UP=2, RIGHT=3
	if(dir==2)
		y--;
	if(dir==0)
		y++;	
	if(dir==1)
		x--;	
	if(dir==3)
		x++;	
}

