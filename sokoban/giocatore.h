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
		Giocatore& operator=(const Giocatore &g);
		int spostaSU(int);
		int spostaGIU(int);
		int spostaDX(int);
		int spostaSX(int);
		int getX() const {return player_x;}
		void setX(int x)	{player_x=x;}
		int getY() const {return player_y;}
		void setY(int y)	{player_y=y;}
		void destroy();

	private:
		int x_iniziale;
		int y_iniziale;
		int player_x;
		int player_y;
		void inizializzaAllegro();
};

#endif
