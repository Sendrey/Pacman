#include "perso.h"
void deplace_pm(int map[27][25], SDL_Rect * pos, int direction){
    switch(direction){
        case(HAUT):
        if(map[pos->y-1][pos->x]==1)
        break;
        if(map[pos->y-1][pos->x]==0||map[pos->y-1][pos->x]==5){
        map[pos->y-1][pos->x]=99;}
        pos->y--;
        
        break;

        case(BAS):
        if(map[pos->y+1][pos->x]==1)
        break;
        if(map[pos->y+1][pos->x]==0||map[pos->y+1][pos->x]==5)
        map[pos->y+1][pos->x]=99;
        pos->y++;
        break;
        
        case(GAUCHE):
        if (map[pos->y][pos->x]==3){
            pos->x=24;
            break;
        }
        
        if(map[pos->y][pos->x-1]==1)
        break;
        if(map[pos->y][pos->x-1]==0||map[pos->y][pos->x-1]==5)
        map[pos->y][pos->x-1]=99;
        pos->x--;
        break;
        case(DROITE):
        if (map[pos->y][pos->x]==4){
            pos->x=0;
            break;
        }

        if(map[pos->y][pos->x+1]==1)
        break;
        if(map[pos->y][pos->x+1]==0||map[pos->y][pos->x+1]==5)
        map[pos->y][pos->x+1]=99;
        pos->x++;
        break;
    }

 }