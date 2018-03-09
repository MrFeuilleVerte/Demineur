/**
* @Author: vincent
* @Date:   2018-03-08T21:47:04+01:00
* @Filename: event.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-09T09:14:36+01:00
*/

#include "demineur.h"

void    place_flag()
{

}

int mouseIsOnScreen(sfVector2i	mouse)
{
    if (mouse.x >= 0 && mouse.x <= (DISP_TEXTURE * CELL_WIDTH) && mouse.y >= 0 && mouse.y <= (DISP_TEXTURE * CELL_HEIGHT))
    return (1);
    else
    return (0);
    return (0);
}

int testMouseCoord(sfVector2i mouse, int xMin, int xMax, int yMin, int yMax)
{
    if (mouse.x > xMin && mouse.x < xMax && mouse.y > yMin && mouse.y < yMax)
    return (1);
    else
    return (0);
    return (0);
}

sfVector2i changeTexture(sfVector2i mouse)
{
    sfVector2i SpriteLocation;

    int x = 0;
    int y = 0;

    SpriteLocation.x = 0;
    SpriteLocation.y = 0;

    while (y != CELL_HEIGHT)
    {
        SpriteLocation.y = y;
        if (y >= mouse.y / 32 && x >= mouse.x / 32)
        return (SpriteLocation);
        while (x != CELL_WIDTH)
        {
            SpriteLocation.x = x;
            if (y >= mouse.y / 32 && x >= mouse.x / 32)
            return (SpriteLocation);
            ++x;
        }
        x = 0;
        ++y;
    }
    return (SpriteLocation);
}

void event(t_parameter_window *par_w, t_demineur *demineur)
{
    sfVector2i	mouse;
    sfVector2i  SpriteLocation;


    mouse =  sfMouse_getPosition(par_w->window);


    if (mouseIsOnScreen(mouse) == 1)
    {
        //printf("X = %d | Y = %d\n", mouse.x / 32, mouse.y / 32);

        if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
        {
            SpriteLocation = changeTexture(mouse);
        //    printf("x = %d | y = %d\n", SpriteLocation.x, SpriteLocation.y);
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_FLAG);
        //    printf("%d\n", mouse.x / 32);
        }
    }
}
