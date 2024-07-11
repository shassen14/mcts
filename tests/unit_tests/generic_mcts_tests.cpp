#include <gtest/gtest.h>
#include <generic_mcts.hpp>
#include <mcts_defs.hpp>
#include <test_utils.hpp>

///////////////////////////////////////////////////////////////////////////////

TEST(GenericMCTS, select)
{
  // Parameters, lots of magic numbers but should be okay for testing
  const int floor = 1;
  const int ceiling = 20;
  const int states = Test_utils::Random_number<int>(floor, ceiling);
  const int actions = Test_utils::Random_number<int>(floor, ceiling);
  const int children = Test_utils::Random_number<int>(7, ceiling);
  const size_t max_child_index = Test_utils::Random_number<size_t>(0, 6);
  const int random_high_visits = Test_utils::Random_number<int>(20, 50);
  const int random_low_visits = Test_utils::Random_number<int>(0, 19);
  double k =
      Test_utils::Random_number<double>(static_cast<double>(floor), static_cast<double>(ceiling));

  // Istantiate objects
  Generic_MCTS<> bob(k);
  Mcts_defs::DecisionNode<> root(states);

  // Give Visits a random value for the root
  root.Visits = Test_utils::Random_number<uint32_t>(floor, ceiling);

  // Make nodes and push them back
  for (int i = 0; i < children; ++i)
  {
    auto child = std::make_unique<Mcts_defs::RandomNode<>>(actions, &root);
    child->Visits = Test_utils::Random_number<int>(20, 50);
    if (i == max_child_index)
    {
      child->Visits = random_low_visits;
    }
    child->Total_reward = 100;
    root.Children.push_back(std::move(child));
  }

  // Mcts_defs::RandomNode<double>&
  auto& answer = bob.Select(root);

  // Check if the memory addresses are the same.
  // If the memory addresses are the same, the visits should be the same as well
  EXPECT_EQ(&answer, root.Children[max_child_index].get());
  EXPECT_EQ(answer.Visits, root.Children[max_child_index]->Visits);
}