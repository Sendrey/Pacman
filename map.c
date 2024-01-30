#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Fonction pour afficher une image sur la fenêtre SDL
void afficherImage(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
    SDL_Rect destRect = { x, y, 32, 32 }; // Taille de chaque élément de la carte
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

int main() {
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 1, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Initialisation de SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Pacman Map", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Chargement des textures
    SDL_Surface* wallSurface = SDL_LoadBMP("wall.bmp");
    SDL_Texture* wallTexture = SDL_CreateTextureFromSurface(renderer, wallSurface);
    SDL_FreeSurface(wallSurface);

    SDL_Surface* gumSurface = SDL_LoadBMP("gum.bmp");
    SDL_Texture* gumTexture = SDL_CreateTextureFromSurface(renderer, gumSurface);
    SDL_FreeSurface(gumSurface);

    SDL_Surface* bigGumSurface = SDL_LoadBMP("bigGum.bmp");
    SDL_Texture* bigGumTexture = SDL_CreateTextureFromSurface(renderer, bigGumSurface);
    SDL_FreeSurface(bigGumSurface);

    // Afficher la carte
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int x = j * 32; // Position x de l'élément
            int y = i * 32; // Position y de l'élément

            if (map[i][j] == 1) {
                afficherImage(renderer, wallTexture, x, y);
            } else if (map[i][j] == 2) {
                afficherImage(renderer, gumTexture, x, y);
            } else if (map[i][j] == 3) {
                afficherImage(renderer, bigGumTexture, x, y);
            }
        }
    }

    // Rafraîchir l'affichage
    SDL_RenderPresent(renderer);

    // Attendre la fermeture de la fenêtre
    SDL_Event event;
    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) {
            break;
        }
    }

    // Libérer les ressources
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(gumTexture);
    SDL_DestroyTexture(bigGumTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

