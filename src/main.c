/**
* @Author: vincent
* @Date:   2018-03-08T15:20:08+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T19:53:11+01:00
*/

#include "demineur.h"

t_demineur *init_struct()
{
    t_demineur  *demineur;

    demineur = malloc(sizeof(t_demineur));

    demineur->time = 0;
    demineur->nBomb = 0;
    demineur->mapSize.x = 10;
    demineur->mapSize.y = 20;

    return (demineur);
}


void create_window(t_parameter_window *par_w)
{
    par_w->mode = sfVideoMode_getFullscreenModes(NULL);
    par_w->window = sfRenderWindow_create(*par_w->mode, GAME_NAME, sfTitlebar | sfResize | sfClose | sfFullscreen , NULL);
    par_w->w_size = sfRenderWindow_getSize(par_w->window);
    sfRenderWindow_setFramerateLimit(par_w->window, FRAME_RATE);
    sfRenderWindow_clear(par_w->window, sfBlack);
}

int main()
{
    t_demineur          *demineur = init_struct();
    t_parameter_window	*par_w = malloc(sizeof(t_parameter_window));

    create_window(par_w);
    create_map(demineur);

    while (sfRenderWindow_isOpen(par_w->window))
    {

        //if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)   // TEST CLIC GAUCHE
        // if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)  // TEST TOUCHE CLAVIER

        // sfVector2i	mouse;                    // GET MOUSE POSITION
        // mouse = sfMouse_getPosition(NULL);

        display_map(par_w, demineur);

        sfRenderWindow_display(par_w->window);
        sfRenderWindow_clear(par_w->window, sfBlack);
    }
    return 0;
}
