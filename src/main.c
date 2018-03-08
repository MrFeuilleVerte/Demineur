/**
* @Author: vincent
* @Date:   2018-03-08T15:20:08+01:00
* @Filename: main.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T15:29:08+01:00
*/

#include "demineur.h"

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
    t_parameter_window	*par_w = malloc(sizeof(t_parameter_window));

    create_window(par_w);
    while (sfRenderWindow_isOpen(par_w->window))
    {
        
        sfRenderWindow_display(par_w->window);
        sfRenderWindow_clear(par_w->window, sfBlack);
    }
    return 0;
}
