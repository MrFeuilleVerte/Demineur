#include "demineur.h"

void setup_mines(t_demineur *demineur)
{
	int tmpCellx;
	int tmpCelly;

	srand(time(NULL));

	for (int i = 0; i > demineur->nBomb; ++i)
	{
		tmpCellx = rand()%demineur->mapSize.x;
		tmpCelly = rand()%demineur->mapSize.y;

		while(demineur->map[tmpCellx][tmpCelly].isBomb == true)
		{
			tmpCellx = rand()%demineur->mapSize.x;
			tmpCelly = rand()%demineur->mapSize.y;
		}

		demineur->map[tmpCellx][tmpCelly].isBomb = true;

		//emplacement de la case sur un pave numerique, 5 la bombe

		if(tmpCellx <= 0 && tmpCelly <= 0)
		++demineur->map[(tmpCellx - 1)][(tmpCelly - 1)].bombAround; //7

		if(tmpCelly <= 0)
		++demineur->map[tmpCellx][(tmpCelly - 1)].bombAround; //8

		if(tmpCellx >= demineur->mapSize.x && tmpCelly <= 0)
		++demineur->map[(tmpCellx + 1)][(tmpCelly - 1)].bombAround; //9

		if(tmpCellx <= 0)
		++demineur->map[(tmpCellx - 1)][tmpCelly].bombAround; //4

		if(tmpCellx >= demineur->mapSize.x)
		++demineur->map[(tmpCellx + 1)][tmpCelly].bombAround; //6

		if(tmpCellx <= 0 && tmpCelly >= demineur->mapSize.y)
		++demineur->map[(tmpCellx - 1)][(tmpCelly + 1)].bombAround; //1

		if(tmpCelly >= demineur->mapSize.y)
		++demineur->map[tmpCellx][(tmpCelly + 1)].bombAround; //2

		if(tmpCellx >= demineur->mapSize.x && tmpCelly >= demineur->mapSize.y)
		++demineur->map[(tmpCellx + 1)][(tmpCelly + 1)].bombAround; //3


	}

}

void afficher_Sprites(t_demineur *demineur){

for (int colonne = 0; colonne < demineur->mapSize.y; ++colonne)
{
	for (int ligne = 0; ligne < demineur->mapSize.x; ++ligne)
	{
		if (demineur->map[ligne][colonne].isBomb = true)
		 {
		 	SetTexture_Sprite(&demineur->map[ligne][colonne].sprite, TEXTURE_REMOVEDBOMB); // ici les bombes
		 }
		/*
		for (int nbBombAround = 1; nbBombAround < 9; ++nbBombAround)
		{
			if (demineur->map[colonne][ligne].bombAround == nbBombAround)
			{
				SetTexture_Sprite(&demineur->map[ligne][colonne].sprite, TEXTURE_ONE); // ici les numeros
			}
		}
		*/
	}
}




		//demineur->map[x][y].isBomb = true;


}
