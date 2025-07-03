#include "../include/Player.h"
#include "raylib.h"

Player::Player(const Vector2 _position) : Character(_position) {
  playerTexture = LoadTexture("assets/playerSprites.png");

  frameWidth = (float)playerTexture.width / 3;
  frameHeight = (float)playerTexture.height / 4;

  frameRec = {0.f, 0.f, frameWidth, frameHeight};
  isMoving = false;
  direction = DOWN;
}

Player::~Player() { UnloadTexture(playerTexture); }

void Player::Draw() const {
  Rectangle destRec = {position.x, position.y, frameWidth * 2.f,
                       frameHeight * 2.f};

  Vector2 origin = {0.f, 0.f};
  float rotation = 0.0f;

  DrawTexturePro(playerTexture, frameRec, destRec, origin, rotation, WHITE);
}

void Player::Update(float delta) {
  InputState input = ReadInput();

  ApplyInput(input);
  UpdateAnimation(input, delta);
}

InputState Player::ReadInput() const {
  return InputState{.up = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP),
                    .down = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN),
                    .left = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT),
                    .right = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)};
}

void Player::ApplyInput(const InputState &input) {
  isMoving = false;

  if (input.up) {
    position.y -= movementSpeed;
    direction = UP;
    isMoving = true;
  }

  else if (input.down) {
    position.y += movementSpeed;
    direction = DOWN;
    isMoving = true;
  }

  else if (input.left) {
    position.x -= movementSpeed;
    direction = LEFT;
    isMoving = true;
  }

  else if (input.right) {
    position.x += movementSpeed;
    direction = RIGHT;
    isMoving = true;
  }
}

void Player::UpdateAnimation(const InputState &input, float delta) {
  if (isMoving) {
    timer += delta;

    if (timer >= frameTime) {
      timer = 0.0f;
      currentFrame = (currentFrame + 1) % 3;
    }
  } else {
    currentFrame = 0;
    timer = 0.0f;
  }

  frameRec.y = direction * frameHeight;
  frameRec.x = currentFrame * frameWidth;
}
