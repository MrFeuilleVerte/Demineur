/**
* @Author: vincent
* @Date:   2018-03-08T16:55:53+01:00
* @Filename: map.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T22:21:58+01:00
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
