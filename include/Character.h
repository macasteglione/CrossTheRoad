/**
 * @file Character.h
 * @brief Clase base para representar un personaje en el juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef CHARACTER_HEADER
#define CHARACTER_HEADER

#include <raylib.h>

class Character {
protected:
  float movementSpeed = 5.f;
  Vector2 position;

public:
  explicit Character(Vector2 _position);

  virtual ~Character() = default;

  Vector2 GetPosition() const;

  void SetPosition(const Vector2 &_position);

  float GetMovementSpeed() const;

  void SetMovementSpeed(const float &_movementSpeed);

  virtual void Draw() const = 0;

  virtual void Update() = 0;
};

#endif // CHARACTER_HEADER
