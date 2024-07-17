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
  Mcts_defs::DecisionNode<> root(states);

  for (int i = 0; i < total_children; ++i)
  {
    // Moving the ownership to root for the pointer object
    auto child = std::make_unique<Mcts_defs::RandomNode<>>(actions, &root);
    root.Children.push_back(std::move(child));

    // TODO: Delete. Old way
    // Mcts_defs::RandomNode<> child(actions, &root);
    // root.Children.push_back(&child);
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
  Mcts_defs::RandomNode<> root(actions);

  for (int i = 0; i < total_children; ++i)
  {
    // Moving the ownership to root for the pointer object

    auto child = std::make_unique<Mcts_defs::DecisionNode<>>(states, &root);
    root.Children.push_back(std::move(child));

    // TODO: Delete. Old way
    // Mcts_defs::DecisionNode<> child(states, &root);
    // root.Children.push_back(&child);
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

TEST(MCTSDefs, ActionSampler)
{
  Eigen::Matrix<double, Eigen::Dynamic, 1> actions{{1}, {2}, {3}};
  Eigen::Matrix<double, Eigen::Dynamic, 1> lower_bounds{{-10}, {-5}, {-8}};
  Eigen::Matrix<double, Eigen::Dynamic, 1> upper_bounds{{4}, {30}, {10}};

  auto answer = Mcts_defs::Action_sampler(actions, lower_bounds, upper_bounds);

  EXPECT_TRUE(answer.empty());
}

///////////////////////////////////////////////////////////////////////////////