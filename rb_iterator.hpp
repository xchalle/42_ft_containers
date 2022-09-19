#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "rb_tree.hpp"
#include <iostream>

namespace ft{

template < typename Node, class T>
class const_bidirectional_iterator : public ft::iterator<std::bidirectional_iterator_tag, Node>
{
public:
typedef Node *nodeptr;
typedef Node node;
typedef typename ft::iterator<std::bidirectional_iterator_tag, Node>::iterator_category iterator_category;
//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::value_type value_type;
typedef typename ft::iterator<bidirectional_iterator_tag, Node>::difference_type difference_type;
typedef typename ft::iterator<bidirectional_iterator_tag, Node>::reference reference;
//typedef typename ft::iteratot_bidirectional_iterator_tag, Node>::reference::value_type referenceval;
typedef typename ft::iterator<bidirectional_iterator_tag, Node>::const_pointer pointer;
typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
//typedef typename ft::iterator<const_bidirectional_iterator_tag, Node>::pointer::value_type pointerval;
const_bidirectional_iterator() : _node(ft::nullptr_a), _end(ft::nullptr_a), _root(ft::nullptr_a)
{}
const_bidirectional_iterator(const nodeptr _ptr, const nodeptr end, const nodeptr root) : _node(_ptr), _end(end), _root(root)
{}
template <class U>
const_bidirectional_iterator(const const_bidirectional_iterator<Node, U> &rhs) : _node(rhs._node), _end(rhs._end), _root(rhs._root)
{
//	*this = rhs;
}
template <class U>
const_bidirectional_iterator& operator=(const const_bidirectional_iterator<Node, U> &rhs)
{
	_node = rhs._node;
	_end = rhs._end;
	_root = rhs._root;
	return (*this);
}
~const_bidirectional_iterator()
{};
operator const_bidirectional_iterator<Node, const T>()
{return const_bidirectional_iterator<Node, const T>(_node, _end, _root);}
pointer get_ptr() const
{return this->_node;}
value_type& operator*() const
{
	return (_node->data);
}
value_type* operator->() const
{
	return (&(_node->data));
}
const_bidirectional_iterator& operator++()
{
	/*if (_node->left == _end && _node->right == _end && _node == _node->parent->right)
	{
		pointer tmp2 = _node;
		while (tmp2->parent != NULL)
			tmp2 = tmp2->parent;
		std::cout << "bebe"<<tmp2->data << std::endl;
		if (max(tmp2) == _node)
		{
			_node = _node->right;
			return (*this);
		}
	}
	if (_node->right->right)
	{
		_node = _node->right;
		if (_node->left->right != _node)
		{
			while (_node->left->left)
			{
				_node = _node->left;
			}
		}
	}
	else
	{
		pointer tmp = _node->parent;
		while (tmp->left != _node)
		{
			_node = tmp;
			tmp = tmp->parent;
		}
		_node = tmp;
	}*/
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
const_bidirectional_iterator operator++(int)
{
	const_bidirectional_iterator tmp(*this);
	++*this;
	return (tmp);
}
const_bidirectional_iterator& operator--()
{
	/*if (_node->left->left)
	{
		_node = _node->left;
		if (_node->right->left != _node)
		{
			while (_node->right->right)
			{
				_node = _node->right;
			}
		}
	}
	else
	{
		nodeptr tmp = _node->parent;
		while (tmp->right != _node)
		{
			_node = tmp;
			tmp = tmp->parent;
		}
		_node = tmp;
	}*/
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
const_bidirectional_iterator operator--(int)
{
	const_bidirectional_iterator tmp(*this);
	--*this;
	return (tmp);
}
private:
pointer min(nodeptr n)
{
	if (n == NULL || n == _end)
		return _end;
	for(; n->left != _end; n = n->left)
	{
	}
	return n;
}
pointer max(nodeptr n)
{
	if (n == NULL || n == _end)
		return _end;
	for(; n->right != _end; n = n->right)
	{
	}
	return n;
}
pointer successor(nodeptr n)
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
pointer predecessor(nodeptr n)
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
public:
nodeptr _node;
nodeptr _end;
nodeptr _root;
};


template< class Node, class T1, class T2 >

bool operator==( const ft::const_bidirectional_iterator<Node, T1>& lhs,
	 const ft::const_bidirectional_iterator<Node, T2>& rhs )
{
return (lhs.get_ptr() == rhs.get_ptr());
}

template< class Node, class T1, class T2 >

bool operator!=( const ft::const_bidirectional_iterator<Node, T1>& lhs,
	 const ft::const_bidirectional_iterator<Node, T2>& rhs )
{
return (lhs.get_ptr() != rhs.get_ptr());
}
template < typename Node, class T>
class bidirectional_iterator : public ft::iterator<std::bidirectional_iterator_tag, Node>
{
public:
typedef Node *nodeptr;
typedef Node node;
typedef typename ft::iterator<std::bidirectional_iterator_tag, Node>::iterator_category iterator_category;
typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
typedef typename ft::iterator<bidirectional_iterator_tag, Node>::difference_type difference_type;
typedef value_type *pointer;
typedef value_type &reference;
//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::reference reference;
//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::reference::value_type referenceval;
//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::pointer pointer;
//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::pointer::value_type pointerval;
bidirectional_iterator() : _node(ft::nullptr_a), _end(ft::nullptr_a), _root(ft::nullptr_a)
{}
bidirectional_iterator(const nodeptr _ptr, const nodeptr end, const nodeptr root) : _node(_ptr), _end(end), _root(root)
{}
bidirectional_iterator(const bidirectional_iterator &rhs)/* : _node(rhs._node), _end(rhs._end), _root(rhs._root)*/
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
	{return bidirectional_iterator<Node, const T>(_node,_end, _root);}
	nodeptr get_ptr() const
	{return this->_node;}
	value_type& operator*() const
	{
		return (_node->data);
	}
	value_type* operator->() const
	{
		return (&(_node->data));
	}
	bidirectional_iterator& operator++()
	{
		/*if (_node->left == _end && _node->right == _end && _node == _node->parent->right)
		{
			pointer tmp2 = _node;
			while (tmp2->parent != NULL)
				tmp2 = tmp2->parent;
			std::cout << "bebe"<<tmp2->data << std::endl;
			if (max(tmp2) == _node)
			{
				_node = _node->right;
				return (*this);
			}
		}
		if (_node->right->right)
		{
			_node = _node->right;
			if (_node->left->right != _node)
			{
				while (_node->left->left)
				{
					_node = _node->left;
				}
			}
		}
		else
		{
			pointer tmp = _node->parent;
			while (tmp->left != _node)
			{
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}*/
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
		bidirectional_iterator tmp(*this);
		++*this;
		return (tmp);
	}
	bidirectional_iterator& operator--()
	{
		/*if (_node->left->left)
		{
			_node = _node->left;
			if (_node->right->left != _node)
			{
				while (_node->right->right)
				{
					_node = _node->right;
				}
			}
		}
		else
		{
			pointer tmp = _node->parent;
			while (tmp->right != _node)
			{
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}*/
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
		bidirectional_iterator tmp(*this);
		--*this;
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
	public:
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
/*
template <class Iter>
class rev_bidirectional_iterator
{
	public:
	typedef Iter iterator_type;
	typedef Node *nodeptr;
	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename ft::iterator<Iter>::value_type value_type;
	typedef typename ft::iterator<Iter>::difference_type difference_type;
	typedef typename ft::iterator<Iter>::reference reference;
	typedef typename ft::iterator<Iter>::pointer pointer;
	rev_bidirectional_iterator() : _ptr(ft::nullptr_a)
	{}
	rev_bidirectional_iterator(pointer ptr) : _ptr(ptr)
	{}
	rev_bidirectional_iterator(rev_bidirectional_iterator &rhs) : _ptr(rhs._ptr)
	{}
	rev_bidirectional_iterator& operator=(const rev_bidirectional_iterator &rhs)
	{
		_ptr = rhs._ptr;
		_node = rhs._node;
		return (*this);
	}

	~rev_bidirectional_iterator()
	{};
	iterator_type base() const
	{
		return (_itr);
	}
	pointer get_ptr() const
	{return this->_ptr;}
	reference operator*()
	{
		return *(_ptr);
	}
	pointer operator->()
	{
		return (&(_ptr));
	}
	rev_bidirectional_iterator& operator++()
	{
		this->_node = predecessor(_node);
		return (*this);
	}
	rev_bidirectional_iterator& operator++(int)
	{
		rev_bidirectional_iterator tmp(*this);
		this->_node = predecessor(_node);
		return (tmp);
	}
	rev_bidirectional_iterator& operator--()
	{
		this->_node = successor(_node);
		return (*this);
	}
	rev_bidirectional_iterator& operator--(int)
	{
		rev_bidirectional_iterator tmp(*this);
		this->_node = successor(_node);
		return (tmp);
	}
	private:
	pointer _ptr;
	nodeptr _node;
};*/

/*template <class Iter>
class rev_bidirectional_iterator
{
	public:
	typedef Iter iterator_type;
	typedef Node *nodeptr;
	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename ft::iterator<Iter>::value_type value_type;
	typedef typename ft::iterator<Iter>::difference_type difference_type;
	typedef typename ft::iterator<Iter>::reference reference;
	typedef typename ft::iterator<Iter>::pointer pointer;
	rev_bidirectional_iterator() : _ptr(ft::nullptr_a)
	{}
	rev_bidirectional_iterator(pointer ptr) : _ptr(ptr)
	{}
	rev_bidirectional_iterator(rev_bidirectional_iterator &rhs) : _ptr(rhs._ptr)
	{}
	rev_bidirectional_iterator& operator=(const rev_bidirectional_iterator &rhs)
	{
		_itr = rhs._itr;
		return (*this);
	}

	~rev_bidirectional_iterator()
	{};
	iterator_type base() const
	{
		return (_itr);
	}
	reference operator*() const
        {
                iterator_type tmp = _itr;
                return (*--tmp);
        }
        pointer operator->() const
        {
                return (&(operator*()));
        }
        reference operator[](difference_type n) const
        {
                return (*_itr + n - 1);
        }
        rev_bidirectional_iterator& operator++()
        {
		--_itr;
                        return (*this);
        }
        rev_bidirectional_iterator& operator--()
        {
                        ++_itr;
                        return (*this);
        }
        rev_bidirectional_iterator operator++( int )
        {
                rev_bidirectional_iterator tmp(*this);
                --_itr;
                return (tmp);
        }
        rev_bidirectional_iterator operator--( int )
        {
                rev_bidirectional_iterator tmp(*this);
                ++_itr;
                return (tmp);
        }
        rev_bidirectional_iterator operator+( difference_type n ) const
        {
                return (rev_bidirectional_iterator(base() - n));
        }
        rev_bidirectional_iterator operator-( difference_type n ) const
        {
                return (rev_bidirectional_iterator(base() + n));
        }
        rev_bidirectional_iterator& operator+=( difference_type n )
        {
                _itr = _itr - n;
                return (*this);
        }
        rev_bidirectional_iterator& operator-=( difference_type n )
        {
                _itr = _itr + n;
                return (*this);
        }
        private:
                iterator_type _itr;
};

template< class Iterator1, class Iterator2 >

bool operator==( const ft::rev_bidirectional_iterator<Iterator1>& lhs,
                 const ft::rev_bidirectional_iterator<Iterator2>& rhs )
{
        return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator!=( const ft::rev_bidirectional_iterator<Iterator1>& lhs,
                const ft::rev_bidirectional_iterator<Iterator2>& rhs )
{
        return (lhs.base() != rhs.base());
}
*/
}
#endif
