#include"giocatore.h"

Giocatore::Giocatore(int x, int y)
{
	x_iniziale = x;
	y_iniziale = y;
	player_x = x;
	player_y = y;
	movespeed = 64;
}

Giocatore::Giocatore(const Giocatore& g)
{
	x_iniziale = g.x_iniziale;
	y_iniziale = g.y_iniziale;
	player_x = g.player_x;
	player_y = g.player_y;
	movespeed = g.movespeed;

}

Giocatore& Giocatore::operator=(const Giocatore &g)
{
	if (this != &g)
	{
		x_iniziale = g.x_iniziale;
		y_iniziale = g.y_iniziale;
		player_x = g.player_x;
		player_y = g.player_y;
		movespeed = g.movespeed;
	}

	return *this;
}

int Giocatore::sposta(int dir)
{
	if (dir == 2)
		return player_y -= movespeed;
	else if (dir == 0)
		return player_y += movespeed;
	else if (dir == 1)
		return player_x -= movespeed;
	else if (dir == 3)
		return player_x += movespeed;
}
