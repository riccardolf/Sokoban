#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"livello.h"
#include<cstdlib>
#include<ctime>

class GestoreGioco
{
	public:
		GestoreGioco();
		void Modalita();
		void creaLivello(int liv);
		void rimuovi (vector<int> livelli, int pos, int& dim);

	private:
		int numLivelli;
		vector<Cassa> casse;
		vector<Muro> muri;
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
