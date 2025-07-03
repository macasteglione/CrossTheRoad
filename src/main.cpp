#include "../include/Constants.h"
#include "Player.h"
#include <cstdlib>
#include <raylib.h>

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cross The Road");
  SetTargetFPS(TARGET_FPS);

  Player *player =
      new Player(Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f});

  while (!WindowShouldClose()) {
    float delta = GetFrameTime();

    BeginDrawing();
    {
      ClearBackground(BLACK);
      player->Update(delta);
      player->Draw();
    }
    EndDrawing();
  }

  CloseWindow();
  exit(EXIT_SUCCESS);
}
