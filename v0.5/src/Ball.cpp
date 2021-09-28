#include "Ball.h"
#include "Game.h"
#include "Utils.h"
#include "raymath.h"

void Ball::init() {
    circle = { Game::sWidth/2.0f, 200, 0, 0, 15.0f };
}

void Ball::update(float dt) {
    if ((circle.x + circle.vx*dt) < 10 || (circle.x + circle.vx*dt) > Game::sWidth-10) {
        circle.vx = circle.vx*-1 + 10;
    }
    if ((circle.y + circle.vy*dt) < 10 || (circle.y + circle.vy*dt) > Game::sHeight-10) {
        circle.vy = circle.vy*-1 + 10;
    }

    Game::resolveBallCircleCollision(circle, Game::hockey.circle);

    if (circle.vx > 0) circle.vx -= friction;
    if (circle.vx < 0) circle.vx += friction;
    if (circle.vy > 0) circle.vy -= friction;
    if (circle.vy < 0) circle.vy += friction;

    circle.vx = Clamp(circle.vx, -1000, 1000);
    circle.vy = Clamp(circle.vy, -1000, 1000);

    circle.x += circle.vx * dt;
    circle.y += circle.vy * dt;
}

void Ball::draw() {
    DrawCircle(circle.x, circle.y, 15, CAROLINABLUE);
}

void Ball::unload() {
    // TODO: unload tings
}
