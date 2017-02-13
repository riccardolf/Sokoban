#ifndef MURO_H
#define MURO_H
#include<iostream>
using namespace std;

class Muro
{
	public:
		Muro(int x, int y);		
		Muro& operator=(const Muro& m);
		int getX() const {return muro_x;}
		int getY() const {return muro_y;}		

	private:
		int muro_x;
		int muro_y;
};

#endif
