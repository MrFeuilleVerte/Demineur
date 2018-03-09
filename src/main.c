/**
* @Author: vincent
* @Date:   2018-03-08T15:20:08+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-10T00:55:13+01:00
*/

#include "demineur.h"

t_demineur *init_struct()
{
    t_demineur  *demineur;

    demineur = malloc(sizeof(t_demineur));
    demineur->par_w = malloc(sizeof(t_parameter_window));

    demineur->time = 0;
    demineur->nBomb = 0;
    demineur->mapSize.x = CELL_WIDTH;
    demineur->mapSize.y = CELL_HEIGHT;
    demineur->w_size.x = CELL_WIDTH * 32;
    demineur->w_size.y = CELL_HEIGHT * 32;

    return (demineur);
}

void create_window(t_demineur *demineur)
{
    sfVideoMode mode = {CELL_WIDTH * 32, CELL_HEIGHT * 32, 32};

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
    create_map(demineur);

    setup_mines(demineur);

    afficher_Sprites(demineur);
    display_map(demineur);


    //  PARTIE TEST     //

    display_bombes(demineur);
    numberMinesAround(demineur);


    while (sfRenderWindow_isOpen(demineur->par_w->window))
    {
        if (sfRenderWindow_pollEvent(demineur->par_w->window, &demineur->par_w->event))
        if (demineur->par_w->event.type == sfEvtClosed)
        sfRenderWindow_close(demineur->par_w->window);


        //if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)   // TEST CLIC GAUCHE
        // if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)  // TEST TOUCHE CLAVIER

        // sfVector2i	mouse;                    // GET MOUSE POSITION
        // mouse = sfMouse_getPosition(NULL);

        event(demineur);

        //sfRenderWindow_clear(demineur->par_w->window, sfBlack);
    }
    return 0;
}
