#ifndef NODE_HPP
#define NODE_HPP

// TODO: Make this an abstract base class??
// TODO: Probably needs templates

#include <stdint.h> // uint32_t

struct Node {
  Node(){};

  /**
   * @brief number of visits this node received
   */
  uint32_t visits;

  /**
   * @brief TODO:
   */
  double reward;
};

#endif