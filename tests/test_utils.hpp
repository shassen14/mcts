#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <random>
#include <type_traits>

/**
 * @brief Generic way to accept type conditions
 * @details A template parameter pack which can accept multiple conditions
 */
template <typename... Cond>
using Requires = std::enable_if_t<std::conjunction_v<Cond...>, bool>;

/**
 * @brief Just helper functions that would make testing easier
 */
namespace Test_utils
{

/**
 * @brief Generate a random number depending on value type
 * NOTE: I wanted to template overload where we get to check if the
 * type is floating or int but C++ doesn't allow template function overload 
 * @tparam Type parameter data type where it is required to be a number (int, float, etc.)
 * @param floor Lowest number a random number can generate to
 * @param ceiling Highest number a random number can generate to
 * @return Type value in between floor and ceiling
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