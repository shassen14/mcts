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
  // Mcts_defs::Node<>* root = new Mcts_defs::Node<>(states, actions);
  std::shared_ptr<Mcts_defs::Node<>> root = std::make_shared<Mcts_defs::Node<>>(states, actions);
  // std::weak_ptr<Mcts_defs::Node<>> root = std::make_shared<Mcts_defs::Node<>>(states, actions);
  ;
  const int total_children = 3;

  // for (int i = 0; i < total_children; ++i)
  // {
  //   std::shared_ptr<Mcts_defs::Node<>> child = std::make_shared<Mcts_defs::Node<>>(i, i + 1, root);
  //   root->Children.push_back(std::move(child));
  // }

  // // iterate through to check if we can vary the states and actions
  // for (int i = 0; i < total_children; ++i)
  // {
  //   EXPECT_EQ(root->Children[i]->Num_states, i);
  //   EXPECT_EQ(root->Children[i]->States.size(), i);
  //   EXPECT_EQ(root->Children[i]->Num_actions, i + 1);
  //   EXPECT_EQ(root->Children[i]->Actions.size(), i + 1);
  //   EXPECT_EQ(root->Children[i]->Parent, root);
  // }

  // Check if parent is a nullptr
  EXPECT_EQ(nullptr, root->Parent);
}

TEST(MCTSDefs, Node_t)
{
  // Initalize
  const int states = 6;
  const int actions = 5;
  Mcts_defs::Node_t<states, actions> root;
  const int total_children = 0;
  int num_of_children = 0;

  for (int i = 0; i < total_children; ++i)
  {
    std::unique_ptr<Mcts_defs::Node_t<states, actions>> child =
        std::make_unique<Mcts_defs::Node_t<states, actions>>();
    root.Children.push_back(std::move(child));
  }

  while (!root.Children.empty())
  {
    num_of_children++;
    root.Children.pop_back();
  }

  // Check size, number of children, and parent is nullptr
  EXPECT_EQ(states, root.States.size());
  EXPECT_EQ(states, root.Num_states);
  EXPECT_EQ(actions, root.Actions.size());
  EXPECT_EQ(actions, root.Num_actions);
  EXPECT_EQ(total_children, num_of_children);
  EXPECT_TRUE(root.Parent == nullptr);
}

///////////////////////////////////////////////////////////////////////////////