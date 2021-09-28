#include "Game.h"
#include "Utils.h"
#include <math.h>

Rectangle Game::walls[wallNums] = {
    { 0, 0, sWidth, 10 },
    { 0, sHeight - 10, sWidth, 10 },
    { 0, 10, 10, sHeight - 20 },
    { sWidth - 10, 10, 10, sHeight - 20 }
};

Ball Game::ball;
Hockey Game::hockey;

void Game::init() {
    SetMousePosition(Game::sWidth/2, 500);
    ball.init();
    hockey.init();
}

void Game::update(float dt) {
    ball.update(dt);
    hockey.update(dt);
}

void Game::draw() {
    for (int i = 0; i < wallNums; i++) {
        DrawRectangleRec(walls[i], INDIGODYE);
    }

    ball.draw();
    hockey.draw();
}

void Game::unload() {
    ball.unload();
    hockey.unload();
}

void Game::resolveBallCircleCollision(Circle& c1, Circle& c2) {
    const float d = sqrtf(powf(c2.x - c1.x, 2) + powf(c2.y - c1.y, 2));
    if (c1.radius + c2.radius >= d) {
        const float nx = (c2.x - c1.x) / d;
        const float ny = (c2.y - c1.y) / d;
        // const float p = 2*(c1.vx*nx + c1.vy*ny - c2.vx*nx + c2.vy*ny)/(1+1);

        const float touchDistFromC1 = (d * (c1.radius / (c1.radius + c2.radius)));
        const float contactX = c1.x + nx * touchDistFromC1;
        const float contactY = c1.y + ny * touchDistFromC1;

        c1.x = contactX - nx * c1.radius;
        c1.y = contactY - ny * c1.radius;

        // c1.vx = c1.vx - p * 1 * nx - p * 1 * nx;
        // c1.vy = c1.vy - p * 1 * ny - p * 1 * ny;

        const float v1 = sqrtf(c1.vx*c1.vx + c1.vy*c1.vy);
        const float v2 = sqrtf(c2.vx*c2.vx + c2.vy*c2.vy);

        const float d1 = atan2f(c1.vy, c1.vx);
        const float d2 = atan2f(c2.vy, c2.vx);
        const float cDir = atan2f(ny, nx);

        const float m1 = powf(c1.radius, 3);
        const float m2 = powf(c2.radius, 3);

        elastic2DCollision(c1, c2, v1, v2, d1, d2, cDir, m1, m2);
    }
}

void Game::elastic2DCollision(Circle& c1, Circle& c2, float v1, float v2, float d1, float d2, float cDir, float m1, float m2) {
    const float mm = m1 - m2;
    const float mmt = m1 + m2;
    const float v1s = v1*sinf(d1 - cDir);

    const float cp = cosf(cDir);
    const float sp = sinf(cDir);
    float cdp1 = v1 * cosf(d1 - cDir);
    float cdp2 = v2 * cosf(d2 - cDir);
    const float cpp = cosf(cDir + PI/2);
    const float spp = sinf(cDir + PI/2);

    const float t = (cdp1*mm + 2*m2*cdp2) / mmt;
    c1.vx = t*cp + v1s*cpp;
    c1.vy = t*sp + v1s*spp;
    cDir += PI;
}
