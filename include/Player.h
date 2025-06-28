/**
 * @file Player.h
 * @brief Clase que representa al jugador en el juego.
 * @author macasteglione
 * @date 2025-06-28
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Character.h"

class Player final : public Character {
public:
  explicit Player(Vector2 _position);

  ~Player() override = default;

  void Draw() const override;

  void Update() override;
};

#endif // !PLAYER_HEADER
