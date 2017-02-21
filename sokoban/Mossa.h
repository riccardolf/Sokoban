#ifndef MOSSA_H
#define MOSSA_H
#include"cassa.h"
#include"giocatore.h"

class Mossa
{
	public:
		Mossa(const Giocatore& g, vector<Cassa*> c)	{player=g; casse=c;}
	//	~Mossa()   { delete player;	delete casse; }
		Giocatore getPlayer() const	{return player;}
		vector<Cassa*> getCasse() const	{return casse;}

	private:
		Giocatore player;
		vector<Cassa*> casse;
		
};
#endif
