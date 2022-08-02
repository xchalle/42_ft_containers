#ifndef VECTOR_H
#define VECTOR_H
#include <cstdio>
#include <memory>
#include <cstddef>
namespace ft{

//template <class T, class Alloc>
//bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);

template<class T, class Allocator = std::allocator<T>>
class vector
{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename ft::random_access_iterator<T> iterator;
		typedef typename ft::random_access_iterator<const T> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	//	typedef typename Allocator::allocator_type allocator_type;
		//CONSTRUCTOR NOT FINISHED
	vector()
	{
		std::cout << "mama" << std::endl;
	}
	~vector()
	{

	}
/*	explicit vector(const Allocator& alloc);
	template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) : _alloc(alloc), _begin(NULL), _end(NULL)
	{
		std::cout <<"mama"<< std::endl;
		size_type count = 0;
		InputIt tmp = first;
		while (tmp != last)
		{
			std::cout <<tmp<< std::endl;
			tmp++;
			count++;
		}
		_begin = _alloc.allocate(count);
		_end = _begin;
		tmp = first;
		while (tmp != last)
		{
			_alloc.construct(_end, tmp);
			tmp++;
			_end++;
		}

	};*/
	explicit vector(size_type count,
			const T& value = T(),
			const Allocator& alloc = Allocator()) : _alloc(alloc), _begin(NULL), _end(NULL)
	{
		std::cout <<"mama"<< std::endl;
		_begin = _alloc.allocate(count);
		_end = _begin;
		this->tester = 1345;
		while (count > 0)
		{
			std::cout <<"mama"<< std::endl;
			_alloc.construct(_end, value);
			count--;
			_end++;
		}
	}
//	vector( const vector& other); TODO

//	ASSIGN TODO
	void assign( size_type count, const T& value)
	{
		_begin = _alloc.allocate(count);
		_end = begin;
		while (count > 0)
		{
			_alloc.construct(_end, value);
			count--;
			_end++;
		}
	};
	template <class InputIt>
	void assign(InputIt first, InputIt last) //change for distance
	{
		difference_type n = 0;
		InputIt tmp;
		tmp = first;
		while (tmp != last)
		{
			tmp++;
			n++;
		}
		_begin = _alloc.allocate(n);
		_end = _begin;
		while (first != last)
		{
			_alloc.construct(_end, *first);
			_end++;
			first++;
		}
	}
//	ITERATOR
	iterator begin() { return (_begin);}
	const_iterator cbegin() const { return (_begin);}
	iterator end() { return (_end);}
	const_iterator cend() const { return (_end);}
//	REVERSE_ITERATOR
	reverse_iterator rbegin() { return (_end);}
	const_reverse_iterator crbegin() const { return (_end);}
	reverse_iterator rend() { return (_begin);}
	const_reverse_iterator crend() const { return (_begin);}
//	GET_ALLOCATOR
	allocator_type get_allocator() const
	{
		return (_alloc);
	};
//	AT TODO
	reference at( size_type pos )
	{
		if (pos > this->size())
			throw std::out_of_range("exception at operation is out of range");
		return (*(this)[pos]);

	};
	const_reference at( size_type pos ) const
	{
		if (pos > this->size())
			throw std::out_of_range("exception at operation is out of range");
		return (*(this)[pos]);
	};
//	OPERATOR[] TODO
	reference operator[]( size_type pos )
	{
		return (*(_begin + pos));
	}
	const_reference operator[]( size_type pos ) const
	{
		return (*(_begin + pos));
	}
//	FRONT TODO
	reference front()
	{
		return (*_begin);
	};
	const_reference front() const
	{
		return (*_begin);
	};
//	BACK TODO
	reference back()
	{
		return (*_end);
	};
	const_reference back() const
	{
		return (*_end);
	};
//	DATA TODO
	T* data()
	{
		if (size() == 0)
			return (NULL);
		return (_begin);
	}
	const T* data() const
	{
		if (size() == 0)
			return (NULL);
		return (_begin);
	}
//	EMPTY
	bool empty() const
	{
		if (this->begin() == this->end())
			return true;
		return false;
	};
//	SIZE
	size_type size() const
	{
		return (ft::distance(this->begin(), this->end()));
	};
//	MAX_SIZE TODO
	size_type max_size() const
	{
		return (1);
		//TODO
	};
//	RESERVE TODO
	void reserve( size_type new_cap)
	{};
//	CQPQCITY TODO
	size_type capacity() const;
//	CLEAR
	void clear()
	{
		while (_end != _begin)
		{
			Allocator::destroy(_end);
			_end--;
		}
	};
//	INSERT TODO
	iterator insert( iterator pos, const T& value )
	{
		return pos;
	};
	void insert( iterator pos, size_type count, const T& value )
	{
		return;
	};
	template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last )
	{
		return;
	};
//	ERASE TODO
	iterator erase( iterator pos );
	iterator erase( iterator first, iterator last );
//	PUSH_BACK TODO
	void push_back( const T& value );
//	POP_BACK TODO
	void pop_back();
//	RESIZE TODO
	void resize( size_type count, T value = T() );
//	SWAP TODO
	void swap( vector& other );
	int print_test()
	{
		pointer _test = this->_begin;
		while (_test != _end)
		{
			std::cout<< *_test<< std::endl;
			_test++;
		}
		return this->tester;
	}
//	OPERATOR =
	vector& operator=(const vector& other)
	{
		if (*this == other)
			return *this;
		this->clear();
		this->insert(this->end(), other.begin(), other.end());
		return (*this);
	};
	private:
		int tester = 5;
		Allocator	_alloc;
		pointer	_begin;
		pointer	_end;

};
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::iterator l_end = lhs.end();
	typename ft::vector<T>::iterator r_end = rhs.end();
	typename ft::vector<T>::iterator r_begin = rhs.begin();
	for(typename ft::vector<T>::iterator l_begin = lhs.begin(); l_begin != l_end; l_begin++)
	{
		if (*l_begin != *r_begin)
			return false;
		r_begin++;
	}
	return true;
};
template< class T, class Alloc >
bool operator!=( const std::vector<T,Alloc>& lhs,
                 const std::vector<T,Alloc>& rhs )
{
	if (lhs == rhs)
		return false;
	return true;
};
template< class T, class Alloc >
bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};
template< class T, class Alloc >
bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return (true);
	return (false);
};
template< class T, class Alloc >
bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
};
template< class T, class Alloc >
bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs )
{
	if (lhs > rhs || lhs == rhs)
		return (true);
	return (false);
};
}
//#include "vector.tpp"
#endif
