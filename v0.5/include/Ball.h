#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "Utils.h"

struct Ball {
    void init();
    void update(float dt);
    void draw();
    void unload();

    Circle circle;
    const float friction{10.0f};
};

#endif
