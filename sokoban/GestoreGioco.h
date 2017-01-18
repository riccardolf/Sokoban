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

class GestoreGioco
{
	public:
		GestoreGioco(int nC, int nM);
		void gioca();

	private:
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
