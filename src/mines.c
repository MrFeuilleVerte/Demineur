#include "demineur.h"

int GetMinesAround(t_demineur *demineur, int x, int y)
{
	int MinesAround = 0;
	int tmpx2 = x;
	int tmpy2 = y;
	int tmpx = x;
	int tmpy = y;

	//printf("x = %d | y = %d\n",x, y);

	if (--tmpy >= 0 && --tmpx >= 0)
	if (demineur->map[--y][--x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (--tmpy >= 0)
	if (demineur->map[--y][x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (--tmpy >= 0 && ++tmpx <= demineur->mapSize.x)
	if (demineur->map[--y][++x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (++tmpx <= demineur->mapSize.x)
	if (demineur->map[y][++x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (++tmpy < demineur->mapSize.y && ++tmpx <= demineur->mapSize.x)
	if (demineur->map[++y][++x].isBomb == true)
	++MinesAround;
	y = tmpy = tmpy2;
	x = tmpx = tmpx2;
	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (++tmpy < demineur->mapSize.y)
	if (demineur->map[++y][x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (++tmpy < demineur->mapSize.y && --tmpx >= 0)
	if (demineur->map[++y][--x].isBomb == true)
	++MinesAround;

	y = tmpy = tmpy2;
	x = tmpx = tmpx2;

	if (--tmpx >= 0)
	if (demineur->map[y][--x].isBomb == true)
	++MinesAround;


	printf("MinesAround = %d\n", MinesAround);

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

			if (demineur->map[y][x].bombAround == 1)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_1); // ici les 1
			else if (demineur->map[y][x].bombAround == 2)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_2); // ici les 2
			else if (demineur->map[y][x].bombAround == 3)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_3); // ici les 3
			else if (demineur->map[y][x].bombAround == 4)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_4); // ici les 4
			else if (demineur->map[y][x].bombAround == 5 )
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_5); // ici les 5
			else if (demineur->map[y][x].bombAround == 6)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_6); // ici les 6
			else if (demineur->map[y][x].bombAround == 7)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_7); // ici les 7
			else if (demineur->map[y][x].bombAround == 8)
			SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_8); // ici les 8
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
		//tmpCellx = (rand()%demineur->mapSize.x);
		//tmpCelly = (rand()%demineur->mapSize.y);

		tmpCellx = 0;
		tmpCelly = 0;

		while(demineur->map[tmpCelly][tmpCellx].isBomb == true)
		{
			tmpCellx = rand()%demineur->mapSize.x;
			tmpCelly = rand()%demineur->mapSize.y;
		}
		demineur->map[tmpCelly][tmpCellx].isBomb = true;

	}
}
