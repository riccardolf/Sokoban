#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include"Livello.h"
#include <allegro5\allegro.h>

class GestoreGioco
{
	public:
		GestoreGioco();
		~GestoreGioco();
		bool creaLivello(int liv, int indice);

	private:
		int numLivelli;
		vector<ALLEGRO_BITMAP*> PG;
		vector<ALLEGRO_BITMAP*> boxes;
		vector<ALLEGRO_BITMAP*> Cbox;
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
