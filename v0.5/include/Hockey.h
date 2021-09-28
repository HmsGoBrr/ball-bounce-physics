#ifndef HOCKEY_H
#define HOCKEY_H

#include "raylib.h"
#include "Utils.h"

struct Hockey {
    void init();
    void update(float dt);
    void draw();
    void unload();
    Circle circle;
};

#endif
