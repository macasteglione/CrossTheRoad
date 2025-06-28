#include "../include/Character.h"

Character::Character(const Vector2 _position) : position(_position) {}

Vector2 Character::GetPosition() const {
    return position;
}

void Character::SetPosition(const Vector2 &_position) {
    position = _position;
}

float Character::GetMovementSpeed() const {
    return movementSpeed;
}

void Character::SetMovementSpeed(const float &_movementSpeed) {
    movementSpeed = _movementSpeed;
}
