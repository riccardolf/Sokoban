#ifndef LIVELLO_H
#define LIVELLO_H
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<vector>
#include<stack>
#include <iostream>

#include "GestoreGioco.h"
#include"Mossa.h"

using namespace std;

enum Shape {niente = 0, wall, cassa, giocatore, undo, restart, mute, audio, seleziona_liv};

class Livello
{
	public:
		Livello(const Coordinate&, vector<Cassa*> c, vector<Coordinate*> m, ALLEGRO_BITMAP* PG, ALLEGRO_BITMAP* B, ALLEGRO_BITMAP* C, ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE_INSTANCE* sI, bool mod);
		Livello(const Livello& l);
		Livello& operator=(const Livello& l);
		~Livello();
		int gioca();
		int selezionaNuovoLivello();
		void drawMap(int dir);
		void rigioca();
		bool Done() const;
		bool clearMosse();
		void destroy();

	private:	
		int** mappa;
		bool modalita;		// 0 = arcade, 1 = seleziona livelli
		stack<Mossa*> mosse;
		Coordinate player;
		vector<Coordinate*> muri;
		vector<Cassa*> casse;
		void inizializzaAllegro(ALLEGRO_DISPLAY*, ALLEGRO_SAMPLE_INSTANCE*);
		ALLEGRO_DISPLAY* display;
		ALLEGRO_SAMPLE_INSTANCE* songInstance;
		ALLEGRO_TIMER* timer;
		ALLEGRO_EVENT_QUEUE* event_queue;
		ALLEGRO_FONT* font;
		ALLEGRO_BITMAP* Undo;
		ALLEGRO_BITMAP* Muto;
		ALLEGRO_BITMAP* Torna;
		ALLEGRO_BITMAP* Rigioca;
		ALLEGRO_BITMAP* Audio;
		ALLEGRO_BITMAP* Box;
		ALLEGRO_BITMAP* BoxColor;
		ALLEGRO_BITMAP* Player;
		ALLEGRO_BITMAP* Wall;
		ALLEGRO_BITMAP* sfondo;
		ALLEGRO_BITMAP* Superato;
};
#endif
