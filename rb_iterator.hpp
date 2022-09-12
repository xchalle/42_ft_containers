#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP

#include "rb_tree.hpp"

namespace ft{
template < typename Node, class Compare>
class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, Node>
{
	public:
	typedef Node *nodeptr;
	typedef typename ft::iterator<bidirectional_iterator_tag, Node>::iterator_category iterator_category;
	typedef typename ft::iterator<bidirectional_iterator_tag, Node>::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, Node>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, Node>::reference reference;
	//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::reference::value_type referenceval;
	typedef typename ft::iterator<bidirectional_iterator_tag, Node>::pointer pointer;
	//typedef typename ft::iterator<bidirectional_iterator_tag, Node>::pointer::value_type pointerval;
	bidirectional_iterator() : _node(ft::nullptr_a)
	{}
	bidirectional_iterator(const pointer _ptr) : _node(_ptr)
	{}
	bidirectional_iterator(const bidirectional_iterator &rhs) : _node(rhs._node)
	{}
	bidirectional_iterator& operator=(const bidirectional_iterator &rhs)
	{
		_node = rhs._node;
		return (*this);
	}
	~bidirectional_iterator()
	{};
	pointer get_ptr() const
	{return this->_node;}
	typename Node::value_type operator*() const
	{
		return (_node->data);
	}
	pointer operator->() const
	{
		return (&(_node->data));
	}
	bidirectional_iterator& operator++()
	{
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
		}
		//this->_node = _node->successor(_node);
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
		if (_node->left->left)
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
		}
		//this->_node = _node->predecessor(_node);
		return (*this);
	}
	bidirectional_iterator operator--(int)
	{
		bidirectional_iterator tmp(*this);
		--*this;
		return (tmp);
	}
	private:
//	pointer min(pointer n)
//	{
//		for(; n->left != _end; n = n->left)
//		return n;
//	}
//	pointer max(pointer n)
//	{
//		for(; n->right != _end; n = n->right)
//		return n;
//	}
//	pointer successor(pointer n)
//	{
//		if (n->right != _end)
//			return min(n->right);
//
//		pointer tmp = n->parent;
//		while (tmp != _end && n == tmp->right)
//		{
//			n = tmp;
//			tmp = tmp->parent;
//		}
//		return tmp;
//	}
//	pointer predecessor(pointer n)
//	{
//		if (n->left != _end)
//			return max(n->left);
//
//		pointer tmp = n->parent;
//		while (tmp != _end && n == tmp->left)
//		{
//			n = tmp;
//			tmp = tmp->parent;
//		}
//		return tmp;
//	}
	nodeptr _node;
};


template< class Key, class Compare >

bool operator==( const ft::bidirectional_iterator<Key, Compare>& lhs,
                 const ft::bidirectional_iterator<Key, Compare>& rhs )
{
        return (lhs.get_ptr() == rhs.get_ptr());
}

template< class Key, class Compare >

bool operator!=( const ft::bidirectional_iterator<Key, Compare>& lhs,
                const ft::bidirectional_iterator<Key, Compare>& rhs )
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
