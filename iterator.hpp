#ifndef ITERATOR_H
#define ITERATOR_H
namespace ft{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag{};
struct random_access_iterator_tag : public bidirectional_iterator_tag{};

template < class Iter>
struct iterator_traits
{
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
	typedef typename Iter::iterator_category iterator_category;
};

template < class T>
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};

template < class T>
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef std::random_access_iterator_tag iterator_category;
};

template <class Category,
	 class T,
	 class Distance = std::ptrdiff_t,
	 class Pointer = T*,
	 class Reference = T&>
	 struct iterator
{
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef const Pointer const_pointer;
	typedef Reference reference;
};

template <class Iter>
class reverse_iterator
{
	public:
	typedef Iter iterator_type; 
	typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
	typedef typename ft::iterator_traits<Iter>::value_type value_type;
	typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
	typedef typename ft::iterator_traits<Iter>::pointer pointer;
	typedef typename ft::iterator_traits<Iter>::reference reference;

	reverse_iterator() : _itr(NULL)
	{}
	explicit reverse_iterator( iterator_type x) : _itr(x)
	{}
	reverse_iterator( const reverse_iterator<Iter>& rhs) : _itr(rhs._itr)
	{}
	reverse_iterator& operator=( const reverse_iterator<Iter>& rhs)
	{
		_itr = (rhs._itr);
		return (*this);
	}
	~reverse_iterator()
	{}
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
	reverse_iterator& operator++()
	{
			--_itr;
			return (*this);
	}
	reverse_iterator& operator--()
	{
			++_itr;
			return (*this);
	}
	reverse_iterator operator++( int )
	{
		reverse_iterator tmp(*this);
		--_itr;
		return (tmp);
	}
	reverse_iterator operator--( int )
	{
		reverse_iterator tmp(*this);
		++_itr;
		return (tmp);
	}
	reverse_iterator operator+( difference_type n ) const
	{
		return (reverse_iterator(base() - n));
	}
	reverse_iterator operator-( difference_type n ) const
	{
		return (reverse_iterator(base() + n));
	}
	reverse_iterator& operator+=( difference_type n )
	{
		_itr = _itr - n;
		return (*this);
	}
	reverse_iterator& operator-=( difference_type n )
	{
		_itr = _itr + n;
		return (*this);
	}
	private:
		iterator_type _itr;
};

template< class Iter >

reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{
	return (reverse_iterator<Iter>(it.base() - n));
}

template< class Iterator >

typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
{
	return (rhs.base() - lhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >

bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
		const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() <= rhs.base());
}

template<typename T>
class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
{
	public:
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer pointer;

		random_access_iterator() : _ptr(NULL)
	{}
		random_access_iterator(pointer ptr) : _ptr(ptr)
	{}
		//template <typename T>
		random_access_iterator(random_access_iterator& rhs)
	{
		_ptr = rhs._ptr;
	}
		random_access_iterator(const random_access_iterator& rhs) : _ptr(rhs._ptr)
	{
	}
		random_access_iterator& operator=( const random_access_iterator &rhs)
	{
		_ptr = rhs._ptr;
		return (*this);
	};
		operator random_access_iterator<const T>()
		{return random_access_iterator<const T>(_ptr);}

		~random_access_iterator()
	{

	};
		pointer get_ptr() const
		{ return this->_ptr;}

		T& operator*()
		{
			return *(_ptr);
		};
		T* operator->()
		{
			return (&(_ptr));
		};
		random_access_iterator& operator++()
		{
			this->_ptr++;
			return (*this);
		}
		random_access_iterator& operator--()
		{
			this->_ptr--;
			return (*this);
		}
		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(*this);
			this->_ptr++;
			return (tmp);
		}
		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(*this);
			this->_ptr--;
			return (tmp);
		}
		reference operator[](difference_type n)
		{
			return *(_ptr + n);
		}
	private:
		pointer _ptr;

};
	template <typename T>
	bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		if (lhs.get_ptr() == rhs.get_ptr())
			return true;
		return false;
	}

	template <typename T, typename U>
	bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		if (lhs.get_ptr() == rhs.get_ptr())
			return true;
		return false;
	}
	template <typename T>
	bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		if (lhs.get_ptr() == rhs.get_ptr())
			return false;
		return true;
	}
	template <typename T, typename U>
	bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		if (lhs.get_ptr() == rhs.get_ptr())
			return false;
		return true;
	}
	template <typename T>
	ft::random_access_iterator<T>& operator +=(ft::random_access_iterator<T>& lhs, typename ft::random_access_iterator<T>::difference_type n)
	{
		typename ft::random_access_iterator<T>::difference_type m = n;
		if (m >= 0)
		{
			while (m--)
			{
				lhs++;
			}
		}
		else
		{	
			while (m++)
			{
				lhs--;
			}
		}
		return (lhs);
	}
	template <typename T>
ft::random_access_iterator<T> operator +(const ft::random_access_iterator<T>& lhs, const typename ft::random_access_iterator<T>::difference_type n)
	{
		ft::random_access_iterator<T> tmp = lhs;
		return tmp += n;
	}
	template <typename T>
	ft::random_access_iterator<T> operator +( const typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T>& rhs) 
	{
		ft::random_access_iterator<T> tmp = rhs;
		return tmp += n;
	}
	template <typename T>
	ft::random_access_iterator<T>& operator -=(ft::random_access_iterator<T>& lhs, typename ft::random_access_iterator<T>::difference_type n)
	{
		return lhs += -n;
	}
	template <typename T>
	ft::random_access_iterator<T> operator -(const ft::random_access_iterator<T>& lhs, const typename ft::random_access_iterator<T>::difference_type n)
	{
		ft::random_access_iterator<T> tmp = lhs;
		return tmp -= n;
	}
	template <typename T>
	typename ft::random_access_iterator<T>::difference_type operator -(const ft::random_access_iterator<T> &lhs, const ft::random_access_iterator<T> &rhs)
	{
		return (lhs.get_ptr() - rhs.get_ptr());
	}	
	template <typename T>
	bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return rhs - lhs > 0;
	}
	template <typename T>
	bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return lhs - rhs > 0;
	}
	template <typename T>
	bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return !(lhs > rhs);
	}
	template <typename T>
	bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs)
	{
		return !(lhs < rhs);
	}
	
	}
#endif

