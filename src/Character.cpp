#include "../include/Character.h"
#include "Constants.h"

Character::Character(const Vector2 _position) : position(_position) {
  movementSpeed = CHARACTER_DEFAULT_SPEED;
  frameTime = 0.1f;
  timer = 0.0f;
}

Vector2 Character::GetPosition() const { return position; }

void Character::SetPosition(const Vector2 &_position) { position = _position; }

float Character::GetMovementSpeed() const { return movementSpeed; }

void Character::SetMovementSpeed(const float &_movementSpeed) {
  movementSpeed = _movementSpeed;
}
