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

/*template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
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
	add_node(Key val)
	{
		nodeptr node = _node_alloc.allocate(1);
		node->parent = ft::nullptr_a;
		node->color = 1;
		node->left = ft::nullptr_a;
		node->right = ft::nullptr_a;
		node->data = _alloc.allocate(1);
		_alloc.construct(&node->data, val);

		nodeptr y = ft::nullptr_a;
		nodeptr x = _root;

		while( x != ft::nullptr_a)
		{
			y = x;
			if (_comp(node->data, y->data))
				x = x->left;
			else
				x = x->right;
		}
		node->parent = y;
	}
	node_allocator _node_alloc;
	allocator_type _alloc;
	nodeptr _root;
	nodeptr _save;
	nodeptr _NULL;
}*/
}
#endif
