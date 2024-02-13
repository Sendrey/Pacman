#include "gestionGraphique.h"
#include <stdlib.h>
#include "pacman.h"
#include <SDL2/SDL_ttf.h>


int main(){
    initSDL();
    SDL_Window* win = createWindow("Pacman", 750, 810);
    SDL_Renderer* ren = createRenderer(win);
    SDL_Texture* image = loadTexture("menu.bmp", ren);
    renderTexture(image, ren, 0, 0, 800, 600);
    updateDisplay(ren);
    SDL_Event  event;
    
    int continuer = 1;
    while(continuer==1){
        
        
        
        
        
        
        
        SDL_WaitEvent(&event);
        
        switch(event.type){
        
        case SDL_QUIT:
            continuer=0;
            break;
        
        
        
        case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
            case SDLK_ESCAPE:
            continuer = 0;
            break;

            case SDLK_SPACE:
            clearRenderer(ren);
            
            play(win,ren);
            renderTexture(image, ren, 0, 0, 750, 810);
            updateDisplay(ren);
            
    
            break;


        }
        }
    }
    SDL_QUIT;




}
