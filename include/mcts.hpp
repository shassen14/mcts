#ifndef MCTS_HPP
#define MCTS_HPP

#include <mcts_defs.hpp>

/**
 * @brief Abstract base class?
 * TODO: looking at this now, it might be better to not make this templated
 * because what if we want to read from a yml file for the number of states, actions,
 * different models. Continue forward to implement not as cleanly.
 * Might need to change to eigen dynamic matrices because these requirements would
 * be given during runtime and not compile time
 */
template <class Type = double>
class MCTS_base
{
public:
  /**
   * @brief Destructor
   */
  virtual ~MCTS_base() = default;

  /**
   * @brief TODO: Change function name. suppose to be main algorithm
   * Maybe update? run? maybe not include in general?
   */
  void Main()
  {
    main();
  }

  /**
   * @brief TODO:
   */
  void Grow_tree()
  {
    grow_tree();
  }

  /**
   * @brief Selects an action from the current DecisionNode
   * @param node Decision Node where it has the state stored within the node 
   * and the children are Random Nodes where possible actions are stored
   * TODO: check if node is const or I'm editing the node itself, possibly pointer?
   * TODO: reference is nice because we will not have to do null checking
   * @return Chosen Random Node with a specific action taken
   */
  Mcts_defs::RandomNode<Type>& Select(const Mcts_defs::DecisionNode<Type>& node)
  {
    return select(node);
  }

  /**
   * @brief TODO:
   */
  void Evaluate()
  {
    evaluate();
  }

  /**
   * @brief TODO:
   */
  void Best_action()
  {
    best_action();
  }

  void selection();
  void expansion();
  void simulate();
  void back_propogate();

private:
  /**
   * @brief TODO:
   */
  virtual void grow_tree() = 0;

  /**
   * @brief Selects an action from the current DecisionNode
   * @param node Decision Node where it has the state stored within the node 
   * and the children are Random Nodes where possible actions are stored
   * TODO: check if node is const or I'm editing the node itself, possibly pointer?
   * TODO: reference is nice because we will not have to do null checking
   * @return Chosen Random Node with a specific action taken
   */
  virtual Mcts_defs::RandomNode<Type>& select(const Mcts_defs::DecisionNode<Type>& node) = 0;

  /**
   * @brief TODO:
   */
  virtual void evaluate() = 0;

  /**
   * @brief TODO:
   */
  virtual void best_action() = 0;

  /**
   * @brief TODO:
   */
  virtual void main() = 0;
};

#endif