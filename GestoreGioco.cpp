#include"GestoreGioco.h"

GestoreGioco::GestoreGioco()
{
	numLivelli = 9;
	numCasse = new int[numLivelli + 2];
	numMuri = new int[numLivelli + 2];
	posCasseXi = new int*[numLivelli + 2];
	posCasseXf = new int*[numLivelli + 2];
	posCasseYi = new int*[numLivelli + 2];
	posCasseYf = new int*[numLivelli + 2];
	posMuriX = new int*[numLivelli + 2];
	posMuriY = new int*[numLivelli + 2];
	posGiocatoreX = new int[numLivelli + 2];
	posGiocatoreY = new int[numLivelli + 2];
			 	 //  1  2  3  4  5  6  7  8  9 10 11
	int nCasse[] = { 2, 3, 8, 4, 4, 3, 7, 5, 4, 1, 3 };
	int nMuri[] =  {23,39,48,37,28,36,35,26,29,12,35 };
	int PGx[] =    { 2, 2, 5, 8, 6, 4, 4, 5, 4, 4, 2 };
	int PGy[] =    { 3, 8, 8, 3, 5, 7, 3, 3, 7, 5, 7 };

	for (int i = 0; i<numLivelli + 2; i++)
	{
		posGiocatoreX[i] = PGx[i];
		posGiocatoreY[i] = PGy[i];
		numCasse[i] = nCasse[i];
		numMuri[i] = nMuri[i];
		posCasseXi[i] = new int[numCasse[i]];
		posCasseXf[i] = new int[numCasse[i]];
		posCasseYi[i] = new int[numCasse[i]];
		posCasseYf[i] = new int[numCasse[i]];
		posMuriX[i] = new int[numMuri[i]];
		posMuriY[i] = new int[numMuri[i]];
	}

	//livello 1
	int CasseXi[] = { 3,4 };
	int CasseYi[] = { 4,4 };
	int CasseXf[] = { 4,5 };
	int CasseYf[] = { 5,5 };
	int MuriX[] = { 1,1,1,1,1,1,2,3,4,5,6,7,7,7,7,7,6,6,5,4,3,2,3 };
	int MuriY[] = { 2,3,4,5,6,7,7,7,7,7,7,7,6,5,4,3,3,2,2,2,2,2,5 };

	for (int i = 0; i<numCasse[0]; i++)
	{
		posCasseXi[0][i] = CasseXi[i];
		posCasseXf[0][i] = CasseXf[i];
		posCasseYi[0][i] = CasseYi[i];
		posCasseYf[0][i] = CasseYf[i];
	}

	for (int i = 0; i<numMuri[0]; i++)
	{
		posMuriY[0][i] = MuriY[i];
		posMuriX[0][i] = MuriX[i];
	}

	// livello 2
	int CasseXi2[] = { 3,3,4 };
	int CasseYi2[] = { 7,6,7 };
	int CasseXf2[] = { 8,8,8 };
	int CasseYf2[] = { 4,5,6 };

	for (int i = 0; i<numCasse[1]; i++)
	{
		posCasseXi[1][i] = CasseXi2[i];
		posCasseXf[1][i] = CasseXf2[i];
		posCasseYi[1][i] = CasseYi2[i];
		posCasseYf[1][i] = CasseYf2[i];
	}

	int MuriX2[] = { 2,3,4,5,6,6,6,7,8,9,9,9,9,9,9,8,7,7,7,6,5,5,5,5,5,4,3,2,1,1,1,1,1,2,3,3,2,2,2 };
	int MuriY2[] = { 1,1,1,1,1,2,3,2,2,2,3,4,5,6,7,7,7,6,5,5,5,6,7,8,9,9,9,9,9,8,7,6,5,5,5,4,4,3,2 };

	for (int i = 0; i<numMuri[1]; i++)
	{
		posMuriY[1][i] = MuriY2[i];
		posMuriX[1][i] = MuriX2[i];
	}

	//livello 3
	int CasseXi3[] = { 2,9,3,4,5,6,7,8 };
	int CasseYi3[] = { 2,2,7,7,7,7,7,7 };
	int CasseXf3[] = { 2,4,5,6,7,9,1,10};
	int CasseYf3[] = { 1,1,1,1,1,1,4,4 };

	for (int i = 0; i<numCasse[2]; i++)
	{
		posCasseXi[2][i] = CasseXi3[i];
		posCasseXf[2][i] = CasseXf3[i];
		posCasseYi[2][i] = CasseYi3[i];
		posCasseYf[2][i] = CasseYf3[i];
	}

	int MuriX3[] = {1,2,3,4,5,6,7,8,9,10,10,10,10,11,11,11,11,10,10,10,10,9,8,7,6,5,4,3,2,1,1,1,1,0,0,0,0,1,1,1,3,4,7,8,4,5,6,7 };
	int MuriY3[] = {0,0,0,0,0,0,0,0,0, 0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9,9,9,9,9,9,9,9,9,9,8,7,6,6,5,4,3,3,2,1,2,2,2,2,4,5,5,4 };

	for (int i = 0; i<numMuri[2]; i++)
	{
		posMuriY[2][i] = MuriY3[i];
		posMuriX[2][i] = MuriX3[i];
	}


	//livello 4 
	int CasseXi4[] = { 2,3,8,9 };
	int CasseYi4[] = { 5,4,5,4 };
	int CasseXf4[] = { 4,5,6,7 };
	int CasseYf4[] = { 4,4,4,4 };

	for (int i = 0; i<numCasse[3]; i++)
	{
		posCasseXi[3][i] = CasseXi4[i];
		posCasseXf[3][i] = CasseXf4[i];
		posCasseYi[3][i] = CasseYi4[i];
		posCasseYf[3][i] = CasseYf4[i];
	}

	int MuriX4[] = { 1,2,3,4,5,6,6,7,8,9,10,10,11,11,11,11,11,10,9,8,7,7,7,6,5,4,4,4,3,2,1,1,0,0,0,0,1 };
	int MuriY4[] = { 2,2,2,2,2,2,3,2,2,2, 2, 3, 3, 4, 5, 6, 7, 7,7,7,7,6,5,5,5,5,6,7,7,7,7,6,6,5,4,3,3 };

	for (int i = 0; i<numMuri[3]; i++)
	{
		posMuriY[3][i] = MuriY4[i];
		posMuriX[3][i] = MuriX4[i];
	}

	//livello 5
	int CasseXi5[] = { 5,5,6,7 };
	int CasseYi5[] = { 4,5,6,4 };
	int CasseXf5[] = { 3,5,6,8 };
	int CasseYf5[] = { 5,2,7,4 };

	for (int i = 0; i<numCasse[4]; i++)
	{
		posCasseXi[4][i] = CasseXi5[i];
		posCasseXf[4][i] = CasseXf5[i];
		posCasseYi[4][i] = CasseYi5[i];
		posCasseYf[4][i] = CasseYf5[i];
	}

	int MuriX5[] = { 4,5,6,6,6,7,8,9,9,9,8,7,7,7,7,6,5,5,5,4,3,2,2,2,3,4,4,4 };
	int MuriY5[] = { 1,1,1,2,3,3,3,3,4,5,5,5,6,7,8,8,8,7,6,6,6,6,5,4,4,4,3,2 };

	for (int i = 0; i<numMuri[4]; i++)
	{
		posMuriY[4][i] = MuriY5[i];
		posMuriX[4][i] = MuriX5[i];
	}

	//livello 6
	int CasseXi6[] = { 3,4,6 };
	int CasseYi6[] = { 3,5,4 };
	int CasseXf6[] = { 5,6,7 };
	int CasseYf6[] = { 7,7,7 };

	for (int i = 0; i<numCasse[5]; i++)
	{
		posCasseXi[5][i] = CasseXi6[i];
		posCasseXf[5][i] = CasseXf6[i];
		posCasseYi[5][i] = CasseYi6[i];
		posCasseYf[5][i] = CasseYf6[i];
	}

	int MuriX6[] = { 1,2,3,4,5,5,6,7,8,9,9,9,9,9,8,8,8,7,6,5,4,3,2,2,2,2,1,1,1,1,5,5,7,7,6,3 };
	int MuriY6[] = { 1,1,1,1,1,2,2,2,2,2,3,4,5,6,6,7,8,8,8,8,8,8,8,7,6,5,5,4,3,2,3,4,4,6,6,5 };

	for (int i = 0; i<numMuri[5]; i++)
	{
		posMuriY[5][i] = MuriY6[i];
		posMuriX[5][i] = MuriX6[i];
	}

	//livello 7
	int CasseXi7[] = { 3,5,6,7,6,6,5 };
	int CasseYi7[] = { 7,7,7,7,5,4,3 };
	int CasseXf7[] = { 3,3,5,6,8,6,7 };
	int CasseYf7[] = { 3,5,7,8,7,6,4 };

	for (int i = 0; i<numCasse[6]; i++)
	{
		posCasseXi[6][i] = CasseXi7[i];
		posCasseXf[6][i] = CasseXf7[i];
		posCasseYi[6][i] = CasseYi7[i];
		posCasseYf[6][i] = CasseYf7[i];
	}

	int MuriX7[] = { 4,5,6,7,8,8,8,8,8,8,9,9,9,9,8,7,6,5,4,3,2,2,2,2,2,2,2,2,3,4,3,4,4,4,5 };
	int MuriY7[] = { 1,1,1,1,1,2,3,4,5,6,6,7,8,9,9,9,9,9,9,9,9,8,7,6,5,4,3,2,2,2,4,4,5,6,5 };

	for (int i = 0; i<numMuri[6]; i++)
	{
		posMuriY[6][i] = MuriY7[i];
		posMuriX[6][i] = MuriX7[i];
	}

	//livello 8
	int CasseXi8[] = { 6,5,6,5,6 };
	int CasseYi8[] = { 3,4,5,6,7 };
	int CasseXf8[] = { 4,4,5,6,7 };
	int CasseYf8[] = { 6,7,7,7,7 };

	for (int i = 0; i<numCasse[7]; i++)
	{
		posCasseXi[7][i] = CasseXi8[i];
		posCasseXf[7][i] = CasseXf8[i];
		posCasseYi[7][i] = CasseYi8[i];
		posCasseYf[7][i] = CasseYf8[i];
	}

	int MuriX8[] = { 4,5,6,7,7,7,7,8,8,8,8,8,7,6,5,4,3,3,3,3,4,4,3,3,3,4 };
	int MuriY8[] = { 1,1,1,1,2,3,4,4,5,6,7,8,8,8,8,8,8,7,6,5,5,4,4,3,2,2 };

	for (int i = 0; i<numMuri[7]; i++)
	{
		posMuriY[7][i] = MuriY8[i];
		posMuriX[7][i] = MuriX8[i];
	}

	//livello 9
	int CasseXi9[] = { 6,5,6,7 };
	int CasseYi9[] = { 4,5,6,6 };
	int CasseXf9[] = { 5,6,6,7 };
	int CasseYf9[] = { 2,2,3,4 };

	for (int i = 0; i<numCasse[8]; i++)
	{
		posCasseXi[8][i] = CasseXi9[i];
		posCasseXf[8][i] = CasseXf9[i];
		posCasseYi[8][i] = CasseYi9[i];
		posCasseYf[8][i] = CasseYf9[i];
	}

	int MuriX9[] = { 2,3,4,5,6,7,8,9,9,9,9,8,8,8,7,7,7,6,5,4,4,4,3,3,3,2,2,2,5 };
	int MuriY9[] = { 8,8,8,8,8,8,8,8,7,6,5,5,4,3,3,2,1,1,1,1,2,3,3,4,5,5,6,7,6 };

	for (int i = 0; i<numMuri[8]; i++)
	{
		posMuriY[8][i] = MuriY9[i];
		posMuriX[8][i] = MuriX9[i];
	}

	//livello 10
	int CasseXi10[] = { 5 };
	int CasseYi10[] = { 5 };
	int CasseXf10[] = { 6 };
	int CasseYf10[] = { 5 };

	for (int i = 0; i<numCasse[9]; i++)
	{
		posCasseXi[9][i] = CasseXi10[i];
		posCasseXf[9][i] = CasseXf10[i];
		posCasseYi[9][i] = CasseYi10[i];
		posCasseYf[9][i] = CasseYf10[i];
	}

	int MuriX10[] = { 3,4,5,6,7,7,7,6,5,4,3,3 };
	int MuriY10[] = { 4,4,4,4,4,5,6,6,6,6,6,5 };

	for (int i = 0; i<numMuri[9]; i++)
	{
		posMuriY[9][i] = MuriY10[i];
		posMuriX[9][i] = MuriX10[i];
	}

	//livello 11
	int CasseXi11[] = { 4,4,4 };
	int CasseYi11[] = { 4,5,6, };
	int CasseXf11[] = { 5,5,5 };
	int CasseYf11[] = { 4,5,6 };

	for (int i = 0; i<numCasse[10]; i++)
	{
		posCasseXi[10][i] = CasseXi11[i];
		posCasseXf[10][i] = CasseXf11[i];
		posCasseYi[10][i] = CasseYi11[i];
		posCasseYf[10][i] = CasseYf11[i];
	}

	int MuriX11[] = { 3,4,5,6,6,7,8,8,8,9,9,9,9,9,8,7,6,5,4,3,2,1,1,1,1,1,2,3,3,3,6,6,7,5,3 };
	int MuriY11[] = { 1,1,1,1,2,2,2,3,4,4,5,6,7,8,8,8,8,8,8,8,8,8,7,6,5,4,4,4,3,2,4,5,6,7,6 };

	for (int i = 0; i<numMuri[10]; i++)
	{
		posMuriY[10][i] = MuriY11[i];
		posMuriX[10][i] = MuriX11[i];
	}

}
GestoreGioco::~GestoreGioco()
{

	for (int i = 0; i<numLivelli; i++)
	{
		delete[]posMuriX[i];
		delete[]posMuriY[i];
		delete[]posCasseXi[i];
		delete[]posCasseXf[i];
		delete[]posCasseYi[i];
		delete[]posCasseYf[i];
	}

	delete[]posGiocatoreX;
	delete[]posGiocatoreY;
	delete[]posMuriX;
	delete[]posMuriY;
	delete[]posCasseXi;
	delete[]posCasseXf;
	delete[]posCasseYi;
	delete[]posCasseYf;
	delete[]numMuri;
	delete[]numCasse;
}

bool GestoreGioco::creaLivello(int liv)
{
	if(liv>11)
		return false;

	Giocatore player(posGiocatoreX[liv], posGiocatoreY[liv]); 		//  uso il costruttore di player;

	for (int i = 0; i<numCasse[liv]; i++)
		casse.push_back(new Cassa(posCasseXi[liv][i], posCasseYi[liv][i], posCasseXf[liv][i], posCasseYf[liv][i]));

	for (int i = 0; i<numMuri[liv]; i++)
		muri.push_back(new Muro(posMuriX[liv][i], posMuriY[liv][i]));

	Livello L(player, casse, muri);
	if(!L.gioca())
		return false;		

	for(int i=0; i<numMuri[liv]; i++)
		delete muri[i];
	for(int i=0; i<numCasse[liv]; i++)
		delete casse[i];
	
	casse.clear();
	muri.clear();

	return true;
}


