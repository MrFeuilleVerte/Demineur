/**
* @Author: vincent
* @Date:   2018-03-08T15:20:08+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-12T08:44:34+01:00
*/

#include "demineur.h"

t_demineur *init_struct()
{
    t_demineur  *demineur;

    demineur = malloc(sizeof(t_demineur));
    demineur->par_w = malloc(sizeof(t_parameter_window));

    demineur->time = 0;
    demineur->nBomb = 10;
    demineur->mapSize.x = CELL_WIDTH;
    demineur->mapSize.y = CELL_HEIGHT;
    demineur->w_size.x = CELL_WIDTH * 32;
    demineur->w_size.y = CELL_HEIGHT * 32;

    demineur->win = false;
    demineur->lose = false;
    demineur->restart = true;

    return (demineur);
}

void create_window(t_demineur *demineur)
{
    sfVideoMode mode = {CELL_WIDTH * DISP_TEXTURE, CELL_HEIGHT * DISP_TEXTURE, 32};

    demineur->par_w->w_size.x = CELL_WIDTH * DISP_TEXTURE;
    demineur->par_w->w_size.y = CELL_HEIGHT * DISP_TEXTURE;
    demineur->par_w->window = sfRenderWindow_create(mode , GAME_NAME, sfTitlebar | sfClose , NULL);
    sfRenderWindow_setFramerateLimit(demineur->par_w->window, FRAME_RATE);
    sfRenderWindow_clear(demineur->par_w->window, sfBlack);
}

int main()
{
    t_demineur          *demineur = init_struct();

    create_window(demineur);

    while (1)
    {
        create_map(demineur);

        setup_mines(demineur);
        numberMinesAround(demineur);

        display_map(demineur);

        //display_bombes(demineur);

        while (demineur->restart == true)
        {
            if (sfRenderWindow_pollEvent(demineur->par_w->window, &demineur->par_w->event))
            if (demineur->par_w->event.type == sfEvtClosed)
            sfRenderWindow_close(demineur->par_w->window);
            if ((event(demineur)) == 1)
            demineur->restart = false;
        }
        free_struct_map(demineur->map);
        demineur->restart = true;
    }
    free_struct_demineur(demineur);
    return (0);
}
