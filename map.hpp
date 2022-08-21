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
	class value_conpare; //TODO
	//CONSTRUCTOR TODO
	map()
	{}
	explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
	{}
	//GET_ALLOCATOR
	allocator_type get_allocator() const {return (_alloc);}
	//AT
	T& at( const Key& key ) {}
	const T& at( const Key& key ) const {}

}

#endif 
