#include <gtest/gtest.h>
#include <generic_mcts.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(GenericMCTS, select)
{
  const int states = 8;
  const int actions = 2;
  Generic_MCTS<states, actions> bob;
  EXPECT_EQ(5, 5);
}