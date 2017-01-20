#ifndef GIOCATORE_H
#define GIOCATORE_H
#include<allegro5/allegro.h>
#include<iostream>
using namespace std;

class Giocatore
{
	public:
		Giocatore(int x, int y);
		Giocatore() {}
		Giocatore& operator=(const Giocatore &g);
		int spostaSU();
		int spostaGIU();
		int spostaDX();
		int spostaSX();
		int getX() const {return player_x;}
		int getY() const {return player_y;}
		ALLEGRO_BITMAP* getPlayer() const	{return player;}
		void destroy();

	private:
		int x_iniziale;
		int y_iniziale;
		int movespeed;
		int player_x;
		int player_y;
		ALLEGRO_BITMAP* player;
		void inizializzaAllegro();
};

#endif
