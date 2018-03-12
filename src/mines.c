#include "demineur.h"

int GetMinesAround(t_demineur *demineur, int x, int y)
{
	int MinesAround = 0;

	int i = 0;
	int coord_x[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	int coord_y[] = {-1, -1, -1, 0, 1, 1, 1, 0};

	// ORDRE CHECK //

	//123
	//804
	//765

	while (i < 8)
	{
		if ((x + coord_x[i] >= 0 && x + coord_x[i] < demineur->mapSize.x)
		&& (y + coord_y[i] >= 0 && y + coord_y[i] < demineur->mapSize.y))
		{
			if (demineur->map[y + coord_y[i]][x + coord_x[i]].isBomb == true)
			++MinesAround;
		}
		++i;
	}
	return(MinesAround);
}

void numberMinesAround(t_demineur *demineur)
{
	int x = 0;
	int y = 0;

	while (y != demineur->mapSize.y)
	{
		while (x != demineur->mapSize.x)
		{
			if (demineur->map[y][x].isBomb == false)
			demineur->map[y][x].bombAround = GetMinesAround(demineur, x, y);
			++x;
		}
		x = 0;
		++y;
	}
	display_map(demineur);
}

void setup_mines(t_demineur *demineur)
{
	int tmpCellx;
	int tmpCelly;

	srand(time(NULL));

	for (int i = 0; i < demineur->nBomb; ++i)
	{
		tmpCellx = rand()%demineur->mapSize.x;
		tmpCelly = rand()%demineur->mapSize.y;

		while(demineur->map[tmpCelly][tmpCellx].isBomb == true)
		{
			tmpCellx = rand()%demineur->mapSize.x;
			tmpCelly = rand()%demineur->mapSize.y;
		}
		demineur->map[tmpCelly][tmpCellx].isBomb = true;

	}
}
