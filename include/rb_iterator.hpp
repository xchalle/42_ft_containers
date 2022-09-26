#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "rb_tree.hpp"
#include <iostream>

namespace ft{

	template < typename Node, class T>
		class bidirectional_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef Node *nodeptr;
			typedef Node &noderef;
			typedef Node node;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
			
			bidirectional_iterator() : _node(ft::nullptr_), _end(ft::nullptr_), _root(ft::nullptr_)
			{}
			
			bidirectional_iterator(const nodeptr _ptr, const nodeptr end, const nodeptr root) : _node(_ptr), _end(end), _root(root)
			{}
			
			bidirectional_iterator(const bidirectional_iterator &rhs) /*: _node(rhs._node), _end(rhs._end), _root(rhs._root)*/
			{
				*this = rhs;
			}
			
			bidirectional_iterator& operator=(const bidirectional_iterator &rhs)
			{
				_node = rhs._node;
				_end = rhs._end;
				_root = rhs._root;
				return (*this);
			}
			
			~bidirectional_iterator()
			{};
			
			operator bidirectional_iterator<Node, const T>()
			{
				return bidirectional_iterator<Node, const T>(_node,_end, _root);
			}
			
			nodeptr get_ptr() const
			{
				return this->_node;
			}
			
			reference operator*() const
			{
				return (_node->data);
			}
			
			pointer operator->() const
			{
				return (&(_node->data));
			}
			
			bidirectional_iterator& operator++()
			{
				if (_node == max(_root))
				{
					_node = _end;
					return (*this);
				}
				else if (_node == _end)
				{
					_node = NULL;
					return (*this);
				}
				this->_node = successor(_node);
				return (*this);
			}
			
			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator tmp = *this;
				if (_node == max(_root))
				{
					_node = _end;
					return (tmp);
				}
				else if (_node == _end)
				{
					_node = NULL;
					return (tmp);
				}
				this->_node = successor(_node);
				return (tmp);
			}
			
			bidirectional_iterator& operator--()
			{
				if (_node == _end)
				{
					_node = max(_root);
					return (*this);
				}
				else if (_node == min(_root))
				{
					_node = _end;
					return (*this);
				}
				this->_node = predecessor(_node);
				return (*this);
			}
			
			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator tmp = *this;
				if (_node == _end)
				{
					_node = max(_root);
					return (tmp);
				}
				else if (_node == min(_root))
				{
					_node = _end;
					return (tmp);
				}
				this->_node = predecessor(_node);
				return (tmp);
			}
		
		private:
			
			nodeptr min(nodeptr n)
			{
				if (n == NULL || n == _end)
					return _end;
				for(; n->left != _end; n = n->left)
				{
				}
				return n;
			}
			
			nodeptr max(nodeptr n)
			{
				if (n == NULL || n == _end)
					return _end;
				for(; n->right != _end; n = n->right)
				{
				}
				return n;
			}
			
			nodeptr successor(nodeptr n)
			{
				if (n->right != _end)
					return min(n->right);
		
				nodeptr tmp = n->parent;
				while (tmp != _end && n == tmp->right)
				{
					n = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}
			
			nodeptr predecessor(nodeptr n)
			{
				if (n->left != _end)
					return max(n->left);
		
				nodeptr tmp = n->parent;
				while (tmp != _end && n == tmp->left)
				{
					n = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}
		
		private:
		
			nodeptr _node;
			nodeptr _end;
			nodeptr _root;
};


	template< class Node, class T1, class T2>
		bool operator==( const ft::bidirectional_iterator<Node, T1>& lhs,
				const ft::bidirectional_iterator<Node, T2>& rhs )
	{
	        return (lhs.get_ptr() == rhs.get_ptr());
	}

	template< class Node, class T1, class T2 >
		bool operator!=( const ft::bidirectional_iterator<Node, T1>& lhs,
				const ft::bidirectional_iterator<Node, T2>& rhs )
	{
		return (lhs.get_ptr() != rhs.get_ptr());
	}
}
#endif
