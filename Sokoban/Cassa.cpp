#include"Cassa.h"

Cassa::Cassa(const Cassa& c)
{
	x_finale=c.x_finale;
	y_finale=c.y_finale;
	x=c.x;
	y=c.y;
}

Cassa& Cassa::operator=(const Cassa& c)
{
	if(this!=&c)
	{
		x_finale=c.x_finale;
		y_finale=c.y_finale;
		x=c.x;
		y=c.y;
	}
	
	return *this;
}

