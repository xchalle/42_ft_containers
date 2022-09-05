#ifndef MAP_HPP
#define MAP_HPP

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map
{
	typedef Key key_type;
	typedef T mapped_type;
	typedef typename ft::pair<const Key, T> value_type;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef Allocator::pointer pointer;
	typedef Allocator::const_pointer const_pointer;
	typedef bidirectionaliterator<value_type> iterator;
	typedef bidirectionaliterator<const value_type> const_iterator;
	typedef ft::reverse_iterator<iterator> reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
	//VALUE_COMPARE TODO
	template <typename Compare>
	class value_conpare : public ft::binary_function<value_type, value_type, bool>
	{
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		bool operator() ( const value_type& lhs, const value_type& rhs) const
		{
			return comp(lhs.first, rhs.first);
		}
		protected :
		value_compare( Compare c) : comp(c)
		{}
		Compare comp;
	}
	//CONSTRUCTOR TODO
	map()
	{}
	explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
	{}
	//DESTRUCTOR
	~map()
	{}
	//OPERTOR=
	map& operator=(const map& other)
	{
		if (*this == rhs)
			return (*this);
		clear();
		isert(begin(), other.begin(), other.end());
		//TODO
		return (*this);
	}
	//GET_ALLOCATOR
	allocator_type get_allocator() const {return (_alloc);}
	//AT
	T& at( const Key& key ) 
	{

	}
	const T& at( const Key& key ) const {}

}

#endif 
