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
		this->_ptr;
	}
	private:
	pointer _ptr;
	nodeptr _node;
};
}
#endif
