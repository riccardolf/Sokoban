#IFNDEF GESTOREGIOCO_H
#DEFINE GESTOREGIOCO_H
#include<allegro5/allegro.h>
#include"muro.h"
#include"giocatore.h"
#include"cassa.h"

class GestoreGioco
{
	public:
		GestoreGioco(int nC, int nM);
		void gioca();
		void creaPartita();
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
}

#ENDIF
