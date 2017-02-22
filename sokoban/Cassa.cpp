#include"Cassa.h"

Cassa::Cassa(int xI, int yI, int xF, int yF)
{
	cassa_x=xI;
	cassa_y=yI;
	x_finale=xF;
	y_finale=yF;
}

Cassa::Cassa(const Cassa& c)
{
	x_finale=c.x_finale;
	y_finale=c.y_finale;
	cassa_x=c.cassa_x;
	cassa_y=c.cassa_y;
}

Cassa& Cassa::operator=(const Cassa& c)
{
	if(this!=&c)
	{
		x_finale=c.x_finale;
		y_finale=c.y_finale;
		cassa_x=c.cassa_x;
		cassa_y=c.cassa_y;
	}
	
	return *this;
}

void Cassa::sposta(int dir)
{
	//DOWN = 0, LEFT=1,UP=2, RIGHT=3

	if (dir == 2)
		cassa_y--;
	else if (dir == 0)
		cassa_y++;
	else if (dir == 1)
		cassa_x--;
	else if (dir == 3)
		cassa_x++;
}

bool Cassa::verifica() const
{
	if(cassa_x==x_finale && cassa_y==y_finale)
		return true;

	return false;
}
