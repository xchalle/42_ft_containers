#ifndef VECTOR_H
#define VECTOR_H
#include <cstdio>
#include <memory>
#include <cstddef>
#include <stdexcept>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator.hpp"
#include "utils.hpp"
namespace ft{

//template <class T, class Alloc>
//bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs);

template<class T, class Allocator = std::allocator<T> >
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
		typedef ft::random_access_iterator<T> iterator;
		typedef ft::random_access_iterator<const T> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
	//	typedef typename Allocator::allocator_type allocator_type;
		//CONSTRUCTOR NOT FINISHED
	explicit vector(const Allocator& alloc = Allocator())
	{
		_alloc = alloc;
		_begin = NULL;
		_end = NULL;
		_capacity = 0;
	}
	~vector()
	{
		clear();
		_alloc.deallocate(_begin, capacity());
	}
	template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a ) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0)
	{
		size_type count = distance(first, last);
		/*InputIt tmp = first;
		while (tmp != last)
		{
			tmp++;
			count++;
		}*/
		_begin = _alloc.allocate(count);
		_end = _begin;
		InputIt tmp = first;
		while (tmp != last)
		{
			_alloc.construct(_end, *tmp);
			tmp++;
			_end++;
		}
		_capacity = count;

	};
	explicit vector(size_type count,
			const T& value = T(),
			const Allocator& alloc = Allocator()) : _alloc(alloc), _begin(NULL), _end(NULL)
	{
		_begin = _alloc.allocate(count);
		_end = _begin;
		_capacity = count;
		while (count > 0)
		{
			_alloc.construct(_end, value);
			count--;
			_end++;
		}
	}
	vector( const vector& other)
	{
		_begin = NULL;
		_end = NULL;
		_alloc = other.get_allocator();
		_capacity = 0;
		insert(begin(), other.begin(), other.end());
	}

//	ASSIGN TODO
	void assign( size_type count, const T& value)
	{
		_alloc.deallocate(_begin, _capacity);
		_begin = _alloc.allocate(count);
		_end = _begin;
		_capacity = count;
		while (count > 0)
		{
			_alloc.construct(_end, value);
			count--;
			_end++;
		}
	};
	template <class InputIt>
	void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a) //change for distance
	{
		_alloc.deallocate(_begin, _capacity);
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
		_capacity = n;
		while (first != last)
		{
			_alloc.construct(_end, *first);
			_end++;
			first++;
		}
	}
//	ITERATOR
	iterator begin() { return (_begin);}
	const_iterator begin() const { return (_begin);}
	iterator end() { return (_end);}
	const_iterator end() const { return (_end);}
//	REVERSE_ITERATOR
	reverse_iterator rbegin() { return (reverse_iterator(end()));}
	const_reverse_iterator rbegin() const { return reverse_iterator(end());}
	reverse_iterator rend() { return reverse_iterator(begin());}
	const_reverse_iterator rend() const { return reverse_iterator(begin());}
//	GET_ALLOCATOR
	allocator_type get_allocator() const
	{
		return (_alloc);
	};
//	AT 
	reference at( size_type pos )
	{
		if (pos > this->size())
			throw std::out_of_range("exception at operation is out of range");
		return ((*this)[pos]);

	};
	const_reference at( size_type pos ) const
	{
		if (pos > this->size())
			throw std::out_of_range("exception at operation is out of range");
		return ((*this)[pos]);
	};
//	OPERATOR[] 
	reference operator[]( size_type pos )
	{
		return (*(_begin + pos));
	}
	const_reference operator[]( size_type pos ) const
	{
		return (*(_begin + pos));
	}
//	FRONT 
	reference front()
	{
		return (*_begin);
	};
	const_reference front() const
	{
		return (*_begin);
	};
//	BACK 
	reference back()
	{
		return (*(_end - 1));
	};
	const_reference back() const
	{
		return (*(_end - 1));
	};
//	DATA
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
		if (_begin == _end)
			return true;
		return false;
		};
//	SIZE
	size_type size() const
	{
		//return _end - _begin;
		return (ft::distance(begin(), end()));
	};
//	MAX_SIZE 
	size_type max_size() const
	{
		return (_alloc.max_size());
	};
//	RESERVE //throz error/change capacity/check if max_size() is exceed
	void reserve( size_type new_cap)
	{
		if (new_cap > max_size())
			throw(std::length_error("vector::reserve"));
		if (new_cap <= capacity())
			return ;
		difference_type old_capacity = capacity();
		pointer old_begin = _begin;
		pointer save_begin = _begin;
		pointer old_end = _end;
		_begin = _alloc.allocate(new_cap);
		_end = _begin;
		_capacity = new_cap;
		while (old_begin != old_end)
		{
			_alloc.construct(_end, *(old_begin));
			_alloc.destroy(old_begin);
			_end++;
			old_begin++;
		}
		_alloc.deallocate(save_begin, old_capacity);
	}
//	CQPQCITY 
	size_type capacity() const
	{
		return (_capacity);
	}
