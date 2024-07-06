#include <gtest/gtest.h>
#include <mcts_defs.hpp>
#include <test_utils.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(MCTSDefs, Node)
{
  // Initalize helper variables for calculations
  const int floor = 0;
  const int ceiling = 20;
  const int states = Test_utils::Random_int(floor, ceiling);
  const int actions = Test_utils::Random_int(floor, ceiling);
  Mcts_defs::Node<>* root = new Mcts_defs::Node<>(states, actions);
  const int total_children = 10;

  for (int i = 0; i < total_children; ++i)
  {
    std::shared_ptr<Mcts_defs::Node<>> child = std::make_shared<Mcts_defs::Node<>>(i, i + 1, root);
    root->Children.push_back(std::move(child));
  }

  // iterate through to check if we can vary the states and actions
  for (int i = 0; i < total_children; ++i)
  {
    EXPECT_EQ(root->Children[i]->Num_states, i);
    EXPECT_EQ(root->Children[i]->States.size(), i);
    EXPECT_EQ(root->Children[i]->Num_actions, i + 1);
    EXPECT_EQ(root->Children[i]->Actions.size(), i + 1);
    EXPECT_EQ(root->Children[i]->Parent, root);
  }

  // Check if parent is a nullptr
  EXPECT_EQ(root->Parent, nullptr);
  delete root;
}

///////////////////////////////////////////////////////////////////////////////

TEST(MCTSDefs, Node_t)
{
  /**
   * NOTE: This currently doesn't have any memory leaks.
   * TODO: Caveat is that the number of states and actions have to be consisitent when 
   * making the tree at compile time. Trying to figure out a way to work around this.
   */
  // Initalize number of states and actions
  const int states = 6;
  const int actions = 5;
  Mcts_defs::Node_t<states, actions>* root = new Mcts_defs::Node_t<states, actions>();
  const int total_children = 10;
  for (int i = 0; i < total_children; ++i)
  {
    std::unique_ptr<Mcts_defs::Node_t<states, actions>> child =
        std::make_unique<Mcts_defs::Node_t<states, actions>>(root);
    root->Children.push_back(std::move(child));
  }

  // // iterate through to check if we can vary the states and actions
  for (int i = 0; i < total_children; ++i)
  {
    EXPECT_EQ(root->Children[i]->Num_states, states);
    EXPECT_EQ(root->Children[i]->States.size(), states);
    EXPECT_EQ(root->Children[i]->Num_actions, actions);
    EXPECT_EQ(root->Children[i]->Actions.size(), actions);
    EXPECT_EQ(root->Children[i]->Parent, root);
  }

  // // Check size, number of children, and parent is nullptr
  EXPECT_EQ(states, root->States.size());
  EXPECT_EQ(states, root->Num_states);
  EXPECT_EQ(actions, root->Actions.size());
  EXPECT_EQ(actions, root->Num_actions);
  EXPECT_TRUE(root->Parent == nullptr);

  delete root;
}

///////////////////////////////////////////////////////////////////////////////