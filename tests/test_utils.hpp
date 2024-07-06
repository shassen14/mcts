#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <random>

namespace Test_utils
{
/**
 * TODO : probably need to be safer, and generalize 
 * int random_int(const int floor, const int ceiling) to take any type
 */
int Random_int(const int floor, const int ceiling)
{
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> random_int(floor, ceiling);
  return random_int(rng);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace Test_utils

#endif