#include <gtest/gtest.h>
#include <test_utils.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(TestUtils, RandomNumberInt)
{
  int floor = -100;
  int ceiling = -50;
  auto number = Test_utils::Random_number<int>(floor, ceiling);

  // lambda to check if a value is an integer
  auto is_int = [](const auto value) -> bool { return value == std::floor(value); };

  // tests for if the value is in between floor and ceiling,
  // also if it's an integer
  EXPECT_TRUE(number <= ceiling && number >= floor);
  EXPECT_TRUE(is_int(number));
}

///////////////////////////////////////////////////////////////////////////////

TEST(TestUtils, RandomNumberDouble)
{
  double floor = 10000;
  double ceiling = 40000;
  auto number = Test_utils::Random_number<double>(floor, ceiling);

  // lambda to check if a value is an integer
  // Not that elegant. Probably has an edge case.
  auto is_int = [](const auto value) -> bool { return value == std::floor(value); };

  // tests for if the value is in between floor and ceiling,
  // also if it's NOT an integer
  EXPECT_TRUE(number <= ceiling && number > floor);
  EXPECT_FALSE(is_int(number));
}

///////////////////////////////////////////////////////////////////////////////