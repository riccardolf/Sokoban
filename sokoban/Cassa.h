#ifndef CASSA_H
#define CASSA_H
#include<iostream>
using namespace std;
class Cassa
{
public:
	Cassa(int xI, int yI, int xF, int yF);
	Cassa(const Cassa& c);
	Cassa& operator=(const Cassa& c);
	~Cassa() { }
	void sposta(int dir);
	int getX() const { return cassa_x; }
	int getY() const { return cassa_y; }
	int getEndX() const { return x_finale; }
	int getEndY() const { return y_finale; }

private:
	int x_finale;
	int y_finale;
	int cassa_x;
	int cassa_y;
	int movespeed;
};

#endif