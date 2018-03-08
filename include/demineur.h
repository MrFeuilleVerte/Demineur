/**
* @Author: vincent
* @Date:   2018-03-08T15:20:03+01:00
* @Filename: demineur.h
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T22:23:22+01:00
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <SFML/Graphics.h>

#define NB_TEXTURE      13
#define DISP_TEXTURE    32
#define GAME_NAME       "DEMINEUR"
#define FRAME_RATE      30

#define CELL_WIDTH      10
#define CELL_HEIGHT     20

#define ERROR           84

#define TEXTURE_CELL             "./img/cell.png"               // 9
#define TEXTURE_NONE             "./img/none.png"               // 0
#define TEXTURE_FLAG             "./img/flag.png"               // 10
#define TEXTURE_EXPLODEDBOMB      "./img/explodedBomb.png"      // 11
#define TEXTURE_REMOVEDBOMB       "./img/removedBomb.png"       // 12
#define TEXTURE_1                "./img/1.png"                  // 1
#define TEXTURE_2                "./img/2.png"                  // 2
#define TEXTURE_3                "./img/3.png"                  // 3
#define TEXTURE_4                "./img/4.png"                  // 4
#define TEXTURE_5                "./img/5.png"                  // 5
#define TEXTURE_6                "./img/6.png"                  // 6
#define TEXTURE_7                "./img/7.png"                  // 7
#define TEXTURE_8                "./img/8.png"                  // 8

typedef int bool;
#define true 1
#define false 0

enum TEXTURES_NAME {NONE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, CELL, FLAG, EXPLODEDBOMB, REMOVEDBOMB};

typedef struct s_sprite
{
        sfSprite              *sprite;
        char                  *texture_name;
        sfTexture             *texture;
        sfVector2f            sprite_origin;
        sfVector2f            sprite_position;
        sfVector2f            sprite_scale;
}               t_sprite;

typedef struct		s_parameter_window
{
        const sfVideoMode                     *mode;
        sfRenderWindow          	*window;
        sfVector2u	             	w_size;
        sfEvent	                	event;
}			t_parameter_window;

typedef struct s_cell
{
        sfVector2u      coord;
        bool            isClicked;
        bool            isBomb;
        bool            isFlag;
        int             bombAround;
        t_sprite        sprite;
}               t_cell;


typedef struct s_demineur
{
        int                     time;
        int                     nBomb;

        sfVector2u      mapSize;       // MAX 36 par 64
        sfVector2u      w_size;
        t_cell           **map;

}               t_demineur;

int	hash(char *str);

//      MAP         //

void init_map(t_demineur *demineur);
void create_map(t_demineur *demineur);
void create_all_sprites(t_cell *);
void display_map(t_parameter_window *par_w, t_demineur *demineur);

//      SPRITES         //

void SetTexture_Sprite(t_sprite *sprite, char *textureParam);
void Draw_Sprite(t_parameter_window *par_w, t_sprite sprite, int position_x, int position_y);
t_sprite Create_Sprite(char *texture);

//      MINES           //

void setup_mines(t_demineur *);

//      EVENT           //

void event(t_parameter_window *par_w, t_demineur *demineur);
