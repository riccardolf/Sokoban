#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
	public:
		Coordinate(int _x=0, int _y=0): x(_x), y(_y), x_iniziale(_x), y_iniziale(_y) { }		
		Coordinate(const Coordinate& c): x(c.x), y(c.y), x_iniziale(c.x_iniziale), y_iniziale(c.y_iniziale)	{ }
		~Coordinate() {}
		Coordinate& operator=(const Coordinate& c);
		void sposta(int dir);
		void restart();
		int getX() const {return x;}
		int getY() const {return y;}		

	protected:
		int x_iniziale;
		int y_iniziale;
		int x;
		int y;


};

#endif
