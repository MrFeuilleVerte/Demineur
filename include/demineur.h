/**
* @Author: vincent
* @Date:   2018-03-08T15:20:03+01:00
* @Filename: demineur.h
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T15:30:10+01:00
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <SFML/Graphics.h>

#define NB_TEXTURE      30
#define GAME_NAME       "SNAKE"
#define FRAME_RATE      60

#define ERROR           84

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
        const sfVideoMode               *mode;
        sfRenderWindow          	*window;
        sfVector2u	             	w_size;
        sfEvent	                	event;
}			t_parameter_window;

typedef struct s_demineur
{
        int             Time;
        int             N_Bombes;

        sfVector2u      Map_Size;

}               t_demineur;

int	hash(char *str);
