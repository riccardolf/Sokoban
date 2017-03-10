#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
	public:
		Coordinate(int _x=0, int _y=0): x(_x), y(_y) { }		
		Coordinate(const Coordinate& c): x(c.x), y(c.y)	{ }
		~Coordinate() {}
		Coordinate& operator=(const Coordinate& c);
		void sposta(int dir);
		int getX() const {return x;}
		int getY() const {return y;}		

	protected:
		int x;
		int y;


};

#endif
