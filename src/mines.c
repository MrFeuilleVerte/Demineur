#include "demineur.h"

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


		//emplacement de la case sur un pave numerique, 5 la bombe


		if(tmpCelly <= 0 && tmpCellx <= 0)
		++demineur->map[(tmpCelly - 1)][(tmpCellx - 1)].bombAround; //7

		if(tmpCellx <= 0)
		++demineur->map[tmpCelly - 1][(tmpCellx)].bombAround; //8

		if(tmpCelly >= demineur->mapSize.x && tmpCellx <= 0)
		++demineur->map[(tmpCelly + 1)][(tmpCellx - 1)].bombAround; //9

		if(tmpCelly <= 0)
		++demineur->map[(tmpCelly)][tmpCellx - 1].bombAround; //4

		if(tmpCelly >= demineur->mapSize.x)
		++demineur->map[(tmpCelly)][tmpCellx + 1].bombAround; //6

		if(tmpCelly <= 0 && tmpCellx >= demineur->mapSize.x)
		++demineur->map[(tmpCelly + 1)][(tmpCellx - 1)].bombAround; //1

		if(tmpCellx >= demineur->mapSize.x)
		++demineur->map[tmpCelly + 1][(tmpCellx)].bombAround; //2

		if(tmpCelly >= demineur->mapSize.x && tmpCellx >= demineur->mapSize.x)
		++demineur->map[(tmpCelly + 1)][(tmpCellx + 1)].bombAround; //3


	}

}
