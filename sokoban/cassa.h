#ifndef CASSA_H
#define CASSA_H
#include<allegro5/allegro.h>
#include<iostream>
using namespace std;

class Cassa
{
	public:
		Cassa(int xI, int yI, int xF, int yF);
		Cassa& operator=(const Cassa& c);
		void spostaSU();
		void spostaGIU();
		void spostaDX();
		void spostaSX();
		int getX() const {return cassa_x;}
		int getY() const {return cassa_y;}		
		ALLEGRO_BITMAP* getCassa() const	{return cassa;}

	private:
		int x_iniziale;
		int y_iniziale;
		int x_finale;
		int y_finale;
		int cassa_x;
		int cassa_y;
		ALLEGRO_BITMAP* cassa;
		void inizializzaAllegro();

};

#endif
