#include"muro.h"

Muro::Muro(int x, int y)
{
	muro_x = x;
	muro_y = y;
}

Muro& Muro::operator=(const Muro& m)
{
	if (this != &m)
	{
		muro_x = m.muro_x;
		muro_y = m.muro_y;
	}

	return *this;
}

Muro::Muro(const Muro& m)
{
	muro_x = m.muro_x;
	muro_y = m.muro_y;
}