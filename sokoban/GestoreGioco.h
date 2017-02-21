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
#include<vector>
using namespace std;

class GestoreGioco
{
public:
	GestoreGioco();
	~GestoreGioco();
	void Modalita();
	void creaLivello(int liv);

private:
	void inizializzaAllegro();
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