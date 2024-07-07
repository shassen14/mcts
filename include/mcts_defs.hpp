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
 * @brief Node TODO:
 * @tparam Type Type of integral variable
 * TODO: add noise or randomness?
 */
template <class Type = double>
struct Node
{
  /**
   * @brief Constructor to initialize the state and action as zero vectors
   * @param num_states Number of states evaluated at current timestep
   * @param num_actions Number of actions evaluated at current timestep
   * @param parent Node shared pointer which nullptr is the default value
   */
  Node(const int num_states, const int num_actions, const std::shared_ptr<Node> parent = nullptr)
      : Num_states(num_states), Num_actions(num_actions), Parent(parent)
  {
    States.setZero(num_states);
    Actions.setZero(num_actions);
  };

  /**
   * @brief Destructor
   */
  ~Node() = default;

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
   * @brief Easily accesible number of actions
   */
  int Num_actions;

  /**
   * @brief N x 1 matrix where N is the number of states
   */
  Eigen::Matrix<double, Eigen::Dynamic, 1> States;

  /**
   * @brief N x 1 matrix where M is the number of actions
   */
  Eigen::Matrix<double, Eigen::Dynamic, 1> Actions;

  /**
   * @brief Opted out for a weak_ptr to ensure for a more memory safe application
   * @details Design choice for smart pointer is not needing to manually delete
   * a raw pointer.
   */
  std::weak_ptr<Node> Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::shared_ptr<Node>> Children;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Node TODO:
 * @tparam N Number of states
 * @tparam M Number of actions
 * @tparam Type Type of integral variable
 * TODO: add noise or randomness?
 */
template <int N, int M, class Type = double>
struct Node_t
{
  /**
   * @brief Constructor
   */
  Node_t(const std::shared_ptr<Node_t> parent = nullptr) : Parent(parent){};

  /**
   * @brief Destructor
   */
  ~Node_t() = default;

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
   * @brief Easily accesible number of actions
   */
  int Num_actions = M;

  /**
   * @brief N x 1 matrix where N is the number of states
   */
  Eigen::Matrix<double, N, 1> States;

  /**
   * @brief N x 1 matrix where M is the number of actions
   */
  Eigen::Matrix<double, M, 1> Actions;

  /**
   * @brief Opted out for a weak_ptr to ensure for a more memory safe application
   * @details Design choice for smart pointer is not needing to manually delete
   * a raw pointer.
   */
  std::weak_ptr<Node_t> Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::unique_ptr<Node_t>> Children;
};

///////////////////////////////////////////////////////////////////////////////

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
  DecisionNode(const std::shared_ptr<RandomNode<N, M, Type>> parent = nullptr) : Parent(parent){};

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
  Eigen::Matrix<double, N, 1> States;

  /**
   * @brief Opted out for a weak_ptr to ensure for a more memory safe application
   * @details Design choice for smart pointer is not needing to manually delete
   * a raw pointer.
   */
  std::weak_ptr<RandomNode<N, M, Type>> Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::unique_ptr<RandomNode<N, M, Type>>> Children;
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
  RandomNode(const std::shared_ptr<DecisionNode<N, M, Type>> parent = nullptr) : Parent(parent){};

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
  double Reward;

  /**
   * @brief Easily accesible number of actions
   */
  int Num_actions = M;

  /**
   * @brief N x 1 matrix where N is the number of actions
   */
  Eigen::Matrix<double, M, 1> Actions;

  /**
   * @brief Opted out for a weak_ptr to ensure for a more memory safe application
   * @details Design choice for smart pointer is not needing to manually delete
   * a raw pointer.
   */
  std::weak_ptr<DecisionNode<N, M, Type>> Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::unique_ptr<DecisionNode<N, M, Type>>> Children;
};

} // namespace Mcts_defs

#endif