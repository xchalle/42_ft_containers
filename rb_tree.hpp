#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

// Implementing Red-Black Tree in C++

#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include <string> 
namespace ft{
template <typename T>
struct Node {
  T data;
  Node<T> *parent;
  Node<T> *left;
  Node<T> *right;
  bool color;
};
}
#endif
