#IFNDEF CASSA_H
#DEFINE CASSA_H
#include<allegro5/allegro.h>

class Cassa
{
	public:
		Cassa(int x, int y);
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
		int cassa_x;
		int cassa_y;
		ALLEGRO_BITMAP* cassa;

}

#ENDIF
