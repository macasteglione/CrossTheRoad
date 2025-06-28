#include <gtest/gtest.h>

namespace {
  int GetMeaningInLife() {
    return 42;
  }
}

TEST(SampleTest, TrivialEquality) {
    EXPECT_EQ(GetMeaningInLife(), 42);
}

TEST(SampleTest, MoreEqualityTests) {
  ASSERT_EQ(GetMeaningInLife(), 42) << "Oh no!! Mistake";
  EXPECT_FLOAT_EQ(23.33F, 23.33F);
}
