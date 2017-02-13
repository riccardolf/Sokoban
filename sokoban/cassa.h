#ifndef CASSA_H
#define CASSA_H
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
		int getEndX() const {return x_finale;}
		int getEndY() const	{return y_finale;}		
		bool verifica();

	private:
		int x_iniziale;
		int y_iniziale;
		int x_finale;
		int y_finale;
		int cassa_x;
		int cassa_y;
};

#endif
