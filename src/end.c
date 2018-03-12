/**
* @Author: vincent
* @Date:   2018-03-10T15:18:19+01:00
* @Filename: end.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-12T08:47:42+01:00
*/

#include "demineur.h"

int AllCaseChecked(t_demineur *demineur)
{
    int x = 0;
    int y = 0;

    while (y != CELL_HEIGHT)
    {
        while (x != CELL_WIDTH)
        {
            if (demineur->map[y][x].isClicked == true)
            ++x;
            else if (demineur->map[y][x].isBomb == true)
            ++x;
            else if ((demineur->map[y][x].isClicked == false)
            && (demineur->map[y][x].isBomb == false))
            return (0);
            //    else
            //    printf("Value = %d \n", demineur->map[y][x].isClicked);
            //    printf("X = %d | Y = %d\n", x, y);
        }
        x = 0;
        ++y;
    }
    return (1);
}

int checkWin(t_demineur *demineur)
{
    int x = 0;
    int y = 0;

    int bombDesam = 0;
    int flagplaced = 0;
    int allCaseCheckedV = AllCaseChecked(demineur);

    while (y != CELL_HEIGHT)
    {
        while (x != CELL_WIDTH)
        {
            if ((demineur->map[y][x].isBomb == true )
            && (demineur->map[y][x].isFlag == true))
            ++bombDesam;
            if (demineur->map[y][x].isFlag == true)
            ++flagplaced;
            ++x;
        }
        x = 0;
        ++y;
    }
    if (bombDesam == demineur->nBomb && bombDesam == flagplaced) // && allCaseCheckedV == 1)
    return (1);

    return (0);
}

int WinLose(t_demineur *demineur)
{
    if (demineur->win == true)
    {
        demineur->end = Create_Sprite(TEXTURE_Win);
        demineur->end.sprite_origin.x = 192/2;
        demineur->end.sprite_origin.y = 64/2;
        demineur->end.sprite_scale.x = 2;
        demineur->end.sprite_scale.y = 2;
        demineur->end.sprite_position.x = demineur->w_size.x / 2;
        demineur->end.sprite_position.y = demineur->w_size.y / 2;
        Draw_Sprite(demineur, demineur->end, demineur->end.sprite_position.x, demineur->end.sprite_position.y);
        return (0);
    }
    if (demineur->lose == true)
    {
        demineur->end = Create_Sprite(TEXTURE_Lose);
        demineur->end.sprite_origin.x = 192/2;
        demineur->end.sprite_origin.y = 64/2;
        demineur->end.sprite_scale.x = 2;
        demineur->end.sprite_scale.y = 2;
        demineur->end.sprite_position.x = demineur->w_size.x / 2;
        demineur->end.sprite_position.y = demineur->w_size.y / 2;
        Draw_Sprite(demineur, demineur->end, demineur->end.sprite_position.x, demineur->end.sprite_position.y);
        return (0);
    }
    return (0);
}

int end(t_demineur *demineur)
{
    display_map(demineur);
    WinLose(demineur);
    sfRenderWindow_display(demineur->par_w->window);
    while(1)
    {
        if (sfRenderWindow_pollEvent(demineur->par_w->window, &demineur->par_w->event))
        if (demineur->par_w->event.type == sfEvtClosed)
        sfRenderWindow_close(demineur->par_w->window);
        if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        exit(0);
        if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
        {
            demineur->win = false;
            demineur->lose = false;
            demineur->restart = true;
            destroy_sprite(&demineur->end);
            sfRenderWindow_display(demineur->par_w->window);
            return (1);
        }
    }
    return (0);
}
