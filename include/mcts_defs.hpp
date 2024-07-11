#ifndef MCTS_DEFS_HPP
#define MCTS_DEFS_HPP

// TODO: Make this an abstract base class??
// TODO: Probably needs templates

#include <stdint.h> // uint32_t
#include <Eigen/Dense>
#include <memory> // smart pointers
#include <vector>

namespace Mcts_defs
{
/**
 * @brief using this documentation for implementation now
 * @details https://theses.hal.science/tel-00927252/document
 */

// Forward declaration, this is for the circular dependency between
// Decision Nodes and Random Nodes
template <int N, int M, class Type = double>
struct RandomNode;

/**
 * @brief Node TODO:
 * @tparam N Number of states
 * @tparam M Number of actions
 * @tparam Type Type of integral variable
 * TODO: add noise or randomness?
 */
template <int N, int M, class Type = double>
struct DecisionNode
{
  /**
   * @brief Constructor
   */
  DecisionNode(RandomNode<N, M, Type>* parent = nullptr) : Parent(parent){};

  /**
   * @brief Destructor
   */
  ~DecisionNode() = default;

  /**
   * @brief Number of visits this node received
   */
  uint32_t Visits;

  /**
   * @brief The benefit from going to this node
   */
  double Reward;

  /**
   * @brief Easily accesible number of states
   */
  int Num_states = N;

  /**
   * @brief N x 1 matrix where N is the number of states
   */
  Eigen::Matrix<Type, N, 1> States;

  /**
   * @brief Raw pointer pointing at the parent
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  RandomNode<N, M, Type>* Parent;

  /**
   * @brief Vector of raw pointers to children
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  std::vector<RandomNode<N, M, Type>*> Children;
};

/**
 * @brief Node TODO:
 * @tparam N Number of states
 * @tparam M Number of actions
 * @tparam Type Type of integral variable
 */
template <int N, int M, class Type>
struct RandomNode
{
  /**
   * @brief Constructor
   */
  RandomNode(DecisionNode<N, M, Type>* parent = nullptr) : Parent(parent){};

  /**
   * @brief Destructor
   */
  ~RandomNode() = default;

  /**
   * @brief Number of visits this node received
   */
  uint32_t Visits;

  /**
   * @brief The benefit from going to this node
   */
  double Total_reward;

  /**
   * @brief Easily accesible number of actions
   */
  int Num_actions = M;

  /**
   * @brief N x 1 matrix where N is the number of actions
   */
  Eigen::Matrix<Type, M, 1> Actions;

  /**
   * @brief Raw pointer pointing at the parent
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  DecisionNode<N, M, Type>* Parent;

  /**
   * @brief Vector of raw pointers to children
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  std::vector<DecisionNode<N, M, Type>*> Children;
};

} // namespace Mcts_defs

#endif