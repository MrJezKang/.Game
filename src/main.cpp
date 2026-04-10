#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>

//default Windowed Screen Size
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int argc, char* argv[]){

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    //Window creation
    SDL_Window* window = SDL_CreateWindow(
        "SDL Tutorial", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );

    if(window == NULL){
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    //Renderer creation
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, 
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == NULL) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }

    bool LoopActive = true;
    SDL_Event e;

    SDL_Rect box = {300, 200, 200, 150};

    //==============================================MAIN LOOP==============================================
    //==============================================THREAD 1===============================================
    while(LoopActive){

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                LoopActive = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the drawing color to black
        SDL_RenderClear(renderer); // Clear the screen with the current drawing color (default is black)

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &box);

        SDL_RenderPresent(renderer); // Render the current frame to the screen

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;

}