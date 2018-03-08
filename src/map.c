/**
* @Author: vincent
* @Date:   2018-03-08T16:55:53+01:00
* @Filename: map.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T19:47:00+01:00
*/

#include "demineur.h"

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
            Draw_Sprite(par_w, demineur->map[u][i].sprite[CELL], x * DISP_TEXTURE, y * DISP_TEXTURE);
            ++x;
            ++i;
        }
        x = 0;
        i = 0;
        ++u;
        ++y;
    }
}

void create_all_sprites(t_cell *cell)
{
    cell->sprite[0] = Create_Sprite(TEXTURE_NONE);
    cell->sprite[1] = Create_Sprite(TEXTURE_1);
    cell->sprite[2] = Create_Sprite(TEXTURE_2);
    cell->sprite[3] = Create_Sprite(TEXTURE_3);
    cell->sprite[4] = Create_Sprite(TEXTURE_4);
    cell->sprite[5] = Create_Sprite(TEXTURE_5);
    cell->sprite[6] = Create_Sprite(TEXTURE_6);
    cell->sprite[7] = Create_Sprite(TEXTURE_7);
    cell->sprite[8] = Create_Sprite(TEXTURE_8);
    cell->sprite[9] = Create_Sprite(TEXTURE_CELL);
    cell->sprite[10] = Create_Sprite(TEXTURE_FLAG);
    cell->sprite[11] = Create_Sprite(TEXTURE_EXPLODEDBOMB);
    cell->sprite[12] = Create_Sprite(TEXTURE_REMOVEDBOMB);
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
            demineur->map[y][x].sprite = malloc(sizeof(t_sprite) * NB_TEXTURE);
            create_all_sprites(&demineur->map[y][x]);
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
