#ifndef MOSSA_H
#define MOSSA_H
#include "GestoreGioco.h"

class Mossa
{
	public:
		Mossa(const Giocatore& g, vector<Cassa> c)	{player=g; casse=c;}
		Giocatore getGiocatore() const	{return player;}
		vector<Cassa> getCasse() const	{return casse;}

	private:
		Giocatore player;
		vector<Cassa> casse;
		
};
#endif
