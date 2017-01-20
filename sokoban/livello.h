#ifndef LIVELLO_H
#define LIVELLO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<vector>
#include"muro.h"
#include"cassa.h"
#include"giocatore.h"
class Livello
{
	public:
		Livello(const Giocatore& g, const Cassa& c, const Muro& m);
		void gioca();
		void destroy(),

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
