#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <vector>

#include "Livello.h"

using namespace std;

class GestoreGioco
{
	public:
		GestoreGioco();
		GestoreGioco(const GestoreGioco& g);
		GestoreGioco& operator=(const GestoreGioco& g);
		~GestoreGioco();
		int creaLivello(int liv, int indice, bool mod, ALLEGRO_DISPLAY* d);
		void setAudio();
		static bool Audio;

	private:
		int numLivelli;
		ALLEGRO_SAMPLE* song;
		ALLEGRO_SAMPLE_INSTANCE* songInstance;
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
