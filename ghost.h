#ifndef ghost_H_
#define ghost_H_
#include <SDL2/SDL.h>
#include "constante.h"

void deplace_fantome(int map[27][25],SDL_Rect *pos,int * direction, SDL_Rect position_pm,int *vie);




#endif