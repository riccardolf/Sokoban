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
		void creaLivelli();

	protected:
		int numLivelli;
		vector<Livello> livelli;
		vector<Cassa> casse;
		vector<Muro> muri;

};


#endif
