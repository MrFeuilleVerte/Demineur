/**
 * @Author: vincent
 * @Date:   2018-03-08T15:30:28+01:00
 * @Filename: sprite.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T19:52:23+01:00
 */

 #include "demineur.h"

 void SetTexture_Sprite(t_sprite sprite, char *textureParam)
 {
     sprite.texture_name = textureParam;
     sprite.texture = sfTexture_createFromFile(sprite.texture_name, NULL);
     sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
 }

 void Draw_Sprite(t_parameter_window *par_w, t_sprite sprite, int position_x, int position_y)
 {
     sprite.sprite_position.x = position_x;
     sprite.sprite_position.y = position_y;

     sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
     sfSprite_setOrigin(sprite.sprite, sprite.sprite_origin);
     sfSprite_setPosition(sprite.sprite, sprite.sprite_position);
     sfSprite_setScale(sprite.sprite, sprite.sprite_scale);
     sfRenderWindow_drawSprite(par_w->window, sprite.sprite, NULL);
 }

 t_sprite Create_Sprite(char *texture)
 {
     t_sprite s_sprite;

     s_sprite.sprite = sfSprite_create();
     s_sprite.texture_name = strdup(texture);
     s_sprite.texture = sfTexture_createFromFile(s_sprite.texture_name, NULL);

     s_sprite.sprite_origin.x = 0;
     s_sprite.sprite_origin.y = 0;

     s_sprite.sprite_position.x = 0;
     s_sprite.sprite_position.y = 0;

     s_sprite.sprite_scale.x = 1;
     s_sprite.sprite_scale.y = 1;

     return (s_sprite);
 }
