#ifndef CASSA_H
#define CASSA_H
#include "Coordinate.h"

class Cassa: public Coordinate
{
	public:
		Cassa(int xI, int yI, int xF, int yF): 	Coordinate(xI,yI),	x_finale(xF), y_finale(yF)	{}
		Cassa(const Cassa& c);
		Cassa& operator=(const Cassa& c);
		int getEndX() const {return x_finale;}
		int getEndY() const	{return y_finale;}		

	private:
		int x_finale;
		int y_finale;
};

#endif
