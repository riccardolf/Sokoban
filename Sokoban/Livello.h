#ifndef LIVELLO_H
#define LIVELLO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<vector>
#include<stack>
#include"Mossa.h"

#include <iostream>
using namespace std;

class Livello
{
	public:
		Livello(const Coordinate& g, vector<Cassa*> c, vector<Coordinate*> m, ALLEGRO_BITMAP* PG, ALLEGRO_BITMAP* B, ALLEGRO_BITMAP* C);
		Livello(const Livello& l);
		Livello& operator=(const Livello& l);
		~Livello();
		bool gioca();
		void drawMap(int dir) const;
		bool Done(vector<Cassa*> casse) const;
		bool clear(stack<Mossa*>& mosse, unsigned dim);
		void destroy();

	private:	
		int** mappa;
		stack<Mossa*> mosse;
		vector<Coordinate*> muri;
		vector<Cassa*> casse;
		void inizializzaAllegro();
		ALLEGRO_DISPLAY* display;
		ALLEGRO_TIMER* timer;
		ALLEGRO_EVENT_QUEUE* event_queue;
		ALLEGRO_FONT* font;
		ALLEGRO_BITMAP* Undo;
		ALLEGRO_BITMAP* Box;
		ALLEGRO_BITMAP* BoxColor;
		ALLEGRO_BITMAP* Player;
		ALLEGRO_BITMAP* Wall;
		ALLEGRO_BITMAP* sfondo;
		ALLEGRO_BITMAP* Superato;

};
#endif
