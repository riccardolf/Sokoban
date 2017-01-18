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

int Giocatore::spostaSU()
{
	if(player_y>0)
	   return player_y -= movespeed;

}

int Giocatore::spostaGIU()
{
	 if(player_y<600 - al_get_bitmap_width(player) / 4)
		return player_y+= movespeed;
}

int Giocatore::spostaDX()
{
	if(player_x<800 - al_get_bitmap_width(player) / 4) 
 	   return player_x += movespeed;
}

int Giocatore::spostaSX()
{	
	if(player_x>0)
	   return player_x -= movespeed;
}

void Giocatore::inizializzaAllegro()
{
	if(!al_init())
	{
		cerr<<"no allegro"<<endl;
	}

}
