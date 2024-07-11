#include <gtest/gtest.h>
#include <generic_mcts.hpp>
#include <mcts_defs.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(GenericMCTS, select)
{
  const int states = 8;
  const int actions = 2;
  const int children = 10;
  double k = 10;
  Generic_MCTS<states, actions> bob(k);
  Mcts_defs::DecisionNode<states, actions> root;
  root.Visits = 20;

  for (int i = 0; i < children; ++i)
  {
    Mcts_defs::RandomNode<states, actions> child(&root);
    child.Visits = i + 1;
    child.Total_reward = 100;
    root.Children.push_back(&child);
  }

  // Mcts_defs::RandomNode<states, actions, double>
  auto answer = bob.Select(root);

  EXPECT_EQ(answer.Visits, root.Children[0]->Visits);
}