#ifndef MURO_H
#define MURO_H
#include<iostream>
using namespace std;

class Muro
{
	public:
		Muro(int x, int y);		
		Muro(const Muro& m);
		Muro& operator=(const Muro& m);
		~Muro() { }
		int getX() const {return muro_x;}
		int getY() const {return muro_y;}		

	private:
		int muro_x;
		int muro_y;
};

#endif
