#include <gtest/gtest.h>
#include <mcts_defs.hpp>
#include <test_utils.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(MCTSDefs, DecisionNode)
{
  // Thinking of a specific problem where the user 8 states to keep track of,
  // position of 4 corners and two actions (velocity, steering angle)
  // Total children is 10 because simulating 10 differenct actions to take
  const int states = 8;
  const int actions = 2;
  const int total_children = 10;
  Mcts_defs::DecisionNode<states, actions> root;

  for (int i = 0; i < total_children; ++i)
  {
    Mcts_defs::RandomNode<states, actions> child(&root);
    root.Children.push_back(&child);
  }

  // iterate through to check if we can vary the states and actions
  for (int i = 0; i < total_children; ++i)
  {
    EXPECT_EQ(root.Children[i]->Num_actions, actions);
    EXPECT_EQ(root.Children[i]->Actions.size(), actions);
    EXPECT_EQ(root.Children[i]->Parent, &root);
  }

  // Check size, number of children, and parent is nullptr/invalid because
  // this is the root
  EXPECT_EQ(root.States.size(), states);
  EXPECT_EQ(root.Num_states, states);
  EXPECT_EQ(root.Parent, nullptr);
}

///////////////////////////////////////////////////////////////////////////////

TEST(MCTSDefs, ActionNode)
{
  // Thinking of a specific problem where the user 8 states to keep track of,
  // position of 4 corners and two actions (velocity, steering angle)
  // Total children is 1 because simulating a deterministic state
  const int states = 8;
  const int actions = 2;
  const int total_children = 1;
  Mcts_defs::RandomNode<states, actions> root;

  for (int i = 0; i < total_children; ++i)
  {
    Mcts_defs::DecisionNode<states, actions> child(&root);
    root.Children.push_back(&child);
    // // std::unique_ptr<Mcts_defs::Node_t<states, actions>>
    // auto child = std::make_unique<Mcts_defs::DecisionNode<states, actions>>(&root);
    // root.Children.push_back(std::move(child));
  }

  // iterate through to check if we can vary the states and actions
  for (int i = 0; i < total_children; ++i)
  {
    EXPECT_EQ(root.Children[i]->Num_states, states);
    EXPECT_EQ(root.Children[i]->States.size(), states);
    EXPECT_EQ(root.Children[i]->Parent, &root);
  }

  // Check size, number of children, and parent is nullptr/invalid because
  // this is the root
  EXPECT_EQ(root.Actions.size(), actions);
  EXPECT_EQ(root.Num_actions, actions);
  EXPECT_EQ(root.Parent, nullptr);
}

///////////////////////////////////////////////////////////////////////////////