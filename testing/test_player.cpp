#include "../include/Constants.h"
#include "../include/Player.h"
#include <gtest/gtest.h>

TEST(PositionTest, GetPositionTest) {
  Vector2 pos = {1, 1};
  Player p(pos);

  EXPECT_FLOAT_EQ(p.GetPosition().x, pos.x);
  EXPECT_FLOAT_EQ(p.GetPosition().y, pos.y);
}

TEST(PositionTest, SetPositionTest) {
  Vector2 newPos = {2, 3};
  Player p(Vector2({1, 2}));
  p.SetPosition(newPos);

  EXPECT_FLOAT_EQ(p.GetPosition().x, newPos.x);
  EXPECT_FLOAT_EQ(p.GetPosition().y, newPos.y);
}

TEST(MovementTest, GetMovementSpeedTest) {
  Player p(Vector2({0, 0}));

  EXPECT_FLOAT_EQ(p.GetMovementSpeed(), CHARACTER_DEFAULT_SPEED);
}

TEST(MovementTest, SetMovementSpeedTest) {
  Player p(Vector2({0, 0}));
  float newSpeed = 10.f;
  p.SetMovementSpeed(newSpeed);

  EXPECT_FLOAT_EQ(p.GetMovementSpeed(), newSpeed);
}

TEST(ControlTest, KeyInputTest) {
  Vector2 pos = {10, 10};
  Player p(pos);

  InputState input = {.up = false, .down = false, .left = false, .right = true};
  p.ApplyInput(input);
  EXPECT_FLOAT_EQ(p.GetPosition().x, pos.x + p.GetMovementSpeed());

  input = {.up = true, .down = false, .left = false, .right = false};
  p.ApplyInput(input);
  EXPECT_FLOAT_EQ(p.GetPosition().y, pos.y - p.GetMovementSpeed());
}
