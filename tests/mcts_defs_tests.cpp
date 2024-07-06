#include <gtest/gtest.h>
#include <mcts_defs.hpp>

TEST(test, dummy)
{
  EXPECT_TRUE(true);
}

///////////////////////////////////////////////////////////////////////////////

TEST(MCTSDefs, Node)
{
  // Initalize helper variables for calculations
  const int states = 6;
  const int actions = 5;
  Mcts_defs::Node<> node(states, actions);
  const int total_children = 12;

  // have the raw pointer point to nullptr
  node.Parent = nullptr;

  for (int i = 0; i < total_children; ++i)
  {
    std::unique_ptr<Mcts_defs::Node<>> child = std::make_unique<Mcts_defs::Node<>>(i, i + 1);
    node.Children.push_back(std::move(child));
  }

  // iterate through to check if we can vary the states and actions
  for (int i = 0; i < total_children; ++i)
  {
    EXPECT_EQ(node.Children[i]->Num_states, i);
    EXPECT_EQ(node.Children[i]->States.size(), i);
    EXPECT_EQ(node.Children[i]->Num_actions, i + 1);
    EXPECT_EQ(node.Children[i]->Actions.size(), i + 1);
  }

  // Check if parent is a nullptr
  EXPECT_EQ(nullptr, node.Parent);
}

TEST(MCTSDefs, Node_t)
{
  // Initalize
  const int states = 6;
  const int actions = 5;
  Mcts_defs::Node_t<states, actions> node;
  const int total_children = 12;
  int num_of_children = 0;

  for (int i = 0; i < total_children; ++i)
  {
    std::unique_ptr<Mcts_defs::Node_t<states, actions>> child =
        std::make_unique<Mcts_defs::Node_t<states, actions>>();
    node.Children.push_back(std::move(child));
  }

  while (!node.Children.empty())
  {
    num_of_children++;
    node.Children.pop_back();
  }

  // Check size, number of children, and parent is nullptr
  EXPECT_EQ(states, node.States.size());
  EXPECT_EQ(states, node.Num_states);
  EXPECT_EQ(actions, node.Actions.size());
  EXPECT_EQ(actions, node.Num_actions);
  EXPECT_EQ(total_children, num_of_children);
  EXPECT_EQ(nullptr, node.Parent);
}

///////////////////////////////////////////////////////////////////////////////