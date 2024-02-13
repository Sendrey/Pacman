#include "pacman.h"

void play(SDL_Window* win,SDL_Renderer* ren){
    
    SDL_Rect position,position_pm,position_ghost_r,position_ghost_ro,position_ghost_j,position_ghost_b;
    position_pm.x=5;
    position_pm.y=4;
    int vie = vie_depart;
    position_ghost_r.x=xdepfant;
    position_ghost_r.y=ydepfant;
    position_ghost_ro.x=xdepfant;
    position_ghost_ro.y=ydepfant;
    position_ghost_j.x=xdepfant;
    position_ghost_j.y=ydepfant;
    position_ghost_b.x=xdepfant;
    position_ghost_b.y=ydepfant;
    int direction_b,direction_r,direction_ro,direction_j;
     
    direction_r=1;
    direction_ro=1;
    direction_j=1;
    direction_b=1;

    int multx, multy;
    SDL_Texture* pakuman_H = loadTexture("image/pakuman_1.bmp", ren);
    SDL_Texture* pakuman_B = loadTexture("image/pakuman_3.bmp", ren);
    SDL_Texture* pakuman_G = loadTexture("image/pakuman_2.bmp", ren);
    SDL_Texture* pakuman_D = loadTexture("image/pakuman_0.bmp", ren);
    SDL_Texture* mur = loadTexture("image/wall.bmp", ren);
    SDL_Texture* fantome_rose_gauche = loadTexture("image/ghost2_2.bmp",  ren);
    SDL_Texture* fantome_rouge_gauche = loadTexture("image/ghost1_2.bmp", ren);
    SDL_Texture* fantome_bleu_gauche = loadTexture("image/ghost3_2.bmp",  ren);
    SDL_Texture* fantome_jaune_gauche = loadTexture("image/ghost4_2.bmp", ren);
    SDL_Texture* direction_pm = pakuman_H;
    char chgt_direction;
    position.x = position_pm.x * taille_bloc ;
    position.y = position_pm.y * taille_bloc ;
    
     int map[27][25] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 5, 0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 1, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 5, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 1},
        {3, 2, 2, 2, 2, 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 2, 2, 2, 4},
        {3, 2, 2, 2, 2, 2, 0, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 0, 2, 2, 2, 2, 2, 4},
        {1, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 1, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1},
        {1, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 5, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    

    
    
    
    int continuer = 2;
    char p = ' ';
    int timer;
    while(continuer == 2) {
        
        
        p=' ';
        timer=10;
        while (p==' '){
                p = processKeyboard();
                
          
                if (p=='h'){
                direction_pm = pakuman_H;
                chgt_direction= HAUT;
                }
                else if(p=='b'){
                chgt_direction= BAS;
                direction_pm = pakuman_B;
                }
                else if(p=='g'){
                direction_pm = pakuman_G;
                chgt_direction= GAUCHE;
                }
                else if(p=='d'){
                direction_pm = pakuman_D;
                chgt_direction= DROITE;
                }
                p='t';
                
        }
        deplace_pm(map,&position_pm,chgt_direction);
        deplace_fantome(map,&position_ghost_r,&direction_r,position_pm,&vie);
        deplace_fantome(map,&position_ghost_ro,&direction_ro,position_pm,&vie);
        deplace_fantome(map,&position_ghost_j,&direction_j,position_pm,&vie);
        deplace_fantome(map,&position_ghost_b,&direction_b,position_pm,&vie);

    
        

        if(vie==0){continuer=0;}
        updateplateau(vie,&continuer,map,ren,direction_pm,position_pm,position_ghost_r,position_ghost_ro,position_ghost_j,position_ghost_b,chgt_direction,direction_r,direction_ro,direction_b,direction_j);
            
        
            
        

    }
}


