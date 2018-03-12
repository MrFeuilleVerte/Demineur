/**
* @Author: vincent
* @Date:   2018-03-10T16:01:19+01:00
* @Filename: free_structs.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-10T16:13:59+01:00
*/

#include "demineur.h"

int     free_struct_demineur(t_demineur *demineur)
{
    free(demineur);
    return (0);
}

int     destroy_sprite(t_sprite *sprite)
{
    sfSprite_destroy(sprite->sprite);
    return (0);
}

int     free_struct_map(t_cell **map)
{
    int     u = 0;
    int     i = 0;

    while (u < CELL_HEIGHT)
    {
        while (i < CELL_WIDTH)
        {
            destroy_sprite(&map[u][i].sprite);
            ++i;
        }
        free(map[u]);
        i = 0;
        ++u;
    }
    return (0);
}
