#include "raylib.h"

#include "Utils.h"
#include "Game.h"

const float gravity = 10.0f;
const float elasticity = 10.0f;

int main(void) {
    InitWindow(Game::sWidth, Game::sHeight, "Atari Clone");

    Game::init();

    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        Game::update(GetFrameTime());

        BeginDrawing();
        ClearBackground(GUNMETAL);

        Game::draw();

        EndDrawing();
    }

    Game::unload();

    CloseWindow();

    return 0;
}