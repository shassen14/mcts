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
   * @brief Constructor to initialize the state and action size
   * @param num_states Number of states evaluated at current timestep
   * @param num_actions Number of actions evaluated at current timestep
   * @param parent Node pointer which nullptr is the default value
   */
  Node(const int num_states, const int num_actions, Node* parent = nullptr)
      : Num_states(num_states), Num_actions(num_actions), Parent(std::move(parent))
  {
    States.resize(num_states, 1);
    Actions.resize(num_actions, 1);
  };

  /**
   * @brief Destructor
   */
  ~Node()
  {
    delete Parent;
  };

  /**
   * @brief Number of visits this node received
   */
  uint32_t Visits;

  /**
   * @brief The benefit from going to this node
   */
  double Reward;

  /**
   * @brief 
   */
  int Num_states;

  /**
   * @brief The benefit from going to this node
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
   * @brief Raw pointer to the parent node since no ownership is happening, just observation
   */
  Node* Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::unique_ptr<Node>> Children;
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
  Node_t() = default;

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
   * @brief 
   */
  int Num_states = N;

  /**
   * @brief The benefit from going to this node
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
   * @brief Raw pointer to the parent node since no ownership is happening, just observation
   */
  Node_t* Parent;

  /**
   * @brief Vector of unique ptrs to children since there should be one owner
   */
  std::vector<std::unique_ptr<Node_t>> Children;
};

} // namespace Mcts_defs

#endif