#include "Car.h"
#include "Constants.h"

Car::Car(const Vector2 _position) : Character(_position) {
  characterTexture = LoadTexture(CAR_SPRITE_SHEET);

  frameWidth = (float)characterTexture.width / CAR_SPRITE_FRAMES;
  frameHeight = (float)characterTexture.height / CAR_SPRITE_ROWS;
  movementSpeed = 100.f;

  frameRec = {0.f, 0.f, frameWidth, frameHeight};
  isMoving = false;
  carDirection = GetRandomValue(0, 1) ? CAR_RIGHT : CAR_LEFT;
  spriteDirectionIndex =
      carDirection == CAR_RIGHT ? CAR_SPRITE_RIGHT : CAR_SPRITE_LEFT;
}

Car::~Car() { UnloadTexture(characterTexture); }

void Car::Draw() const {
  float textureSize = 1.f;
  Rectangle destRec = {position.x, position.y, frameWidth * textureSize,
                       frameHeight * textureSize};

  Vector2 origin = {0.f, 0.f};
  float rotation = 0.0f;

  DrawTexturePro(characterTexture, frameRec, destRec, origin, rotation, WHITE);
}

void Car::Update(float delta) {
  position.x += movementSpeed * delta * carDirection;

  UpdateAnimation(delta);
}

void Car::UpdateAnimation(float delta) {
  timer += delta;

  if (timer >= frameTime) {
    timer = 0.0f;
    currentFrame = (currentFrame + 1) % PLAYER_SPRITE_FRAMES;
  }

  frameRec.y = spriteDirectionIndex * frameHeight;
  frameRec.x = currentFrame * frameWidth;
}
