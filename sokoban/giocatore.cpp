#include"giocatore.h"

Giocatore::Giocatore(int x, int y)
{
	this->inizializzaAllegro();
	x_iniziale=x;
	y_iniziale=y;
	player_x=x;
	player_y=y;
	movespeed=5;
	player=al_load_bitmap("george.png");
}

Giocatore& Giocatore::operator=(const Giocatore &g)
{
	x_iniziale=g.x_iniziale;
	y_iniziale=g.y_iniziale;
	player_x=g.player_x;
	player_y=g.player_y;
	movespeed=g.movespeed;
	player=g.player;
}

void Giocatore::spostaSU()
{
	if(player_y>0)
	   player_y -= movespeed;

}

void Giocatore::spostaGIU()
{
	 if(player_y<480 - al_get_bitmap_width(player) / 4)
		player_y+= movespeed;
}

void Giocatore::spostaDX()
{
	if(player_x<640 - al_get_bitmap_width(player) / 4) 
 	   player_x += movespeed;
}

void Giocatore::spostaSX()
{	
	if(player_x>0)
	   player_x -= movespeed;
}

void Giocatore::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

}
