#IFNDEF MURO_H
#DEFINE MURO_H
#include<allegro5/allegro.h>

class Muro
{
	public:
		Muro(int x, int y);		
		int getX const {return muro_x;}
		int getY const {return muro_y;}		
		ALLEGRO_BITMAP* getMuro() const		{return muro;}

	private:
		int muro_x;
		int muro_y;
		ALLEGRO_BITMAP* muro;
		void inizializzaAllegro();
}

#ENDIF
