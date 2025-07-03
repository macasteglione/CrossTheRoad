#include "../include/Car.h"
#include "../include/Constants.h"
#include <gtest/gtest.h>

TEST(CarPositionTest, GetPositionTest) {
  Vector2 pos = {1, 1};
  Car c(pos);

  EXPECT_FLOAT_EQ(c.GetPosition().x, pos.x);
  EXPECT_FLOAT_EQ(c.GetPosition().y, pos.y);
}

TEST(CarPositionTest, SetPositionTest) {
  Vector2 newPos = {2, 3};
  Car c(Vector2({1, 2}));
  c.SetPosition(newPos);

  EXPECT_FLOAT_EQ(c.GetPosition().x, newPos.x);
  EXPECT_FLOAT_EQ(c.GetPosition().y, newPos.y);
}

TEST(CarMovementTest, GetMovementSpeedTest) {
  Car c(Vector2({0, 0}));

  EXPECT_FLOAT_EQ(c.GetMovementSpeed(), CHARACTER_DEFAULT_SPEED);
}

TEST(CarMovementTest, SetMovementSpeedTest) {
  Car c(Vector2({0, 0}));
  float newSpeed = 10.f;
  c.SetMovementSpeed(newSpeed);

  EXPECT_FLOAT_EQ(c.GetMovementSpeed(), newSpeed);
}
