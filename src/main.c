/**
* @Author: vincent
* @Date:   2018-03-08T15:20:08+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T22:49:10+01:00
*/

#include "demineur.h"

t_demineur *init_struct()
{
    t_demineur  *demineur;

    demineur = malloc(sizeof(t_demineur));

    demineur->time = 0;
    demineur->nBomb = 0;
    demineur->mapSize.x = CELL_WIDTH;
    demineur->mapSize.y = CELL_HEIGHT;
    demineur->w_size.x = CELL_WIDTH * 32;
    demineur->w_size.y = CELL_HEIGHT * 32;

    return (demineur);
}


void create_window(t_parameter_window *par_w)
{
    sfVideoMode mode = {CELL_WIDTH * 32, CELL_HEIGHT * 32, 32};

    //par_w->mode = sfVideoMode_getFullscreenModes(NULL);

    par_w->w_size.x = CELL_WIDTH * DISP_TEXTURE;
    par_w->w_size.y = CELL_HEIGHT * DISP_TEXTURE;
    par_w->window = sfRenderWindow_create(mode , GAME_NAME, sfTitlebar | sfClose , NULL);
    sfRenderWindow_setFramerateLimit(par_w->window, FRAME_RATE);
    sfRenderWindow_clear(par_w->window, sfBlack);
}

int main()
{
    t_demineur          *demineur = init_struct();
    t_parameter_window	*par_w = malloc(sizeof(t_parameter_window));

    create_window(par_w);
    create_map(demineur);
    setup_mines(demineur);

/*
    SetTexture_Sprite(&demineur->map[4][6].sprite, TEXTURE_EXPLODEDBOMB);
    SetTexture_Sprite(&demineur->map[3][6].sprite, TEXTURE_NONE);
    SetTexture_Sprite(&demineur->map[5][6].sprite, TEXTURE_NONE);
    SetTexture_Sprite(&demineur->map[3][7].sprite, TEXTURE_NONE);
    SetTexture_Sprite(&demineur->map[4][5].sprite, TEXTURE_FLAG);
*/
    while (sfRenderWindow_isOpen(par_w->window))
    {

        //if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)   // TEST CLIC GAUCHE
        // if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)  // TEST TOUCHE CLAVIER

        // sfVector2i	mouse;                    // GET MOUSE POSITION
        // mouse = sfMouse_getPosition(NULL);

        event(par_w, demineur);

        display_map(par_w, demineur);

        sfRenderWindow_display(par_w->window);
        sfRenderWindow_clear(par_w->window, sfBlack);
    }
    return 0;
}
