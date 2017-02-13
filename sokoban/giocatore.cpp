#include"giocatore.h"

Giocatore::Giocatore(int x, int y)
{
	x_iniziale=x;
	y_iniziale=y;
	player_x=x;
	player_y=y;
}

Giocatore::Giocatore(const Giocatore& g)
{
	x_iniziale=g.x_iniziale;
	y_iniziale=g.y_iniziale;
	player_x=g.player_x;
	player_y=g.player_y;
	player=g.player;

}

Giocatore& Giocatore::operator=(const Giocatore &g)
{
	if(this!=&g)
	{
		x_iniziale=g.x_iniziale;
		y_iniziale=g.y_iniziale;
		player_x=g.player_x;
		player_y=g.player_y;
		player=g.player;
	}
	
	return *this;
}

int Giocatore::spostaSU(int movespeed)
{
	if(player_y>0)
	  player_y -= movespeed;

	return player_y;
}

int Giocatore::spostaGIU(int movespeed)
{
	 if(player_y< 600)//- al_get_bitmap_width(player) / 4)
		 player_y+= movespeed;

  	 return player_y;
}

int Giocatore::spostaDX(int movespeed)
{
	if(player_x<800 )//- al_get_bitmap_width(player) / 4) 
 	   player_x += movespeed;

	return player_x;
}

int Giocatore::spostaSX(int movespeed)
{	
	if(player_x>0)
	  player_x -= movespeed;

	return player_x;
}

