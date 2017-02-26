#ifndef GIOCATORE_H
#define GIOCATORE_H
#include<iostream>
using namespace std;

class Giocatore
{
	public:
		Giocatore(int x=0, int y=0);
		Giocatore(const Giocatore& g);
		Giocatore& operator=(const Giocatore &g);
		void MovePlayer(int dir);
		int getX() const {return player_x;}
		int getY() const {return player_y;}

	private:
		int x_iniziale;
		int y_iniziale;
		int player_x;
		int player_y;	
};

#endif
