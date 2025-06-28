#include <cstdlib>
#include <raylib.h>
#include "../include/Constants.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CrossTheRoad!");
  SetTargetFPS(TARGET_FPS);

  while (!WindowShouldClose()) {
    BeginDrawing();
    {
      ClearBackground(BLACK);
      DrawText("Hola Mundo!", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, WHITE);
    }
    EndDrawing();
  }

  CloseWindow();
  exit(EXIT_SUCCESS);
}
