#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "Utils.h"

struct Ball {
    void init();
    void update(float dt);
    void draw();
    void unload();

    Vector2 lastPos;
    Circle circle;
    const float friction{5.0f};
    const float bounciness{0.75f};
};

#endif
