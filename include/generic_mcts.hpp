#ifndef GENERIC_MCTS_HPP
#define GENERIC_MCTS_HPP

#include <mcts.hpp>
#include <mcts_defs.hpp>

template <class Type = double>
class Generic_MCTS : public MCTS_base<Type>
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
   * @brief Selects an action (Random Node) TODO:
   * @details TODO: Assumption is that there will always be an answer by the end of it.
   * This could possibly be a huge mistake. I might want to create an optional? what happens
   * if there is no children and need to add one? If null throw an error? maybe explore possible
   * actions to utilize and add a random node?
   * @param node Decision Node which holds the states and action children
   * @returns A reference to the Random Node where we would like to explore
   */
  Mcts_defs::RandomNode<Type>& select(const Mcts_defs::DecisionNode<Type>& node) override
  {
    // Initialize temporary variables to keep track of the child which yields
    // max reward
    Type max_reward = 0;
    Mcts_defs::RandomNode<Type>* output = nullptr;

    // Iterate through each child and choose the one with maximum reward to explore
    for (const auto& child : node.Children)
    {
      if (child->Visits > 0)
      {
        Type equation = (child->Total_reward / child->Visits) +
                        (m_k * std::sqrt(std::log(node.Visits) / child->Visits));
        if (equation > max_reward)
        {
          max_reward = equation;
          output = child.get();
        }
      }
      else
      {
        output = child.get();
        break;
      }
    };

    return *output;
  };

  /**
   * @brief TODO:
   */
  void evaluate() override{};

  /**
   * @brief TODO:
   */
  void grow_tree() override{};

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