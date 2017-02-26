#ifndef MOSSA_H
#define MOSSA_H
#include"Cassa.h"
#include"Giocatore.h"

class Mossa
{
	public:
		Mossa(const Giocatore& g, int** m)	
		{	
			player=g;
			mappa=new int*[12];
			for(int i=0; i<12; i++)
				mappa[i]=new int[10];

			for(int i=0; i<12; i++)
				for(int j=0; j<10; j++)
					mappa[i][j]=m[i][j];
		}
		
		~Mossa()   
		{	
			for(int i=0; i<12; i++)
				delete[] mappa[i];
			delete[]mappa;
		}
		Giocatore getPlayer() const	{return player;}
		int** getMappa() const {return mappa;}

	private:
		int** mappa;
		Giocatore player;
		
};
#endif
