#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <cstdio>
#include <memory>
#include <cstddef>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator.hpp"
#include "utils.hpp"

namespace ft{

	template< class T, class Container = ft::vector<T> >
		class stack
	{
		public:

			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			explicit stack( const Container& cont = Container() ) : c(cont)
			{}
			
			stack( const stack& other )
			{
				*this = other;
			}
			
			stack& operator=( const stack& other )
			{
				c = other.c;
				return (*this);
			}
			
			~stack()
			{}
			
			reference top() { return (c.back());}
			
			const_reference top() const { return (c.back());}
			
			bool empty() const {return c.empty();}
			
			size_type size() const {return c.size();}
			
			void push( const value_type& value )
			{
				return (c.push_back(value));
			}
			
			void pop()
			{
				return (c.pop_back());
			}
			
			container_type get_c() const
			{
				return (c);
			}
		
		protected:

			container_type c;
	};

	template< class T, class Container >
		bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() == rhs.get_c());}

	template< class T, class Container >
		bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() != rhs.get_c());}

	template< class T, class Container >
		bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() < rhs.get_c());}

	template< class T, class Container >
		bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() <= rhs.get_c());}

	template< class T, class Container >
		bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() > rhs.get_c());}

	template< class T, class Container >
		bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.get_c() >= rhs.get_c());}
}
#endif
