#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include"Livello.h"
#include<vector>
using namespace std;

class GestoreGioco
{
	public:
		GestoreGioco();
		~GestoreGioco();
		bool creaLivello(int liv);

	private:
		int numLivelli;
		vector<Cassa*> casse;
		vector<Muro*> muri;
		int** posCasseXi;
		int** posCasseXf;
		int** posCasseYi;
		int** posCasseYf;
		int** posMuriX;
		int** posMuriY;
		int* posGiocatoreX;
		int* posGiocatoreY;
		int* numCasse;
		int* numMuri;
};


#endif
