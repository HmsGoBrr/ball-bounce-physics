#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Ball.h"
#include "Hockey.h"

class Game {
public:
    static const int sWidth = 800;
    static const int sHeight = 600;

    static const int wallNums = 4;
    static Rectangle walls[wallNums];

    static Ball ball;
    static Hockey hockey;

    static void init();
    static void update(float dt);
    static void draw();
    static void unload();

    static void resolveBallCircleCollision(Circle& c1, Circle& c2);
private:
    static void elastic2DCollision(Circle& c1, Circle& c2, float v1, float v2, float d1, float d2, float cDir, float m1, float m2);
};

#endif