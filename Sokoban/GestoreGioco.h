#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include"Livello.h"
#include <allegro5/allegro.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include <vector>
using namespace std;
class GestoreGioco
{
	public:
		GestoreGioco();
		GestoreGioco(const GestoreGioco& g);
		GestoreGioco& operator=(const GestoreGioco& g);
		~GestoreGioco();
		int creaLivello(int liv, int indice, bool mod);
		void setAudio();
		bool getAudio() const	{return audio;}

	private:
		bool audio;
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
