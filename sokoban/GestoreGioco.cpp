#include"GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
	numLivelli=5;
	this->creaLivelli();
}

void GestoreGioco::creaLivelli()
{
	// LIVELLO 1


	Giocatore player(3,5); 		//  uso il costruttore di player;
	int numCasse=5;
	int numMuri=4;
	
	int casse_x_iniziali[numCasse]={1,2,3,4,5};
	int casse_y_iniziali[numCasse]={1,2,3,4,5};
	int casse_x_finali[numCasse]={6,7,8,9,0};
	int casse_y_finali[numCasse]={6,7,8,9,0};

	int muro_x[numMuri]={1,2,3,4};
	int muro_y[numMuri]={5,6,7,8};
	
	for(int i=0; i<numCasse; i++)
	{
		Cassa c(casse_x_iniziali[i], casse_y_iniziali[i], casse_x_finali[i],casse_y_finali[i]);
		casse.push_back(c);
	}

	for(int i=0; i<numMuri; i++)
	{
		Muro m(muro_x[i],muro_y[i]);
		muri.push_back(m);
	}	
	
	Livello l1(player,casse,muri);
	livelli.push_back(l1);


	// LIVELLO 2


	Giocatore player1(3,5); 		//  uso il costruttore di player;
	int numCasse=5;
	int numMuri=4;
	
	int casse_x_iniziali[numCasse]={1,2,3,4,5};
	int casse_y_iniziali[numCasse]={1,2,3,4,5};
	int casse_x_finali[numCasse]={6,7,8,9,0};
	int casse_y_finali[numCasse]={6,7,8,9,0};

	int muro_x[numMuri]={1,2,3,4};
	int muro_y[numMuri]={5,6,7,8};
	
	for(int i=0; i<numCasse; i++)
	{
		Cassa c(casse_x_iniziali[i], casse_y_iniziali[i], casse_x_finali[i],casse_y_finali[i]);
		casse.push_back(c);
	}

	for(int i=0; i<numMuri; i++)
	{
		Muro m(muro_x[i],muro_y[i]);
		muri.push_back(m);
	}	
	
	Livello l2(player,casse,muri);
	livelli.push_back(l2);	
}

void GestoreGioco::Modalita()
{

	srand(time(0);
	int liv=0;

	cout<<"Scegli modalita"<<endl; 		// poi va cambiato con i bitmap
	if(arcade)
	{	
		while(numLivelli>0)
		{
			liv=srand()%numLivelli;
			livelli[liv].gioca();
			livelli.erase(livelli.begin()+liv);
			numLivelli--;
		}			

	}
	if(scegliLiv)
	{
		cin>>liv;
		livelli[liv-1].gioca();
	}
}

