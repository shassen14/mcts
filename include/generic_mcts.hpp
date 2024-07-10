#ifndef GENERIC_MCTS_HPP
#define GENERIC_MCTS_HPP

#include <mcts.hpp>
#include <mcts_defs.hpp>

template <int N, int M, class Type = double>
class Generic_MCTS : public MCTS_base<N, M, Type>
{
public:
  /**
   * @brief Destructor
   */
  ~Generic_MCTS() override = default;

private:
  /**
   * @brief TODO:
   */
  Mcts_defs::RandomNode<N, M, Type> select(Mcts_defs::DecisionNode<N, M, Type>& node) override
  {
    Type max_reward = 0;
    size_t max_reward_i = 0;
    for (size_t i = 0; i < node.Children.size(); ++i)
    {
      if (node.Children[i]->Visits > 0)
      {
        Type equation = node.Children[i]->Total_reward;
        std::max(max_reward, equation);
      }
    };
    return Mcts_defs::RandomNode<N, M, Type>();
  };

  /**
   * @brief TODO:
   */
  void grow_tree() override{};

  /**
   * @brief TODO:
   */
  void evaluate() override{};

  /**
   * @brief TODO:
   */
  void best_action() override{};

  /**
   * @brief TODO:
   */
  void main() override{};
};

#endif