//	CLEAR
	void clear()
	{
		//_end--;
		while (_end != _begin)
		{
			//_alloc.destroy(_end);
			_end--;
		}
	};
//	INSERT 
	iterator insert( iterator pos, const T& value )
	{
		difference_type count = 1;
		size_type new_size = size() + count;
		difference_type pos_int = _end - &(*pos);
		if (new_size > capacity())
		{
			if (new_size > max_size())
				throw(std::length_error("vector::insert"));
			if (capacity() * 2 > new_size)
				reserve(size() * 2);
			else 
				reserve(new_size);
		}
		for (int i = 1; i <= pos_int; i++)
		{
	//		if (i!= 0)
				//_alloc.destroy(_end - i);
			_alloc.construct(_end - i + count, *(_end - i));
		}
		for (int i = 0; i < count; i++)
			_alloc.construct(_end - pos_int + i, value);
		_end += count;
		return (end() - pos_int - 1);
	}
	/*iterator insert( iterator pos, const T& value )
	{
		difference_type pos_int = _end - &(*pos);
		if (size() + 2 > capacity())
		{
			if (size() != 0)
			{
				while (size() + 1 > capacity())
					reserve(capacity() * 2);
			}
			else
			{
				_alloc.deallocate(_begin, capacity());
				_begin=_alloc.allocate(1);
				_end = _begin;
				_alloc.construct(_end, value);
				_end++;
				_capacity = 1;
				return (_begin);
			}

		}
		for (int i = 0; i < pos_int; i++)
		{
			//_alloc.destroy(_end - i);
			_alloc.construct(_end - i, *(_end - i - 1));
		}
		_alloc.construct(_end - pos_int, value);
		_end++;

		return (end() - pos_int - 1);
	};*/
	void insert( iterator pos, size_type count, const T& value )
	{
		size_type new_size = size() + count;
		difference_type pos_int = _end - &(*pos);
		if (new_size > capacity())
		{
			if (new_size > max_size())
				throw(std::length_error("vector::insert"));
			if (capacity() * 2 > new_size)
				reserve(size() * 2);
			else 
				reserve(new_size);
		}
		//std::cout << capacity() << std::endl;
		for (int i = 1; i <= pos_int; i++)
		{
	//		if (i!= 0)
				//_alloc.destroy(_end - i);
			_alloc.construct(_end - i + count, *(_end - i));
		}
		for (size_type i = 0; i < count; i++)
			_alloc.construct(_end - pos_int + i, value);
		_end += count;
		return;
	}
	/*void insert( iterator pos, size_type count, const T& value )
	{
		difference_type pos_int = _end - &(*pos);
		if (size() + count +1> capacity())
		{
			if (size() != 0)
			{
				while (size() + 1> capacity())
					reserve(capacity() * 2);
			}
			else
			{
				_alloc.deallocate(_begin, capacity());
				_begin=_alloc.allocate(count);
				_end = _begin;
				for (size_type i = 0; i < count; i++)
				{
					_alloc.construct(_end, value);
					_end++;
				}
				_end++;
				_capacity = count;
				return ;
			}
		}
		for (int i = 0; i <= pos_int; i++)
		{
	//		if (i!= 0)
				//_alloc.destroy(_end - i);
			_alloc.construct(_end - i + count, *(_end - i));
		}
		for (size_type i = 0; i < count; i++)
			_alloc.construct(_end - pos_int + i, value);
		_end += count;
		return ;
	};*/
template< class InputIt>
void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a)
	{
		difference_type count = distance(first, last);
		size_type new_size = size() + count;
		difference_type pos_int = _end - &(*pos);
		if (new_size > capacity())
		{
			if (new_size > max_size())
				throw(std::length_error("vector::insert"));
			if (capacity() * 2 > new_size)
				reserve(size() * 2);
			else 
				reserve(new_size);
		}
		for (int i = 1; i <= pos_int; i++)
		{
	//		if (i!= 0)
				//_alloc.destroy(_end - i);
			_alloc.construct(_end - i + count, *(_end - i));
		}
		for (int i = 0; i < count; i++)
		{
			_alloc.construct(_end - pos_int + i, *first);
			first++;
		}
		_end += count;
		return;
	}

/*template< class InputIt>
void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a)
	{
		difference_type count = distance(first, last);
		difference_type pos_int = _end - &(*pos);
		if (size() + count + 1> capacity())
		{
			if (size() != 0)
			{
				while (size() + 1 > capacity())
					reserve(capacity() * 2);
			}
			else
			{
				_alloc.deallocate(_begin, capacity());
				_begin=_alloc.allocate(count);
				_end = _begin;
				for (int i = 0; i < count; i++)
				{
					_alloc.construct(_end, *first);
					_end++;
					first++;
				}
				_capacity = count;
				return ;
			}
		}
		for (int i = 0; i <= pos_int; i++)
		{
	//		if (i!= 0)
				//_alloc.destroy(_end - i);
			_alloc.construct(_end - i + count, *(_end - i));
		}
		for (int i = 0; i < count; i++)
		{
			_alloc.construct(_end - pos_int + i, *first);
			first++;
		}
		_end += count;
		return;
	};*/
