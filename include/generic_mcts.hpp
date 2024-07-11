#ifndef GENERIC_MCTS_HPP
#define GENERIC_MCTS_HPP

#include <mcts.hpp>
#include <mcts_defs.hpp>

template <int N, int M, class Type = double>
class Generic_MCTS : public MCTS_base<N, M, Type>
{
public:
  /**
   * @brief Constructor
   * @param K TODO:
   */
  Generic_MCTS(const Type k)
  {
    m_k = k;
  };

  /**
   * @brief Destructor
   */
  ~Generic_MCTS() override = default;

private:
  /**
   * @brief Exploration parameter for the upper confidence bound applied to Trees 
   * TODO: rename variable and better description maybe?
   */
  Type m_k;

  /**
   * @brief TODO:
   */
  Mcts_defs::RandomNode<N, M, Type> select(const Mcts_defs::DecisionNode<N, M, Type>& node) override
  {
    Type max_reward = 0;
    size_t max_reward_i = 0;
    for (size_t i = 0; i < node.Children.size(); ++i)
    {
      if (node.Children[i]->Visits > 0)
      {
        Type equation = (node.Children[i]->Total_reward / node.Children[i]->Visits) +
                        (m_k * std::sqrt(std::log(node.Visits) / node.Children[i]->Visits));
        if (equation > max_reward)
        {
          max_reward = equation;
          max_reward_i = i;
        }
      }
    };

    return *node.Children[max_reward_i];
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