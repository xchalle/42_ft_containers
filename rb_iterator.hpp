#ifndef RB_ITERATOR_HPP
#define RB_ITERATOR_HPP
class< typename T, typename Node
class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, T>
{
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::iterator_category iterator_category;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::value_type value_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::difference_type difference_type;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::reference reference;
	typedef typename ft::iterator<bidirectional_iterator_tag, T>::pointer pointer;
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
	operator bidirectional_iterator<const T>()
	{return bidirectional_iterator<const T>(_ptr);}

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
		this->_ptr
	}
	private:
	pointer _ptr;
	NodePtr _node;
}
