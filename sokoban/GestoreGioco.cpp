#include"GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
	numLivelli=1;
	numCasse = new int[numLivelli];
	numMuri = new int[numLivelli];
	posCasseXi = new int*[numLivelli];
	posCasseXf = new int*[numLivelli];
	posCasseYi = new int*[numLivelli];
	posCasseYf = new int*[numLivelli];
	posMuriX = new int*[numLivelli];
	posMuriY = new int*[numLivelli];
	posGiocatoreX = new int[numLivelli];
	posGiocatoreY = new int[numLivelli];
	
// livello 1
	numCasse[0]=2;
	numMuri[0]=23;
	posCasseXi[0] = new int [numCasse[0]];
	posCasseXf[0] = new int [numCasse[0]];
	posCasseYi[0] = new int [numCasse[0]];
	posCasseYf[0] = new int [numCasse[0]];
	posCasseXi[0] = {148,212};
	posCasseXf[0] = {228,228};
	posCasseYi[0] = {308,244};
	posCasseYf[0] = {324,324};
	posGiocatoreX[0] = 84;
	posGiocatoreY[0] = 164;
	posMuriX[0] = new int[numMuri[0]];
	posMuriY[0] = new int[numMuri[0]];
	posMuriX[0] = { 20, 20, 20, 20, 20, 20, 84,148,212,276,340,404,404,404,404,404,340,340,276,212,148, 84,148};
	posMuriY[0] = {100,164,228,292,356,420,420,420,420,420,420,420,356,292,228,164,164,100,100,100,100,100,292};

// livello 2

}

void GestoreGioco::creaLivello(int liv)
{

	Giocatore player(posGiocatoreX[liv],posGiocatoreY[liv]); 		//  uso il costruttore di player;

	for(int i=0; i<numCasse[liv]; i++)
		casse.push_back(new Cassa(posCasseXi[i], posCasseYi[i], posCasseXf[i], posCasseYf[i]));

	for(int i=0; i<numMuri[liv]; i++)
		muri.push_back(new Muro(PosMuriX[i],posMuroY[i]));


	Livello l(player, casse, muri);
	l.gioca();

	for(int i=0; i<numMuri[liv]; i++)
		delete muri[i];

	for(int i=0; i<numCasse[liv]; i++)
		delete casse[i];
	

}	

void rimuovi(Vector<int>& livelli, int pos, int& dim)
{
	for(int i=pos; i<dim; i++)
		livelli[i]=livelli[i+1];
	livelli.pop_back();
	dim--;
}

void GestoreGioco::Modalita()
{

	srand(time(0));
	int liv=0;

	//cout<<"Scegli modalita"<<endl; 		// poi va cambiato con i bitmap
	//if(arcade)
	//{	
		int num=numLivelli;
		vector<int> livelli;

		for(int i=0; i<num; i++)
			livelli.push_back(i+1);

		while(num>0)
		{
			liv=rand()%num;
			creaLivello(liv);
			rimuovi(livelli, liv, num);
		}			

	/*}
	if(scegliLiv)
	{
		cin>>liv;
		creaLivello(liv);
	}*/
} 

