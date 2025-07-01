/**
 * @file Player.h
 * @brief Clase que representa al jugador en el juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Character.h"

struct InputState {
  bool up;
  bool down;
  bool left;
  bool right;
};

class Player final : public Character {
private:
  InputState inputState;

  void SetControls();

public:
  explicit Player(Vector2 _position);

  ~Player() override = default;

  void Draw() const override;

  void Update() override;

  void ApplyInput(InputState &input);
};

#endif // !PLAYER_HEADER
