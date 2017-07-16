#ifndef MOSSA_H
#define MOSSA_H
#include"Cassa.h"

class Mossa
{
	public:
		Mossa(const Coordinate& g, int** m, int d);
		~Mossa();
		Mossa(const Mossa& m);
		Mossa& operator=(const Mossa& m);
		Coordinate getPlayer() const	{return player;}
		int** getMappa() const {return mappa;}
		int getDir() const	{return dir;}

	private:
		int** mappa;
		Coordinate player;
		int dir;
		
};
#endif
