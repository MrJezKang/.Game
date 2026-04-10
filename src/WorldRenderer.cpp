#include "WorldRenderer.h"

void RenderWorld(SDL_Renderer* renderer, const World& world) {
    for (const WorldObject& object : world.objects) {
        SDL_SetRenderDrawColor(
            renderer,
            object.color.r,
            object.color.g,
            object.color.b,
            object.color.a
        );
        SDL_RenderFillRect(renderer, &object.rect);
    }
}
