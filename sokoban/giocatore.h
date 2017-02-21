#ifndef GIOCATORE_H
#define GIOCATORE_H
#include<iostream>
using namespace std;

class Giocatore
{
	public:
		Giocatore(int x, int y);
		Giocatore(const Giocatore& g);
		Giocatore() {}		
		~Giocatore() {}
		Giocatore& operator=(const Giocatore &g);
		int sposta(int dir);
		int getX() const {return player_x;}
		int getY() const {return player_y;}
		void destroy();

	private:
		int x_iniziale;
		int y_iniziale;
		int player_x;
		int player_y;	
		int movespeed;
		void inizializzaAllegro();
};

#endif
