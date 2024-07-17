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

template <class Type>
using VectorTD = Eigen::Matrix<Type, Eigen::Dynamic, 1>;

/**
 * @brief using this documentation for implementation now
 * @details https://theses.hal.science/tel-00927252/document
 */

// Forward declaration, this is for the circular dependency between
// Decision Nodes and Random Nodes
template <class Type = double>
struct RandomNode;

// template <int N, int M, class Type = double>
// struct DecisionNode;

// using index_and_random = std::pair<size_t, RandomNode>

/**
 * @brief Node TODO:
 * @tparam N Number of states
 * @tparam M Number of actions
 * @tparam Type Type of integral variable
 * TODO: add noise or randomness?
 */
template <class Type = double>
struct DecisionNode
{
  /**
   * @brief Constructor
   */
  DecisionNode(const int num_states, RandomNode<Type>* parent = nullptr)
      : Visits(0), Reward(0), Num_states(num_states), Parent(parent)
  {
    States.setZero(num_states);
  };

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
  int Num_states;

  /**
   * @brief N x 1 matrix where N is the number of states
   */
  VectorTD<Type> States;

  /**
   * @brief Raw pointer pointing at the parent
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  RandomNode<Type>* Parent;

  /**
   * @brief Vector of raw pointers to children
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome TODO:
   */
  std::vector<std::unique_ptr<RandomNode<Type>>> Children;
};

/**
 * @brief Node TODO:
 * @tparam N Number of states
 * @tparam M Number of actions
 * @tparam Type Type of integral variable
 */
template <class Type>
struct RandomNode
{
  /**
   * @brief Constructor
   */
  RandomNode(const int num_actions, DecisionNode<Type>* parent = nullptr)
      : Visits(0), Total_reward(0), Num_actions(num_actions), Parent(parent)
  {
    Actions.setZero(num_actions);
  };

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
  int Num_actions;

  /**
   * @brief N x 1 matrix where N is the number of actions
   */
  VectorTD<Type> Actions;

  /**
   * @brief Raw pointer pointing at the parent
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome
   */
  DecisionNode<Type>* Parent;

  /**
   * @brief Vector of raw pointers to children
   * @details Design choice for a raw pointer because ownership and creating
   * these nodes beforehand to connect them together is cumbersome TODO:
   */
  std::vector<std::unique_ptr<DecisionNode<Type>>> Children;
};

/**
 * @brief 
 * @details 
 * @tparam Type
 * @param node
 * 
 */
template <class Type>
std::vector<VectorTD<Type>, Eigen::aligned_allocator<VectorTD<Type>>>
Action_sampler(const VectorTD<Type>& previous_action,
               const VectorTD<Type>& lower_bounds,
               const VectorTD<Type>& upper_bounds,
               const VectorTD<Type>& rate_limits)
{
  std::vector<VectorTD<Type>, Eigen::aligned_allocator<VectorTD<Type>>> output;

  return output;
};

// template <class D1>
// Eigen::Matrix<typename D1::Scalar, D1::RowsAtCompileTime, 1>
// // std::vector<Eigen::Matrix<typename D1::Scalar, D1::RowsAtCompileTime, 1>>
// Action_sampler(const Eigen::MatrixBase<D1>& node,
//                const Eigen::MatrixBase<D1>& lower_limits,
//                const Eigen::MatrixBase<D1>& upper_limits)
// {
//   Eigen::MatrixBase<D1> output;

//   // std::vector<Eigen::MatrixBase<D1>, Eigen::aligned_allocator<Eigen::MatrixBase<D1>>> output;
//   return output;
// };

} // namespace Mcts_defs

#endif