#include "../include/Car.h"
#include "raylib.h"

Car::Car(const Vector2 _position) : Character(_position) {
  /*
    playerTexture = LoadTexture(CAR_SPRITE_SHEET);

    frameWidth = (float)playerTexture.width / CAR_SPRITE_FRAMES;
    frameHeight = (float)playerTexture.height / CAR_SPRITE_ROWS;

    frameRec = {0.f, 0.f, frameWidth, frameHeight};
    isMoving = false;
    direction = DOWN;
  */
}

Car::~Car() {
  // UnloadTexture(playerTexture);
}

// Por ahora hardcodeado
void Car::Draw() const { DrawCircleV(position, 10, RED); }

void Car::Update(float delta) { return; }
