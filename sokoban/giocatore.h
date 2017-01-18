#IFNDEF GIOCATORE_H
#DEFINE GIOCATORE_H
#include<allegro5/allegro.h>

class Giocatore
{
	public:
		Giocatore(int x, int y);
		~Giocatore()	{ this->al_destroy_bitmap(player);}
		void spostaSU();
		void spostaGIU();
		void spostaDX();
		void spostaSX();
		int getX const {return player_x;}
		int getY const {return player_y;}
		ALLEGRO_BITMAP* getPlayer() const	{return player;}

	private:
		int x_iniziale;
		int y_iniziale;
		int player_x;
		int player_y;
		ALLEGRO_BITMAP* player;
		void inizializzaAllegro();
}
