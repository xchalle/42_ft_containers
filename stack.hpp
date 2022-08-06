#ifndef STACK_HPP
#define STACK_HPP

namespace ft{
	template< class T, class Container = std::deque<T>>
	class stack
	{
		public:
		typedef Container container_type;
		typedef Container::value_type value_type;
		typedef Container::size_type size_type;
		typedef Container::reference reference;
		typedef Container::const_reference const_reference;

		explicit stack( const Container& cont = Container() ) : c(cont)
		{}
		stack( const stack& other )
		{
			*this = other;
		}
		stack& operator=( const stack& other )
		{
			c = other.c;
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
		private:

		container_type c;
	}
	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c == rhs.c);}
	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c != rhs.c);}
	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c < rhs.c);}
	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c <= rhs.c);}
	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c > rhs.c);}
	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{ return (lhs.c >= rhs.c);}
}
