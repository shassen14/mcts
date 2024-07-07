#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <random>
#include <type_traits>

/**
 * @brief Generic way to accept type conditions TODO: fill out
 */
template <typename... Cond>
using Requires = std::enable_if_t<std::conjunction_v<Cond...>, bool>;

namespace Test_utils
{

/**
 * @brief An attempt TODO: fill out
 */
template <class Type, Requires<std::is_arithmetic<Type>> = true>
Type Random_number(Type floor, Type ceiling)
{
  // Create device and random number generator using Mersenne Twister pseudo-random generator
  std::random_device dev;
  std::mt19937 rng(dev());

  // Check what type of number the input is to deduce which distribution to use
  if constexpr (std::is_integral<Type>::value)
  {
    return std::uniform_int_distribution<std::mt19937::result_type>(floor, ceiling)(rng);
  }
  else
  {
    return std::uniform_real_distribution<Type>(floor, ceiling)(rng);
  }
}

} // namespace Test_utils

#endif