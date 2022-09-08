#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP


#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include <string> 
namespace ft{
template <typename T>
struct Node {
	typedef T value_type;
  T data;
  Node *parent;
  Node *left;
  Node *right;
  bool color;
};
}
#endif
