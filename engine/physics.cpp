#include "instance.h"

void UpdatePhysics(Box& b) {
    if (!b.isDragging) {
        b.vy += 0.5f; // Gravity
        b.x += b.vx;
        b.y += b.vy;
        b.vx *= 0.95f; // Friction

        // Simple Floor Collision
        if (b.y + b.h > 550) {
            b.y = 550 - b.h;
            b.vy = 0;
        }
    }
}

void UpdatePhysics(Rect& r) {
    if (!r.isDragging) {
        r.vy += 0.5f; // Gravity
        r.x += r.vx;
        r.y += r.vy;
        r.vx *= 0.95f; // Friction

        // Simple Floor Collision
        if (r.y + r.h > 550) {
            r.y = 550 - r.h;
            r.vy = 0;
        }
    }
}