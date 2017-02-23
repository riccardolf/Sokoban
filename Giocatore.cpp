#include"Giocatore.h"

Giocatore::Giocatore(int x, int y)
{
	x_iniziale=x;
	y_iniziale=y;
	player_x=x;
	player_y=y;
	Dir = 0;
	
}

Giocatore::Giocatore(const Giocatore& g)
{
	x_iniziale=g.x_iniziale;
	y_iniziale=g.y_iniziale;
	player_x=g.player_x;
	player_y=g.player_y;
	Dir = g.Dir;
}

Giocatore& Giocatore::operator=(const Giocatore &g)
{
	if(this!=&g)
	{
		x_iniziale=g.x_iniziale;
		y_iniziale=g.y_iniziale;
		player_x=g.player_x;
		player_y=g.player_y;
		Dir = g.Dir;
	}
	
	return *this;
}

// UP = 2, LEFT = 1, DOWN = 0, RIGHT = 3
void Giocatore::MovePlayer()
{
	if (Dir == 2)
		player_y--;
	if (Dir == 0)
		player_y++;
	if (Dir == 1)
		player_x--;
	if (Dir == 3)
		player_x++;
}