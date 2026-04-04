#include <SDL2/SDL.h>
#include "instance.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("Phase: Beta00", 100, 100, 800, 600, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    Box player;
    Rect Rectangle;
    bool running = true;
    SDL_Event ev;

    while (running) {
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) running = false;
            
            // Dev Mode: Mouse Drag
            if (ev.type == SDL_MOUSEBUTTONDOWN) {
                int mx, my; SDL_GetMouseState(&mx, &my);
                if (mx > player.x && mx < player.x + player.w && my > player.y && my < player.y + player.h)
                    player.isDragging = true;
                if (mx > Rectangle.x && mx < Rectangle.x + Rectangle.w && my > Rectangle.y && my < Rectangle.y + Rectangle.h)
                    Rectangle.isDragging = true;
            }
            if (ev.type == SDL_MOUSEBUTTONUP) {
                player.isDragging = false;
                Rectangle.isDragging = false;
            }
        }

        if (Rectangle.isDragging) {
            int mx, my; SDL_GetMouseState(&mx, &my);
            Rectangle.x = mx - Rectangle.w / 2;
            Rectangle.y = my - Rectangle.h / 2;
        }
        if (player.isDragging) {
            int mx, my; SDL_GetMouseState(&mx, &my);
            player.x = mx - player.w / 2;
            player.y = my - player.h / 2;
        }

        // WASD Movement
        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_A]) player.vx = -5;
        if (state[SDL_SCANCODE_D]) player.vx = 5;

        UpdatePhysics(player);
        UpdatePhysics(Rectangle);

        SDL_SetRenderDrawColor(ren, 20, 20, 20, 255); // Background
        SDL_RenderClear(ren);
        
        SDL_Rect r = {(int)player.x, (int)player.y, (int)player.w, (int)player.h};
        SDL_SetRenderDrawColor(ren, 0, 255, 0, 255); // Player Box
        SDL_RenderDrawRect(ren, &r);

        SDL_Rect rect = {(int)Rectangle.x, (int)Rectangle.y, (int)Rectangle.w, (int)Rectangle.h};
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255); // Rectangle Box
        SDL_RenderDrawRect(ren, &rect);
        
        SDL_RenderPresent(ren);
        SDL_Delay(16); // ~60FPS
    }
    return 0;
}