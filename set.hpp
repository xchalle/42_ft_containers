#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "utils.hpp"
#include "pair.hpp"
#include "rb_tree.hpp"
#include "rb_iterator.hpp"


namespace ft{
template<
class Key,
class Compare = std::less<Key>,
class Allocator = std::allocator<Key>
> class set
{
	public:
		typedef Key key_type;
		typedef Key value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Compare value_compare;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::bidirectional_iterator<node< value_type>, key_compare> iterator;
		//	typedef ft::const_bidirectional_iterator<Node<const T>, key_compare> const_iterator;
		//class iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		//	typedef ft::const_reverse_iterator<const_iterator> const_reverse_iterator;
	protected:
		typedef node<value_type> *nodeptr;

	public:
		key_compare				_comp;
		allocator_type				_alloc;
		rb_tree<value_type, value_compare>	_rbt;

		//CONSTRUCTOR TODO
		set() : _comp(key_compare()), _alloc(Allocator())
		{
		}
		explicit set( const Compare& comp,
				const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
		{
		}
		//DESTRUCTOR
		~set()
		{}


		//OPERTOR=
		set& operator=(const set& other)
		{
			if (*this == other)
				return (*this);
			clear();
			isert(begin(), other.begin(), other.end());
			//TODO
			return (*this);
		}
		//GET_ALLOCATOR
		allocator_type get_allocator() const {return (_alloc);}
		//BEGIN//cosnt_fct TODO
		iterator begin()
		{
			return (iterator(_rbt.min()));
		}
		/*
		const_iterator begin() const 
		{
			return (iterator(_rbt.min()));
		}
		*/
		//END//cosnt_fct TODO
		iterator end()
		{
			return (iterator(_rbt.max()));
		}
		//iterator root()
		//{
		//	return (_root);
		//}
		/*
		 * const_iterator end() const
		{
			return (iterator(max()));
		}
		*/
		//RBEGIN//cosnt_fct TODO
		/*reverse_iterator rbegin()
		{
			return (maximum(_root));
		}
		const_reverse_iterator rbegin() const
		{
			return (maximum(_root));
		}
		//REND //cosnt_fct TODO
		reverse_iterator rend()
		{
			return (minimum(_root));
		}
		const_reverse_iterator rend() const
		{
			return (minimum(_root));
		}*/
		//EMPTY
		bool empty() const
		{
			if (begin() == end())
				return true;
			return false;
		}
		//SIZE
		size_type size() const
		{
			return (ft::distance(begin(), end()));
		}
		//MAX_SIZE
		size_type max_size() const
		{
			return (_rbt.max_size());
		}
		//CLEAR
		void clear()
		{
			_rbt.destroy();
		}
		//INSERT
		ft::pair<iterator, bool> insert(const value_type& value)
		{
			bool tmp = _rbt.insert(value);
			return (ft::pair<iterator, bool>(iterator(_rbt.search(value)), tmp));
		}
		iterator insert(iterator hint, const value_type& value)
		{
			_rbt.insert(value);
			return(iterator(_rbt.search(value)));
		}
		template<class InputIt>
		void insert(InputIt first, InputIt last, , typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a)
		{
			while(first != last)
			{
				_rbt.insert(*first);
				first++;
			}
		}
		//ERASE
		iterator erase(iterator pos)
		{
			_rbt.delete_node(*pos);
			return ;
		}
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				_rbt.delete_node(*first);
				first++;
			}
			return ;
		}
		size_type erase (const Key& key)
		{
			if (_rbt.delete_node(key))
				return 1;
			return 0;
		}
		//KEY_COMP
		key_compare key_comp() const
		{
			return _comp;
		}
		//VALUE_COMP
		value_compare value_comp() const
		{
			return value_compare(_comp);
		}
		//COUNT
		size_type count( const Key& key) const
		{
			if (find(key) != end())
				return 1;
			return 0;
		}
		//FIND
		iterator find( const Key& key)
		{
			return(iterator(searchTree(key)));
		}
};
}

#endif 