void updateplateau(int vie, int *continuer,int map[27][25],SDL_Renderer* ren,SDL_Texture* direction_pm,SDL_Rect position_pm,SDL_Rect position_ghost_r,SDL_Rect position_ghost_ro,SDL_Rect position_ghost_j,SDL_Rect position_ghost_b,char chgt_direction,int direction_r,int direction_ro,int direction_b,int direction_j){
    SDL_Rect position;
   
    SDL_Texture* mur = loadTexture("image/wall.bmp", ren);
    SDL_Texture* gum = loadTexture("image/gum.bmp", ren);
    SDL_Texture* biggum = loadTexture("image/bigGum.bmp", ren);
    SDL_Texture* fantome_rose_gauche = loadTexture("image/ghost2_2.bmp",  ren);
    SDL_Texture* fantome_rouge_gauche = loadTexture("image/ghost1_2.bmp", ren);
    SDL_Texture* fantome_bleu_gauche = loadTexture("image/ghost3_2.bmp",  ren);
    SDL_Texture* fantome_jaune_gauche = loadTexture("image/ghost4_2.bmp", ren);
    SDL_Texture* coeur = loadTexture("image/cherry.bmp",  ren);
    
    
    int affichage = 30;
    
    while(affichage!=0&&*continuer!=0){
        
        
        
        
        affichage=affichage-1;
        if (chgt_direction == HAUT&&map[position_pm.y-1][position_pm.x]!=1){
        position.x = position_pm.x * taille_bloc ;
        position.y = position_pm.y * taille_bloc +  affichage ;
        renderTexture(direction_pm, ren, position.x, position.y, taille_bloc, taille_bloc);
        
        
        }
        else if (chgt_direction == BAS&&map[position_pm.y+1][position_pm.x]!=1){
        position.x = position_pm.x * taille_bloc ;
        position.y = position_pm.y * taille_bloc -  affichage;
        renderTexture(direction_pm, ren, position.x, position.y, taille_bloc, taille_bloc);
        
        }
        else if (chgt_direction == DROITE&&map[position_pm.y][position_pm.x+1]!=1){
        position.x = position_pm.x * taille_bloc -  affichage;
        position.y = position_pm.y * taille_bloc ;
        renderTexture(direction_pm, ren, position.x, position.y, taille_bloc, taille_bloc);
        }
        else if (chgt_direction == GAUCHE&&map[position_pm.y][position_pm.x-1]!=1){
        position.x = position_pm.x * taille_bloc +  affichage;
        position.y = position_pm.y * taille_bloc ;
        renderTexture(direction_pm, ren, position.x, position.y, taille_bloc, taille_bloc);
        
        }
        else{
            position.x = position_pm.x * taille_bloc ;
            position.y = position_pm.y * taille_bloc ;
            renderTexture(direction_pm, ren, position.x, position.y, taille_bloc, taille_bloc);
            
        }
        int i=0,j=0;
        int count = 0;
        for(i=0;i<27;i++){
        for(j=0;j<25;j++){
            position.x = j *taille_bloc;
            position.y = i *taille_bloc;
            
            
            if (map[i][j]==1){
                renderTexture(mur, ren, position.x, position.y, taille_bloc, taille_bloc);
                

            }
            else if(map[i][j]==0){
                renderTexture(gum, ren, position.x, position.y, taille_bloc, taille_bloc);
                count++;
            }
            else if(map[i][j]==5){
                renderTexture(biggum, ren, position.x, position.y, taille_bloc, taille_bloc);

            }
           
        }
        
        }

    if(direction_r==10||direction_r==-10){
    position.x = position_ghost_r.x * taille_bloc  ;
    position.y = position_ghost_r.y * taille_bloc + direction_r * affichage*0.1;}
    else{
    position.x = position_ghost_r.x * taille_bloc + direction_r * affichage;
    position.y = position_ghost_r.y * taille_bloc ;}
    renderTexture(fantome_rouge_gauche,ren,position.x,position.y,taille_bloc,taille_bloc);
    
    if(direction_ro==10||direction_ro==-10){
    position.x = position_ghost_ro.x * taille_bloc  ;
    position.y = position_ghost_ro.y * taille_bloc + direction_ro * affichage*0.1;}
    else{
    position.x = position_ghost_ro.x * taille_bloc + direction_ro * affichage;
    position.y = position_ghost_ro.y * taille_bloc ;}
    renderTexture(fantome_rose_gauche,ren,position.x,position.y,taille_bloc,taille_bloc);
    
    if(direction_j==10||direction_j==-10){
    position.x = position_ghost_j.x * taille_bloc  ;
    position.y = position_ghost_j.y * taille_bloc + direction_j * affichage*0.1;}
    else{
    position.x = position_ghost_j.x * taille_bloc + direction_j * affichage;
    position.y = position_ghost_j.y * taille_bloc ;}
    renderTexture(fantome_jaune_gauche,ren,position.x,position.y,taille_bloc,taille_bloc);
    
    if(direction_b==10||direction_b==-10){
    position.x = position_ghost_b.x * taille_bloc  ;
    position.y = position_ghost_b.y * taille_bloc + direction_b * affichage*0.1;}
    else{
    position.x = position_ghost_b.x * taille_bloc + direction_b * affichage*1;
    position.y = position_ghost_b.y * taille_bloc ;}
    renderTexture(fantome_bleu_gauche,ren,position.x,position.y,taille_bloc,taille_bloc);
    for(i=0;i<vie;i++){
    renderTexture(coeur,ren,325 + 40*i,-7,40,40); }  
        SDL_Delay(delai);
        updateDisplay(ren);
        clearRenderer(ren);
    
    
        if (count==0||*continuer==0){
            *continuer=0;
        }
        else *continuer==2;
    

}}


