#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#define BLACK 0
#define RED 1

#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include <string> 
namespace ft{

	template <typename T>
		struct node
	{
		typedef T value_type;
		typedef node* nodeptr;
		typedef node& noderef;
		typedef std::size_t color_type; //bool for sharper prog but diff for max_size

		public:
			nodeptr parent;
			nodeptr left;
			nodeptr right;
			color_type color;
			value_type data;

			node() : parent(NULL), left(NULL), right(NULL), color(BLACK)
			{}
			node(const value_type &val, bool color_ = BLACK, nodeptr parent_ = NULL, nodeptr left_ = NULL, nodeptr right_ = NULL) : parent(parent_), left(left_), right(right_), color(color_), data(val)
			{}
			node(const node& rhs) : parent(rhs.parent), left(rhs.left), right(rhs.right), color(rhs.color), data(rhs.data)
			{}
			~node()
			{}
			noderef operator=(const node& rhs)
			{
				if (*this == rhs)
					return *this;
				parent = rhs.parent;
				left = rhs.left;
				right = rhs.right;
				color = rhs.color;
				data = rhs.data;
				return *this;
			}
			bool operator==(const node& rhs)
			{
				return (data == rhs.data);
			}
	};

	template <typename T>
		bool operator<(const node<T>& lhs, const node<T>&rhs)
	{
		return (lhs.data <rhs.data);
	}

	template <typename T, class Compare, class Node = ft::node<T>, class Allocator = std::allocator<Node> >
		class rb_tree
	{

		public:

			typedef T                                           value_type;
			typedef Compare                                     value_compare;
			typedef Allocator                                   allocator_type;
			typedef Node                                        node_type;
			typedef typename allocator_type::reference          reference;
			typedef typename allocator_type::const_reference    const_reference;
			typedef typename allocator_type::pointer            pointer;
			typedef typename allocator_type::const_pointer      const_pointer;
			typedef typename allocator_type::difference_type    difference_type;
			typedef typename allocator_type::size_type          size_type;
	
			rb_tree(value_compare const& cmp = value_compare()) :
				_cmp(cmp)
			{
				_end = _node_alloc.allocate(1);
				_node_alloc.construct(_end, node_type());
				_root = _end;
			}
	
			~rb_tree() {}
	
			pointer		min(pointer s) const
			{
				if (s == NULL || s == _end)
					return _end;
				for ( ; s->left != _end; s = s->left);
				return s;
			}
	
			pointer		min() const { return min(_root); }
	
			pointer		max(pointer s) const
			{
				if (s == NULL || s == _end)
					return _end;
				for ( ; s->right != _end; s = s->right);
				return s;
			}
	
			pointer		max() const { return max(_root); }
	
			size_type	size(pointer s) const
			{
				if (s == _end)
					return 0;
				return size(s->right) + size(s->left) + 1;
			}
	
			size_type	size()                        const { return size(_root); }
			size_type	max_size()                    const { return _node_alloc.max_size(); }
			pointer		search(const value_type& key) const { return __search_wrapper(_root, key); }
	
