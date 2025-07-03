#include "../include/Constants.h"
#include "Car.h"
#include "Player.h"
#include <cstdlib>
#include <raylib.h>

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cross The Road");
  SetTargetFPS(TARGET_FPS);

  Player *player =
      new Player(Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f});
  Car *car = new Car(
      Vector2{SCREEN_WIDTH / 2.0f, 10}); // Posicion hardcodeada por el momento

  while (!WindowShouldClose()) {
    float delta = GetFrameTime();

    BeginDrawing();
    {
      ClearBackground(BLACK);
      player->Update(delta);
      player->Draw();

      car->Update(delta);
      car->Draw();
    }
    EndDrawing();
  }

  CloseWindow();
  exit(EXIT_SUCCESS);
}
