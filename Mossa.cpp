#include "Mossa.h"
Mossa::Mossa(const Giocatore& g, int** m)	
{	
	player=g;
	mappa=new int*[12];
	for(int i=0; i<12; i++)
		mappa[i]=new int[10];

	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j]=m[i][j];
}

Mossa::Mossa(const Mossa& m)
{
	player=m.player;
	mappa=new int*[12];
	for(int i=0; i<12; i++)
		mappa[i]=new int[10];

	for(int i=0; i<12; i++)
		for(int j=0; j<10; j++)
			mappa[i][j]=m.mappa[i][j];
}

Mossa& Mossa::operator=(const Mossa& m)
{
	if(this!=&m)
	{
		player=m.player;

		for(int i=0; i<12; i++)
			delete[] mappa[i];
		delete[]mappa;
		
		mappa=new int*[12];
		for(int i=0; i<12; i++)
			mappa[i]=new int[10];

		for(int i=0; i<12; i++)
			for(int j=0; j<10; j++)
				mappa[i][j]=m.mappa[i][j];
	}
	return *this;
}

Mossa::~Mossa()   
{	
	for(int i=0; i<12; i++)
		delete[] mappa[i];
	delete[]mappa;
}

