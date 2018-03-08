/**
* @Author: vincent
* @Date:   2018-03-06T11:40:20+01:00
* @Filename: hash.c
 * @Last modified by:   vincent
 * @Last modified time: 2018-03-08T15:30:06+01:00
*/

#include "demineur.h"

int	hash(char *str)
{
    int   sm = 0;
    int   i = 0;

    while (str[i])
    {
        sm += str[i];
        i += 1;
    }
    return (sm % NB_TEXTURE);
}
