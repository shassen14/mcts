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
 */
template <int N>
struct Node
{
  /**
   * @brief Default constructor
   */
  Node() = default;

  /**
   * @brief Default destructor
   */
  ~Node()
  {
    delete Parent;
  }

  /**
   * @brief Number of visits this node received
   */
  uint32_t Visits;

  /**
   * @brief The benefit from going to this node
   */
  double Reward;

  /**
   * @brief N x 1 matrix where N is the number of states
   */
  Eigen::Matrix<double, N, 1> State;

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

} // namespace Mcts_defs

#endif