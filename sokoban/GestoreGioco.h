#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"muro.h"
#include"giocatore.h"
#include"cassa.h"
#include<vector>
#include<cstdlib>
#include<ctime>

class GestoreGioco
{
	public:
		void Modalita();
		void Livello1();
		void Livello2();
		void Livello3();

	protected:
		int numLivelli;
		Giocatore player;
		int numCasse;
		int numMuri;
		vector<Cassa> casse;
		vector<Muro> muri;
		void inizializzaAllegro();
		ALLEGRO_DISPLAY* display;
		ALLEGRO_TIMER* timer;
		ALLEGRO_EVENT_QUEUE* event_queue;

};


#endif
