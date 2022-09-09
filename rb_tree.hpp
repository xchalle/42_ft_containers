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
  T* data;
  Node *parent;
  Node *left;
  Node *right;
  bool color;
};

template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
class rb_tree
{
	typedef Allocator allocator_type;
	typedef std::allocator<Node<Key> > node_allocator;
	typedef Node<key> *nodeptr;

	void rb_tree_init()
	{
		_NULL = ft::nullptr_a;
		_NULL->parent = ft::nullptr_a;
		_NULL->left = ft::nullptr_a;
		_NULL->right = ft::nullptr_a;
		_root = _node_alloc(1);
		_root->parent = ft::nullptr_a;
		_root->left = ft::nullptr_a;
		_root->right = ft::nullptr_a;

	}
	node_allocator _node_alloc;
	allocator_type _alloc;
	nodeptr _root;
	nodeptr _save;
	nodeptr _NULL;
}
}
#endif
