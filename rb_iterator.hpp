#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP
namespace ft{
template < typename Node, class Compare>
class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, typename Node::data>
{
	typedef Node *nodeptr;
	typedef typename ft::iterator<bidirectional_iterator_tag, typename Node::data>::iterator_category iterator_category;
	typedef typename ft::iterator<bidirectional_iterator_tag, typename Node::data>::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, typename Node::data>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, typename Node::data>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, typename Node::data>::pointer pointer;
	bidirectional_iterator() : _ptr(ft::nullptr_a)
	{}
	bidirectional_iterator(pointer ptr) : _ptr(ptr)
	{}
	bidirectional_iterator(bidirectional_iterator &rhs) : _ptr(rhs._ptr)
	{}
	bidirectional_iterator& operator=(const bidirectional_iterator &rhs)
	{
		_ptr = rhs._ptr;
		_node = rhs._node;
		return (*this);
	}

	~bidirectional_iterator()
	{};
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
	bidirectional_iterator& operator++()
	{
		this->_node = successor(_node);
		return (*this);
	}
	bidirectional_iterator& operator++(int)
	{
		bidirectional_iterator tmp(*this);
		this->_node = successor(_node);
		return (tmp);
	}
	bidirectional_iterator& operator--()
	{
		this->_node = predecessor(_node);
		return (*this);
	}
	bidirectional_iterator& operator--(int)
	{
		bidirectional_iterator tmp(*this);
		this->_node = predecessor(_node);
		return (tmp);
	}
	private:
	pointer _ptr;
	nodeptr _node;
};
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

}
#endif
