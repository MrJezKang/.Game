#ifndef INSTANCE_H
#define INSTANCE_H

#include <SDL2/SDL.h>


struct Entity {
    float x, y, w, h;
    float vx = 0, vy = 0;
    bool isDragging = false;
};
/*struct Box {
    float x = 400, y = 300, w = 50, h = 50;
    float vx = 0, vy = 0; //Variables
    bool isDragging = false;
};

struct Rect {
    float x = 0, y = 0, w = 100, h = 50;
    float vx = 0, vy = 0;
    bool isDragging = false;
};


void UpdatePhysics(Box& b);
void UpdatePhysics(Rect& r);
*/
#endif