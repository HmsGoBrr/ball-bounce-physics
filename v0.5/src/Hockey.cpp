#include "Hockey.h"
#include "Game.h"
#include "Utils.h"

void Hockey::init() {
    circle = { Game::sWidth/2, Game::sHeight/2, 0, 0, 40.0f };
}

void Hockey::update(float dt) {
    circle.vx = (GetMouseX() - circle.x) * 10;
    circle.vy = (GetMouseY() - circle.y) * 10;

    circle.x += circle.vx * dt;
    circle.y += circle.vy * dt;
}

void Hockey::draw() {
    DrawCircle(circle.x, circle.y, circle.radius, INDIGODYE);
}

void Hockey::unload() {
    // TODO: unload sum vars
}
