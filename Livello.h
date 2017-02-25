#ifndef LIVELLO_H
#define LIVELLO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<vector>
#include<stack>
#include"Mossa.h"
#include"Muro.h" 
#include"Cassa.h"

class Livello
{
	public:
		Livello(const Giocatore& g, vector<Cassa*> c, vector<Muro*> m);
		~Livello();
		bool gioca();
		void drawMap(int dir) const;
		bool Done(vector<Cassa*> casse) const;
		bool clear(stack<Mossa*>& mosse, unsigned dim);
	private:	
		int** mappa;
		stack<Mossa*> mosse;
		vector<Muro*> muri;
		vector<Cassa*> casse;
		void inizializzaAllegro();
		ALLEGRO_DISPLAY* display;
		ALLEGRO_TIMER* timer;
		ALLEGRO_EVENT_QUEUE* event_queue;
		ALLEGRO_BITMAP* Undo;
	//	ALLEGRO_BITMAP* Rigioca;
		ALLEGRO_BITMAP* Box;
		ALLEGRO_BITMAP* BoxColor;
		ALLEGRO_BITMAP* Player;
		ALLEGRO_BITMAP* Wall;
		ALLEGRO_BITMAP* sfondo;


};
#endif
