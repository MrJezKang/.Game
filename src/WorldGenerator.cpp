#include "WorldGenerator.h"

void GenerateTestWorld(World& world) {
    world.objects.push_back({{300, 200, 200, 150}, {255, 255, 255, 255}});
    world.objects.push_back({{100, 100, 80, 80}, {255, 0, 0, 255}});
}
