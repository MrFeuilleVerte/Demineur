/**
* @Author: vincent
* @Date:   2018-03-08T21:47:04+01:00
* @Filename: event.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-11T12:54:07+01:00
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

int    place_flag(t_demineur *demineur, sfVector2i SpriteLocation, int *canUseRightButton)
{

    // RESET BUTTON //
    if (sfMouse_isButtonPressed(sfMouseRight) == sfFalse)
    canUseRightButton[0] = 1;

    // USE BUTTON //
    if (canUseRightButton[0] == 1 && sfMouse_isButtonPressed(sfMouseRight) == sfTrue)
    {
        // PLACE FLAG //
        if ((demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag == false)
        && (demineur->map[SpriteLocation.y][SpriteLocation.x].isClicked == false))
        {
            canUseRightButton[0] = 0;
            demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag = true;
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_FLAG);
            if (checkWin(demineur) == 1)
            {
                demineur->win = true;
                if (end(demineur) == 1)
                return (1);
            }
            display_map(demineur);
        }
        // REMOVE FLAG //
        else if (demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag == true)
        {
            canUseRightButton[0] = 0;
            demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag = false;
            demineur->map[SpriteLocation.y][SpriteLocation.x].isClicked == false;
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_CELL);
            display_map(demineur);
            if (checkWin(demineur) == 1)
            {
                demineur->win = true;
                if (end(demineur) == 1)
                return (1);
            }
        }
    }
}

int ShowCellNone(t_demineur *demineur, int x, int y)
{
    int i = 0;
    int coord_x[] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
    int coord_y[] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};

    // ORDRE CHECK //

    //123
    //894
    //765

    if (demineur->map[y][x].bombAround > 0)
        return (0);


    while (i < 9)
    {
        if ((x + coord_x[i] >= 0 && x + coord_x[i] < demineur->mapSize.x)
        && (y + coord_y[i] >= 0 && y + coord_y[i] < demineur->mapSize.y))
        {
            if ((demineur->map[y + coord_y[i]][x + coord_x[i]].isFlag == false)
            && (demineur->map[y + coord_y[i]][x + coord_x[i]].isBomb == false)
            && (demineur->map[y + coord_y[i]][x + coord_x[i]].isClicked == false))
            {
                demineur->map[y + coord_y[i]][x + coord_x[i]].isClicked = true;
                afficher_Sprites(demineur, x + coord_x[i], y + coord_y[i]);
                ShowCellNone(demineur, x + coord_x[i], y + coord_y[i]);
            }
        }
        ++i;
    }
    return (0);
}

int ClickOnCase(t_demineur *demineur, sfVector2i SpriteLocation, int *canUseLeftButton)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfFalse)
    canUseLeftButton[0] = 1;

    if (canUseLeftButton[0] == 1 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
    {
        canUseLeftButton[0] = 0;
        if (demineur->map[SpriteLocation.y][SpriteLocation.x].isFlag == false)
        {
            if (demineur->map[SpriteLocation.y][SpriteLocation.x].isBomb == true)
            {
                SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_EXPLODEDBOMB);
                display_map(demineur);
                demineur->lose = true;
                if (end(demineur) == 1)
                return (1);
            }
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 1)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_1); // ici les 1
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 2)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_2); // ici les 2
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 3)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_3); // ici les 3
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 4)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_4); // ici les 4
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 5 )
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_5); // ici les 5
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 6)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_6); // ici les 6
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 7)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_7); // ici les 7
            else if (demineur->map[SpriteLocation.y][SpriteLocation.x].bombAround == 8)
            SetTexture_Sprite(&demineur->map[SpriteLocation.y][SpriteLocation.x].sprite, TEXTURE_8); // ici les 8
            else
            ShowCellNone(demineur, SpriteLocation.x, SpriteLocation.y);
            if (checkWin(demineur) == 1)
            {
                demineur->win = true;
                if (end(demineur) == 1)
                return (1);
            }
        }
        display_map(demineur);
    }
    return (0);
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
        if (y >= mouse.y / DISP_TEXTURE && x >= mouse.x / DISP_TEXTURE)
        return (SpriteLocation);
        while (x != CELL_WIDTH)
        {
            SpriteLocation.x = x;
            if (y >= mouse.y / DISP_TEXTURE && x >= mouse.x / DISP_TEXTURE)
            return (SpriteLocation);
            ++x;
        }
        SpriteLocation.x = 0;
        x = 0;
        ++y;
    }
    return (SpriteLocation);
}

int event(t_demineur *demineur)
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

        if ((place_flag(demineur, SpriteLocation, &canUseRightButton)) == 1)
        return (1);
        if ((ClickOnCase(demineur, SpriteLocation, &canUseLeftButton)) == 1)
        return (1);
    }
    return (0);
}
