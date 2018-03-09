/**
* @Author: vincent
* @Date:   2018-03-08T21:47:04+01:00
* @Filename: event.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-10T00:29:19+01:00
*/

#include "demineur.h"

int     sfGetEventType(t_demineur *demineur, sfEventType type)
{
    if (sfRenderWindow_pollEvent(demineur->par_w->window, &demineur->par_w->event))
    if (demineur->par_w->event.type == type)
    return(1);
    else
    return (0);
    return (0);
}

int     relacheButtonMouse(t_demineur *demineur, sfMouseButton button)
{
    if (sfGetEventType(demineur, sfEvtMouseButtonReleased) == true &&
    demineur->par_w->event.mouseButton.button == button)
    return (1);
    else
    return (0);
    return (0);
}

void    place_flag(t_demineur *demineur, sfVector2i SpriteLocation, int *canUseRightButton)
{

    // RESET BUTTON //
    if (sfMouse_isButtonPressed(sfMouseRight) == sfFalse)
    canUseRightButton[0] = 1;

    // USE BUTTON //
    if (canUseRightButton[0] == 1 && sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
    {
        // PLACE FLAG //
        if (demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag != true
            && demineur->map[SpriteLocation.y][SpriteLocation.x].isClicked != true
            && demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 0)
        {
            canUseRightButton[0] = 0;
            demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag = true;
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_FLAG);

        //    if (demineur->map[SpriteLocation.y][SpriteLocation.x].isBomb == true)
        //    printf("BOMBE\n");

            display_map(demineur);
        }
        // REMOVE FLAG //
        else if (demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag == true)
        {
            canUseRightButton[0] = 0;
            demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag = false;
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_CELL);
            display_map(demineur);
        }
    }
}

void ClickOnCase(t_demineur *demineur, sfVector2i SpriteLocation, int *canUseLeftButton)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
    canUseLeftButton[0] = 1;
    if (canUseLeftButton[0] == 1 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    {
        canUseLeftButton[0] = 0;
        demineur->map[SpriteLocation.y][SpriteLocation.x].isClicked = true;
        SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_NONE);
        display_map(demineur);
    }
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
        SpriteLocation.x = 0;
        x = 0;
        ++y;
    }
    return (SpriteLocation);
}

void event(t_demineur *demineur)
{
    sfVector2i	mouse;
    sfVector2i  SpriteLocation;

    sfEvent rightClic;

    mouse =  sfMouse_getPosition(demineur->par_w->window);

    static int canUseLeftButton = 1;
    static int canUseRightButton = 1;

    if (mouseIsOnScreen(mouse) == 1)
    {
        SpriteLocation = changeTexture(mouse);

        place_flag(demineur, SpriteLocation, &canUseRightButton);
        ClickOnCase(demineur, SpriteLocation, &canUseLeftButton);
    }
}
