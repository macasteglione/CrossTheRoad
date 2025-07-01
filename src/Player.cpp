#include "../include/Player.h"
#include "../include/Constants.h"
#include "raylib.h"

Player::Player(const Vector2 _position) : Character(_position) {
  movementSpeed = PLAYER_MOVEMENT_SPEED;
}

void Player::Draw() const {
  DrawCircleV(position, 20.0f, BLUE);
}

void Player::Update() {
  SetControls();
}

void Player::ApplyInput(InputState &input) {
  if (input.up)
    position.y -= movementSpeed;

  if (input.down)
    position.y += movementSpeed;

  if (input.left)
    position.x -= movementSpeed;

  if (input.right)
    position.x += movementSpeed;
}

// Controles que en un futuro podrían ser configurables
void Player::SetControls() {
  InputState input = {
    .up = IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP),
    .down = IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN),
    .left = IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT),
    .right = IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)
  };

  ApplyInput(input);
}
