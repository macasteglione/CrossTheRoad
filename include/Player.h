/**
 * @file Player.h
 * @brief Clase que representa al jugador en el juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Character.h"
#include "raylib.h"

struct InputState {
  bool up;
  bool down;
  bool left;
  bool right;
};

class Player final : public Character {
private:
  InputState inputState;
  Direction direction;

  void UpdateAnimation(const InputState &input, float delta);
  InputState ReadInput() const;

public:
  explicit Player(Vector2 _position);
  ~Player() override;
  void Draw() const override;
  void Update(float delta) override;
  void ApplyInput(const InputState &input);
};

#endif // !PLAYER_HEADER
