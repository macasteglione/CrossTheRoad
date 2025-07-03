#include "../include/Constants.h"
#include "../include/Player.h"

Player::Player(const Vector2 _position) : Character(_position) {
  playerTexture = LoadTexture(PLAYER_SPRITE_SHEET);

  frameWidth = (float)playerTexture.width / PLAYER_SPRITE_FRAMES;
  frameHeight = (float)playerTexture.height / PLAYER_SPRITE_ROWS;

  frameRec = {0.f, 0.f, frameWidth, frameHeight};
  isMoving = false;
  spriteDirectionIndex = PLAYER_SPRITE_DOWN;
}

Player::~Player() { UnloadTexture(playerTexture); }

void Player::Draw() const {
  float textureSize = 2.f;
  Rectangle destRec = {position.x, position.y, frameWidth * textureSize,
                       frameHeight * textureSize};

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
    spriteDirectionIndex = PLAYER_SPRITE_UP;
    isMoving = true;
  }

  else if (input.left) {
    position.x -= movementSpeed;
    spriteDirectionIndex = PLAYER_SPRITE_LEFT;
    isMoving = true;
  }

  else if (input.right) {
    position.x += movementSpeed;
    spriteDirectionIndex = PLAYER_SPRITE_RIGHT;
    isMoving = true;
  }

  else if (input.down) {
    position.y += movementSpeed;
    spriteDirectionIndex = PLAYER_SPRITE_DOWN;
    isMoving = true;
  }
}

void Player::UpdateAnimation(const InputState &input, float delta) {
  if (isMoving) {
    timer += delta;

    if (timer >= frameTime) {
      timer = 0.0f;
      currentFrame = (currentFrame + 1) % PLAYER_SPRITE_FRAMES;
    }
  } else {
    currentFrame = 0;
    timer = 0.0f;
  }

  frameRec.y = spriteDirectionIndex * frameHeight;
  frameRec.x = currentFrame * frameWidth;
}
