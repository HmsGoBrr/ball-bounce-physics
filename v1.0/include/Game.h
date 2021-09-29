#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Ball.h"
#include "Cannon.h"

struct Game {
    static const int sWidth = 800;
    static const int sHeight = 600;

    static const int wallNums = 4;
    static Rectangle walls[wallNums];

    static Ball ball;
    static Cannon cannon;

    static void init();
    static void update(float dt);
    static void draw();
    static void unload();
};

#endif