//	ERASE 
	iterator erase( iterator pos )
	{
		if (pos == this->end())
			return(pos);
		pointer _return_val = &(*pos);
		pointer posi = &(*pos);
		if (_return_val == _end - 1)
			_alloc.destroy(&(*pos));
		else
		{
			_alloc.destroy(&(*pos));
			for (int i = 0; i < _end - posi - 1; i++)
			{
				_alloc.construct(&(*(posi + i)), *(posi + i + 1));
				_alloc.destroy(posi + i + 1);
			}
		}
		_end--;
		return (_return_val);
	}
	iterator erase( iterator first, iterator last )
	{
		pointer tmp = &(*first);
		if (first == last)
		{
			return (last);
		}
		for (; first <= last; first++)
		{
			_alloc.destroy(&(*first));
		}
		first = tmp;
		for (int i = 0; i< _end - &(*last); i++)
		{
			_alloc.construct(&(*first) + i, *(last + i));
			_alloc.destroy(&(*last) + i);
		}
		_end -= last - first;
		return(first);
	}
//	PUSH_BACK 
	void push_back( const T& value )
	{
		if ((size() + 1) > capacity())
		{
			if (size() == 0 && capacity() == 0)
			{
				_begin = _alloc.allocate(1);
				_end = _begin;
				_capacity = 1;
			}
			else
				reserve(capacity() * 2);
		}
		_alloc.construct(_end, value);
		_end++;
	}
//	POP_BACK 
	void pop_back()
	{
		_end--;
		_alloc.destroy(_end);
	}
//	RESIZE 
	void resize( size_type count, T value = T() )
	{
		if (size() > count)
		{
			_end = _begin + count;
			_alloc.destroy(_end);
		}
		else if (size() < count)
		{
			if (capacity() * 2 > count)
				reserve(capacity() * 2);
			else 
				reserve(count);
			/*	if (count > max_size())
					throw(std::length_error("vector::resize"));
				if (capacity() == 0)
					reserve(count);
				if (capacity() * 2 > max_size() && max_size() >= count)
					reserve(max_size());
				if (capacity() * 2 < max_size())
					reserve(capacity() * 2);	*/
			while (size() != count)
			{
				_alloc.construct(_end, value);
				_end++;
			}
		}
	}
//	SWAP TODO
	void swap( vector& other )
	{
		pointer tmp_begin;
		pointer tmp_end;
		Allocator tmp_alloc;
		difference_type tmp_capacity;
		tmp_begin = _begin;
		tmp_end = _end;
		tmp_alloc = _alloc;
		tmp_capacity = _capacity;
		_begin = other._begin;
		_end = other._end;
		_alloc = other._alloc;
		_capacity = other._capacity;
		other._begin = tmp_begin;
		other._end = tmp_end;
		other._alloc = tmp_alloc;
		other._capacity = tmp_capacity;
	}
//	OPERATOR =
	vector& operator=(const vector& other)
		{
		if (*this == other)
			return *this;
		this->clear();
		//_alloc.deallocate(_begin, capacity());
		this->insert(this->end(), other.begin(), other.end());
		return (*this);
	};
	private:
		Allocator	_alloc;
		pointer	_begin;
		pointer	_end;
		difference_type _capacity;

};
/*template <class T, class U, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<U, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::const_iterator l_end = lhs.end();
	typename ft::vector<U>::const_iterator r_end = rhs.end();
	typename ft::vector<U>::const_iterator r_begin = rhs.begin();
	for(typename ft::vector<T>::const_iterator l_begin = lhs.begin(); l_begin != l_end; l_begin++)
	{
		if (*l_begin != *r_begin)
			return false;
		r_begin++;
	}
	return true;
};*/
template <class T, class Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	typename ft::vector<T>::const_iterator l_end = lhs.end();
	typename ft::vector<T>::const_iterator r_end = rhs.end();
	typename ft::vector<T>::const_iterator r_begin = rhs.begin();
	for(typename ft::vector<T>::const_iterator lt_begin = lhs.begin(); lt_begin != l_end; lt_begin++)
	{
		if (*lt_begin != *r_begin)
			return false;
		r_begin++;
	}
	return true;
};
template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<T,Alloc>& rhs )
{
	if (lhs == rhs)
		return false;
	return true;
};
/*template< class T, class U, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs,
                 const ft::vector<U,Alloc>& rhs )
{
	if (lhs == rhs)
		return false;
	return true;
};*/
template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
};
template< class T, class Alloc >
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return (true);
	return (false);
};
template< class T, class Alloc >
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
};
template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs > rhs || lhs == rhs)
		return (true);
	return (false);
};
template< class T, class Alloc >

void swap( ft::vector<T,Alloc>& lhs,
           ft::vector<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}
}
//#include "vector.tpp"
#endif
