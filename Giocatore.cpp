#include"Giocatore.h"

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
}

Giocatore& Giocatore::operator=(const Giocatore &g)
{
	if(this!=&g)
	{
		x_iniziale=g.x_iniziale;
		y_iniziale=g.y_iniziale;
		player_x=g.player_x;
		player_y=g.player_y;
	}
	
	return *this;
}

//Movimenti del player
void Giocatore::MovePlayer(int dir)
{
	//DOWN = 0, LEFT=1,UP=2, RIGHT=3
	if(dir==2)
		player_y--;
	if(dir==0)
		player_y++;	
	if(dir==1)
		player_x--;	
	if(dir==3)
		player_x++;	
}

