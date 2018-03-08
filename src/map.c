/**
 * @Author: vincent
 * @Date:   2018-03-08T16:55:53+01:00
 * @Filename: map.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T16:56:40+01:00
 */

#include "demineur.h"

 void init_map(t_demineur *demineur)
 {
     int     x = 0;
     int     y = 0;

     while (y != demineur->mapSize.y)
     {
         while (x != demineur->mapSize.x)
         {
             demineur->map[y][x].coord.x = x;
             demineur->map[y][x].coord.y = y;
             demineur->map[y][x].isBomb = false;
             demineur->map[y][x].isFlag = false;
             demineur->map[y][x].bombAround = 0;
             ++x;
         }
         x = 0;
         ++y;
     }
 }

 void create_map(t_demineur *demineur)
 {
     int     u = 0;

     demineur->map = malloc(sizeof(t_cell) * (demineur->mapSize.x * demineur->mapSize.y));
     while (u != demineur->mapSize.y)
     {
         demineur->map[u] = malloc(sizeof(t_cell) * (demineur->mapSize.x + 1));
         ++u;
     }
     init_map(demineur);
 }
