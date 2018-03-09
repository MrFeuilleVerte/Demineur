/**
* @Author: vincent
* @Date:   2018-03-08T16:55:53+01:00
* @Filename: map.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T23:27:41+01:00
*/

#include "demineur.h"

void afficher_Sprites(t_demineur *demineur)
{
    int x = 0;
    int y = 0;

    while (y < demineur->mapSize.y)
    {
        while (x < demineur->mapSize.x)
        {
            if (demineur->map[y][x].isBomb == true)
            SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_REMOVEDBOMB); // ici les bombes
            ++x;
        }
        x = 0;
        ++y;
    }

    x = 0;
    y = 0;

    while (y < demineur->mapSize.y)
    {
        while (x < demineur->mapSize.x)
        {
            if (demineur->map[y][x].isClicked == true)
            {  
                if (demineur->map[y][x].isBomb == true)
                SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_EXPLODEDBOMB); // ici les bombes
                else if (demineur->map[y][x].bombAround == 0)
                SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_NONE); // ici les case vides
                else if (demineur->map[y][x].bombAround == 1)
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
            }
            else if (demineur->map[y][x].isClicked == false){
                if (demineur->map[y][x].isFlag == true)
                SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_FLAG);
                else SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_CELL);
            }
            ++x;
        }
        x = 0;
        ++y;
    }
}

void display_map(t_parameter_window *par_w, t_demineur *demineur)
{
    int i = 0;
    int u = 0;

    int x = 0;
    int y = 0;

    while (y != demineur->mapSize.y)
    {
        while (x != demineur->mapSize.x)
        {
            Draw_Sprite(par_w, demineur->map[u][i].sprite, x * DISP_TEXTURE, y * DISP_TEXTURE);
            ++x;
            ++i;
        }
        x = 0;
        i = 0;
        ++u;
        ++y;
    }
}

void create_sprite(t_cell *cell)
{
    cell->sprite = Create_Sprite(TEXTURE_CELL);
}

void init_map(t_demineur *demineur)
{
    int     x = 0;
    int     y = 0;

    while (y != demineur->mapSize.y)
    {
        while (x != demineur->mapSize.x)
        {
            demineur->map[y][x].coord.x = x;
            demineur->map[y][x].coord.y = y;
            demineur->map[y][x].isBomb = false;
            demineur->map[y][x].isFlag = false;
            demineur->map[y][x].isClicked = 0;
            demineur->map[y][x].bombAround = 0;
            create_sprite(&demineur->map[y][x]);
            ++x;
        }
        x = 0;
        ++y;
    }

}

void create_map(t_demineur *demineur)
{
    int     u = 0;
    int     i = 0;

    demineur->map = malloc(sizeof(t_cell) * (demineur->mapSize.x * demineur->mapSize.y));
    while (u != demineur->mapSize.y)
    {
        demineur->map[u] = malloc(sizeof(t_cell) * (demineur->mapSize.x + 1));
        ++u;
    }

    init_map(demineur);
}