			pointer		successor(pointer s) const
			{
				if (s->right != _end)
					return min(s->right);
				if (s->parent == NULL || s == max())
					return _end;
	
				pointer	tmp = s->parent;
				while (tmp != _end && s == tmp->right)
				{
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}
	
			pointer		predecessor(pointer s) const
			{
				if (s->left != _end)
					return max(s->left);
				if (s->parent == NULL || s == min())
					return _end;
	
				pointer	tmp = s->parent;
				while (tmp != _end && s == tmp->left)
				{
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}
	
			bool	insert(const value_type& key)
			{
				pointer	y = NULL;
				pointer	x = _root;
	
				pointer	s = _node_alloc.allocate(1);
				_node_alloc.construct(s, node_type(key, RED, NULL, _end, _end));
	
				while (x != _end)
				{
					y = x;
					if (_cmp(s->data, x->data))
						x = x->left;
					else if (_cmp(x->data, s->data))
						x = x->right;
					else
					{
						_node_alloc.destroy(s);
						_node_alloc.deallocate(s, 1);
						return false;
					}
				}
	
				s->parent = y;
				if (y == NULL)
					_root = s;
				else if (_cmp(s->data, y->data))
					y->left = s;
				else
					y->right = s;
	
				if (s->parent == NULL)
				{
					s->color = BLACK;
					return true;
				}
	
				if (s->parent->parent == NULL)
					return true;
	
				_fix_insertion(s);
				return true;
			}
	
			pointer		get_root() const { return _root; }
			pointer		get_end() const { return _end; }
			const_pointer		get_cend() const { return _end; }
	
			bool	delete_node(const value_type& key)
			{ return __delete_node_wrapper(_root, key); }
	
			void		destroy()
			{
				_destroy(_root);
				_root = _end;
			}
	
			void		destroy_end()
			{
				_node_alloc.destroy(_end);
				_node_alloc.deallocate(_end, 1);
			}
	
			pointer		lower_bound(const value_type& v) const
			{
				pointer	p = min();
	
				for ( ; p != _end; p = successor(p))
				{
					if (!_cmp(p->data, v))
						break ;
				}
				return p;
			}
	
			pointer		upper_bound(const value_type& v) const
			{
				pointer	p = min();
	
				for ( ; p != _end; p = successor(p))
				{
					if (_cmp(v, p->data))
						break ;
				}
				return p;
			}
	
			void		swap(rb_tree& ref)
			{
				pointer			tmp_root = _root;
				pointer			tmp_end = _end;
	
	
				_root = ref.get_root();
				_end = ref.get_end();
				ref._root = tmp_root;
				ref._end = tmp_end;
			}
	
	
		private:

			pointer		__search_wrapper(pointer node, const value_type key) const
			{
				//std::cout << "miaou" << std::endl;
				if (node == _end)
					return node;
				else if (_cmp(key, node->data))
					return __search_wrapper(node->left, key);
				else if (_cmp(node->data, key))
					return __search_wrapper(node->right, key);
				else
					return node;
			}
	
			void		_left_rotate(pointer s)
			{
				pointer	tmp = s->right;
	
				s->right = tmp->left;
				if (tmp->left != _end)
					tmp->left->parent = s;
				tmp->parent = s->parent;
				if (s->parent == NULL)
					_root = tmp;
				else if (s == s->parent->left)
					s->parent->left = tmp;
				else
					s->parent->right = tmp;
				tmp->left = s;
				s->parent = tmp;
			}
	
			void		_right_rotate(pointer x)
			{
				pointer	y = x->left;
	
				x->left = y->right;
				if (y->right != _end)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == NULL)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}
	
			void		_fix_insertion(pointer k)
			{
				pointer	u;
	
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								_right_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_left_rotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;
						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								_left_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_right_rotate(k->parent->parent);
						}
					}
					if (k == _root)
						break ;
				}
				_root->color = BLACK;
			}
	
			void		_fix_delete(pointer x)
			{
				pointer	s;
	
				while (x != _root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_left_rotate(x->parent);
							s = x->parent->right;
						}
	
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								_right_rotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							_left_rotate(x->parent);
							x = _root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							_right_rotate(x->parent);
							s = x->parent->left;
						}
	
						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								_left_rotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							_right_rotate(x->parent);
							x = _root;
						}
					}
				}
				x->color = BLACK;
			}
	
			void		_rb_transplant(pointer u, pointer v)
			{
				if (u->parent == NULL)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}
	
			bool	__delete_node_wrapper(pointer node, const value_type& key)
			{
				pointer	z = _end;
				pointer	x;
				pointer	y;
	
				while (node != _end)
				{
					if (_cmp(node->data, key))
						node = node->right;
					else if (_cmp(key, node->data))
						node = node->left;
					else
					{
						z = node;
						node = node->right;
					}
				}
	
				if (z == _end) // if the key doesn't exist
					return false;
	
				y = z;
				int	y_original_color = y->color;
				if (z->left == _end)
				{
					x = z->right;
					_rb_transplant(z, z->right);
				}
				else if (z->right == _end)
				{
					x = z->left;
					_rb_transplant(z, z->left);
				}
				else
				{
					y = min(z->right);
					y_original_color = y->color;
					x = y->right;
	
					if (y->parent == z)
						x->parent = y;
					else
					{
						_rb_transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					_rb_transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
	
				_node_alloc.destroy(z);
				_node_alloc.deallocate(z, 1);
	
				if (y_original_color == BLACK)
					_fix_delete(x);
				return true;
			}
	
			void		_destroy(pointer root)
			{
				if (root == _end)
					return ;
				_destroy(root->left);
				_destroy(root->right);
				_node_alloc.destroy(root);
				_node_alloc.deallocate(root, 1);
			}
	
		private:

			allocator_type _node_alloc;
			value_compare	_cmp;
			pointer			_root;
			pointer			_end;
	};
}
#endif
