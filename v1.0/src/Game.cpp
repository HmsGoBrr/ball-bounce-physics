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
Cannon Game::cannon;

void Game::init() {
    SetMousePosition(Game::sWidth/2, 500);
    ball.init();
    cannon.init();
}

void Game::update(float dt) {
    ball.update(dt);
    cannon.update(dt);
}

void Game::draw() {
    for (int i = 0; i < wallNums; i++) {
        DrawRectangleRec(walls[i], INDIGODYE);
    }

    ball.draw();
    cannon.draw();
}

void Game::unload() {
    ball.unload();
    cannon.unload();
}
