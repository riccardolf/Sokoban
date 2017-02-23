#ifndef MOSSA_H
#define MOSSA_H
#include"Cassa.h"
#include"Giocatore.h"

class Mossa
{
	public:
		Mossa(const Giocatore& g, vector<Cassa*> c, int** m)	
		{	
			player=g;
			for(unsigned i=0; i<c.size(); i++)
				casse.push_back(c[i]);
			mappa=new int*[12];
			for(int i=0; i<12; i++)
				mappa[i]=new int[10];

			for(int i=0; i<12; i++)
				for(int j=0; j<10; j++)
					mappa[i][j]=m[i][j];
			cout << "dir: " << g.getDir() << endl;
		}
	//	~Mossa()   { delete player;	delete casse; }
		Giocatore getPlayer() const	{return player;}
		vector<Cassa*> getCasse() const	{return casse;}
		int** getMappa() const {return mappa;}

	private:
		int** mappa;
		Giocatore player;
		vector<Cassa*> casse;
		
};
#endif
