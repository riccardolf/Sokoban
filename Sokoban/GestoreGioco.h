#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include"Livello.h"
#include <allegro5/allegro.h>

class GestoreGioco
{
	public:
		GestoreGioco();
		GestoreGioco(const GestoreGioco& g);
		GestoreGioco& operator=(const GestoreGioco& g);
		~GestoreGioco();
		int creaLivello(int liv, int indice, bool mod);
		void setAudio(bool a)	{audio = a;}

	private:
		bool audio;
		int numLivelli;
		vector<ALLEGRO_BITMAP*> PG;
		vector<ALLEGRO_BITMAP*> boxes;
		vector<ALLEGRO_BITMAP*> Cbox;
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
