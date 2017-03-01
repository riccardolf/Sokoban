#ifndef MOSSA_H
#define MOSSA_H
#include"Cassa.h"
#include"Giocatore.h"

class Mossa
{
	public:
		Mossa(const Giocatore& g, int** m);
		~Mossa();
		Mossa(const Mossa& m);
		Mossa& operator=(const Mossa& m);
		Giocatore getPlayer() const	{return player;}
		int** getMappa() const {return mappa;}

	private:
		int** mappa;
		Giocatore player;
		
};
#endif
