#include "demineur.h"

void setup_mines(t_demineur *demineur)
{
	int tmpCellx;
	int tmpCelly;

	for (int i = 0; i > demineur->nBomb; ++i)
	{
		tmpCellx = rand()%demineur->mapSize.x;
		tmpCelly = rand()%demineur->mapSize.y;

		while(demineur->map[tmpCellx][tmpCelly].isBomb == true)
		{
			tmpCellx = rand()%demineur->mapSize.x;
			tmpCelly = rand()%demineur->mapSize.y;
		}

		demineur.map[tmpCellx][tmpCelly].isBomb = true;

		//emplacement de la case sur un pave numerique, 5 la bombe
		
		if(tmpCellx <= 0 || tmpCelly <= 0)
		++demineur.map[(tmpCellx - 1)][(tmpCelly - 1)].bombAround; //7

		if(tmpCelly <= 0)
		++demineur.map[tmpCellx][(tmpCelly - 1)].bombAround; //8

		if(tmpCellx >= demineur.Map_Size.x || tmpCelly <= 0)
		++demineur.map[(tmpCellx + 1)][(tmpCelly - 1)].bombAround; //9
		
		if(tmpCellx <= 0)
		++demineur.map[(tmpCellx - 1)][tmpCelly].bombAround; //4

		if(tmpCellx >= demineur.Map_Size.x)
		++demineur.map[(tmpCellx + 1)][tmpCelly].bombAround; //6
		
		if(tmpCellx <= 0 || tmpCelly >= demineur.Map_Size.y)
		++demineur.map[(tmpCellx - 1)][(tmpCelly + 1)].bombAround; //1

		if(tmpCelly >= demineur.Map_Size.y)
		++demineur.map[tmpCellx][(tmpCelly + 1)].bombAround; //2

		if(tmpCellx >= demineur.Map_Size.x || tmpCelly >= demineur.Map_Size.y)
		++demineur.map[(tmpCellx + 1)][(tmpCelly + 1)].bombAround; //3


	}

}