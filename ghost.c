#include "ghost.h"

void deplace_fantome(int map[27][25],SDL_Rect *pos,int * direction,SDL_Rect position_pm,int * vie){
    int cont = 1;
    int alea;
    if (pos->x==position_pm.x&&pos->y==position_pm.y){
    *vie=*vie-1;
    
    pos->x=xdepfant;
    pos->y=ydepfant;
    }
   
    while(cont ==1){
        alea =rand()%3+1;
        if (*direction==1){
            if(alea==1 && map[pos->y][pos->x-1]!=1 && map[pos->y][pos->x-1]!=3 && map[pos->y][pos->x-1]!=4){
                pos->x--;
                *direction=1;
                cont=0;
                break;
            }
            else if(alea==2 && map[pos->y-1][pos->x]!=1&& map[pos->y-1][pos->x]!=3 && map[pos->y-1][pos->x]!=4){
                pos->y--;
                *direction=10;
                cont=0;
                break;
            }
            else if(alea==3 && map[pos->y+1][pos->x]!=1 && map[pos->y+1][pos->x]!=3 && map[pos->y+1][pos->x]!=4){
                pos->y++;
                *direction=-10;
                cont=0;
                break;
            }
        }
        if (*direction==10){
            if(alea==1 && map[pos->y][pos->x-1]!=1 && map[pos->y][pos->x-1]!=3 && map[pos->y][pos->x-1]!=4){
                pos->x--;
                *direction=1;
                cont=0;
                break;
            }
            else if(alea==2 && map[pos->y-1][pos->x]!=1 && map[pos->y-1][pos->x]!=3 && map[pos->y-1][pos->x]!=4){
                pos->y--;
                *direction=10;
                cont=0;
                break;
            }
            else if(alea==3 && map[pos->y][pos->x+1]!=1&& map[pos->y][pos->x+1]!=3 && map[pos->y][pos->x+1]!=4){
                pos->x++;
                *direction=-1;
                cont=0;
                break;
            }

        }
        if (*direction==-1){
            if(alea==1 && map[pos->y-1][pos->x]!=1 && map[pos->y-1][pos->x]!=3 && map[pos->y-1][pos->x]!=4){
                pos->y--;
                *direction=10;
                cont=0;
                break;
            }
            else if(alea==2 && map[pos->y][pos->x+1]!=1 && map[pos->y][pos->x+1]!=3 && map[pos->y][pos->x+1]!=4){
                pos->x++;
                *direction=-1;
                cont=0;
                break;
            }
            else if(alea==3 && map[pos->y+1][pos->x]!=1 && map[pos->y+1][pos->x]!=3 && map[pos->y+1][pos->x]!=4){
                pos->y++;
                *direction=-10;
                cont=0;
                break;
            }
        }
        if (*direction==-10){
            if(alea==1 && map[pos->y][pos->x-1]!=1 && map[pos->y][pos->x-1]!=3 && map[pos->y][pos->x-1]!=4){
                pos->x--;
                *direction=1;
                cont=0;
                break;
            }
            else if(alea==2 && map[pos->y][pos->x+1]!=1 && map[pos->y][pos->x+1]!=3 && map[pos->y][pos->x+1]!=4){
                pos->x++;
                *direction=-1;
                cont=0;
                break;
            }
            else if(alea==3 && map[pos->y+1][pos->x]!=1 && map[pos->y+1][pos->x]!=3 && map[pos->y+1][pos->x]!=4 ){
                pos->y++;
                *direction=-10;
                cont=0;
                break;
            }
        }
        
    }
    if (pos->x==position_pm.x&&pos->y==position_pm.y){
    *vie=*vie-1;
    
    pos->x=xdepfant;
    pos->y=ydepfant;
    }
}