#ifndef PARTITA_H
#define PARTITA_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include"GestoreGioco.h"
class Partita
{
	public:
		Partita(const Giocatore& g, const Cassa& c, const Muro& m);
		void gioca();

	private:
		Giocatore player;
		vector<Cassa> casse;
		vector<Muro> muri;
		void inizializzaAllegro();
		ALLEGRO_DISPLAY* display;
		ALLEGRO_TIMER* timer;
		ALLEGRO_EVENT_QUEUE* event_queue;

};
#endif
