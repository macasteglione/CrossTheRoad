/**
 * @file Car.h
 * @brief Clase que representa un coche en el juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef CAR_HEADER
#define CAR_HEADER

#include "Character.h"
#include "raylib.h"

class Car : public Character {
private:
  Direction direction;

public:
  explicit Car(Vector2 _position);
  ~Car() override;
  void Draw() const override;
  void Update(float delta) override;
};

#endif // !CAR_HEADER
