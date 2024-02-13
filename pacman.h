#ifndef pacman_H_
#define pacman_H_
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "gestionGraphique.h"

#include "constante.h"
#include "carte.h"
#include "perso.h"
#include "ghost.h"


void play(SDL_Window* win,SDL_Renderer* ren);

void updateplateau(int vie,int * continuer,int map[27][25],SDL_Renderer* ren,SDL_Texture* direction_pm,SDL_Rect position_pm,SDL_Rect position_ghost_r,SDL_Rect position_ghost_ro,SDL_Rect position_ghost_j,SDL_Rect position_ghost_b,char chgt_direction,int direction_r,int direction_ro,int direction_b,int direction_j);






















#endif