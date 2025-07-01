#include <cstdlib>
#include <raylib.h>
#include "../include/Constants.h"
#include "Player.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cross The Road");
  SetTargetFPS(TARGET_FPS);

  Player *player = new Player(Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f});

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      player->Update();
      player->Draw();
    }
    EndDrawing();
  }

  CloseWindow();
  exit(EXIT_SUCCESS);
}
