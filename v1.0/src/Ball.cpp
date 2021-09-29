#include "Ball.h"
#include "Game.h"
#include "Utils.h"
#include "raymath.h"

void Ball::init() {
    circle = { Game::sWidth/2.0f, 200, 0, 700, 15.0f };
}

void Ball::update(float dt) {
    lastPos = { circle.x, circle.y };

    if ((circle.x + circle.vx*dt) < 10 || (circle.x + circle.vx*dt) > Game::sWidth-10)
        circle.vx = circle.vx*-1*bounciness;
    if ((circle.y + circle.vy*dt) < 10 || (circle.y + circle.vy*dt) > Game::sHeight-10)
        circle.vy = circle.vy*-1*bounciness;
    
    if (Game::cannon.loaded && (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        circle.x = Game::cannon.pos.x + cosf(Game::cannon.rot*DEG2RAD)*50;
        circle.y = Game::cannon.pos.y + sinf(Game::cannon.rot*DEG2RAD)*50;
        circle.vx = Game::cannon.force*cosf(Game::cannon.rot*DEG2RAD);
        circle.vy = Game::cannon.force*sinf(Game::cannon.rot*DEG2RAD);
        Game::cannon.loaded = false;
    }

    if (circle.vx > 0) circle.vx -= friction;
    if (circle.vx < 0) circle.vx += friction;
    if (circle.vy > 0) circle.vy -= friction;
    if (circle.vy < 0) circle.vy += friction;

    circle.vx = Clamp(circle.vx, -1000, 1000);
    circle.vy = Clamp(circle.vy, -1000, 1000);

    circle.x += circle.vx * dt;
    circle.y += circle.vy * dt;

    if (Game::cannon.loaded) {
        circle.x = Game::cannon.pos.x;
        circle.y = Game::cannon.pos.y;
    }
}

void Ball::draw() {
    DrawCircle(circle.x, circle.y, 15, CAROLINABLUE);
}

void Ball::unload() {
    // TODO: unload tings
}
