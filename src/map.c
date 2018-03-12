/**
* @Author: vincent
* @Date:   2018-03-08T16:55:53+01:00
* @Filename: map.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-11T12:10:24+01:00
*/

#include "demineur.h"

void afficher_Sprites(t_demineur *demineur, int x, int y)
{
    if (demineur->map[y][x].isFlag == false)
    {
        if (demineur->map[y][x].isBomb == true)
        SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_EXPLODEDBOMB);
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
        else
        SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_NONE);
    }
}

void display_bombes(t_demineur *demineur)
{
    int i = 0;
    int u = 0;

    int x = 0;
    int y = 0;

    while (y != demineur->mapSize.y)
    {
        while (x != demineur->mapSize.x)
        {
            if (demineur->map[u][i].isBomb == true)
            SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_REMOVEDBOMB);
            ++x;
            ++i;
        }
        x = 0;
        i = 0;
        ++u;
        ++y;
    }
    display_map(demineur);
}

void display_numbers(t_demineur *demineur)
{
    int i = 0;
    int u = 0;

    int x = 0;
    int y = 0;

    while (y != demineur->mapSize.y)
    {
        while (x != demineur->mapSize.x)
        {
            if (demineur->map[u][i].isBomb == false && demineur->map[u][i].bombAround == 0)
            SetTexture_Sprite(&demineur->map[y][x].sprite, TEXTURE_REMOVEDBOMB);
            ++x;
            ++i;
        }
        x = 0;
        i = 0;
        ++u;
        ++y;
    }
    display_map(demineur);
}

void display_map(t_demineur *demineur)
{
    int i = 0;
    int u = 0;

    int x = 0;
    int y = 0;

    while (y != demineur->mapSize.y)
    {
        while (x != demineur->mapSize.x)
        {
            Draw_Sprite(demineur, demineur->map[u][i].sprite, x * DISP_TEXTURE, y * DISP_TEXTURE);
            ++x;
            ++i;
        }
        x = 0;
        i = 0;
        ++u;
        ++y;
    }
    sfRenderWindow_display(demineur->par_w->window);
}

void create_sprite(t_cell *cell)
{
    cell->sprite = Create_Sprite(TEXTURE_CELL);
}

void init_map(t_demineur *demineur)
{
    int     x = 0;
    int     y = 0;

    while (y != CELL_HEIGHT)
    {
        while (x != CELL_WIDTH)
        {
            demineur->map[y][x].coord.x = x;
            demineur->map[y][x].coord.y = y;
            demineur->map[y][x].isBomb = false;
            demineur->map[y][x].isFlag = false;
            demineur->map[y][x].isClicked = false;
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
    int     y = 0;

    demineur->map = malloc(sizeof(t_cell) * (demineur->mapSize.x * demineur->mapSize.y));
    while (y != demineur->mapSize.y)
    {
        demineur->map[y] = malloc(sizeof(t_cell) * (demineur->mapSize.x + 1));
        ++y;
    }


    init_map(demineur);
}
