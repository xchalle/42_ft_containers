#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "utils.hpp"
#include "compare.hpp"
#include "pair.hpp"
#include "rb_tree.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "rb_iterator.hpp"


namespace ft{

	template<
		class Key,
		      class Compare = ft::less<Key>,
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
			typedef ft::bidirectional_iterator<node< value_type>, const value_type> iterator;
			typedef ft::bidirectional_iterator<node< value_type>, const value_type> const_iterator;
			//class iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		protected:
			typedef node<value_type> *nodeptr;
		public:
			key_compare				_comp;
			allocator_type				_alloc;
			rb_tree<value_type, value_compare>	_rbt;

		//CONSTRUCTOR TODO
			set() : _comp(key_compare()), _alloc(Allocator())
			{}
			explicit set( const Compare& comp,
					const Allocator& alloc = Allocator() ) : _comp(comp), _alloc(alloc)
			{}
			template < class InputIt>
				set( InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator& alloc = Allocator()) : _comp(comp), _alloc(alloc)
			{
				insert(first, last);
			//	while (first != last)
			//	{
			//		_rbt.insert(*first);
			//		first++;
			//	}
			}
			set (const set& rhs)
			{
				insert(rhs.begin(), rhs.end());
			}
		//DESTRUCTOR
			~set()
			{ 
				_rbt.destroy();
				_rbt.destroy_end();
			}
		//OPERTOR=
			set& operator=(const set& other)
			{
		//	if (*this == other)
		//		return (*this);
				clear();
				insert(other.begin(), other.end());
			//TODO
				return (*this);
			}
		//GET_ALLOCATOR
			allocator_type get_allocator() const {return (_alloc);}
		//BEGIN//cosnt_fct TODO
			iterator begin()
			{
				return (iterator(_rbt.min(), _rbt.get_end(), _rbt.get_root()));
			}
			const_iterator begin() const 
			{
				return (const_iterator(_rbt.min(), _rbt.get_end(), _rbt.get_root()));
			}
		//END//cosnt_fct TODO
			iterator end()
			{
				return (iterator(_rbt.get_end(), _rbt.get_end(), _rbt.get_root()));
			}
		//iterator root()
		//{
		//	return (_root);
		//}
			const_iterator end() const
			{
				return (const_iterator(_rbt.get_end(), _rbt.get_end(), _rbt.get_root()));
			}
		//RBEGIN//cosnt_fct TODO
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
		//REND //cosnt_fct TODO
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
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
				return (ft::make_pair<iterator, bool>(iterator(_rbt.search(value), _rbt.get_end(), _rbt.get_root()), tmp));
			}
			iterator insert(iterator hint, const value_type& value)
			{
				(void)hint;
				_rbt.insert(value);
				return(iterator(_rbt.search(value), _rbt.get_end(), _rbt.get_root()));
			}
			template<class InputIt>
				void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = ft::nullptr_a)
			{
				while(first != last)
					_rbt.insert(*first++);
			}
		//ERASE
			iterator erase(iterator pos)
			{
				_rbt.delete_node(*pos);
				return end();
			}
			iterator erase(iterator first, iterator last)
			{
		//	last--;
			//std::cout <<"last "<< *(--last) << std::endl;
				while (first != last)
				{
					first = find(*first);
					erase(first++);
				//iterator tmp = last--;
		//		_rbt.delete_node(*(last--));
			//	std::cout << *first << std::endl;
			//	_rbt.delete_node(*(first++));
				}
				//_rbt.delete_node(*(last));
				return end();
			}
			size_type erase (const Key& key)
			{
				if (_rbt.delete_node(key))
					return 1;
				return 0;
			}
		//SWAP
			void swap(set &other)
			{
				_rbt.swap(other._rbt);
			}
		//KEY_COMP
		/*key_compare key_comp() const
		{
			return _comp;
		}
		//VALUE_COMP
		value_compare value_comp() const
		{
			return value_compare(_comp);
		}*/
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
				return(iterator(_rbt.search(key), _rbt.get_end(), _rbt.get_root()));
			}
			const_iterator find( const Key& key) const
			{
				return(const_iterator(_rbt.search(key), _rbt.get_end(), _rbt.get_root()));
			}
		//LOWER_BOUND
			const_iterator lower_bound( const Key& key) const
			{
				return (const_iterator(_rbt.lower_bound(key), _rbt.get_end(), _rbt.get_root()));
			}
			iterator lower_bound( const Key& key)
			{
				return (iterator(_rbt.lower_bound(key), _rbt.get_end(), _rbt.get_root()));
			}
			const_iterator upper_bound( const Key& key) const
			{
				return (const_iterator(_rbt.upper_bound(key), _rbt.get_end(), _rbt.get_root()));
			}
			iterator upper_bound( const Key& key)
			{
				return (iterator(_rbt.upper_bound(key), _rbt.get_end(), _rbt.get_root()));
			}
		//EQUAL_RANGE
			ft::pair<iterator, iterator> equal_range(const Key& key)
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}
			ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}
		//KEY_COMP
			key_compare key_comp() const
			{
				return (_comp);
			}
		//VALUE_COMP
			value_compare value_comp() const
			{
				return (_comp);
			}
	};

	template< class Key , class Compare, class Alloc >
		bool operator==( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && ft::equal(rhs.begin(), rhs.end(), lhs.begin()))
			return true;
		return false;

	}
	template< class Key , class Compare, class Alloc >
		bool operator!=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if(lhs == rhs)
			return false;
		return true;
	}
	template< class Key , class Compare, class Alloc >
		bool operator<( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		return false;
	}
	template< class Key , class Compare, class Alloc >
		bool operator<=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if(lhs < rhs || lhs == rhs)
			return true;
		return false;
	}
	template< class Key , class Compare, class Alloc >
		bool operator>( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if (lhs <= rhs)
			return false;
		return true;
	}
	template< class Key , class Compare, class Alloc >
		bool operator>=( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs)
	{
		if (lhs < rhs)
			return false;
		return true;
	}
	template<class Key, class Compare, class Alloc>
		void swap(ft::set<Key, Compare, Alloc>& lhs, ft::set<Key, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif 
