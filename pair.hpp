#ifndef PAIR_HPP
#define PAIR_HPP

template < class T1, class T2>
struct pair
{
	public:
	T1 first;
	T2 second;
	pair() : first(), second()
	{}
	pair( const T1& x, const T2& y ) : first(x), second(y)
	{}
	template< class U1, class U2 >
	pair( const pair<U1, U2>& p ) : first(p.first), second(p.second)
	{}
	pair& operator=( const pair& other )
	{
		this.first = other.first;
		this.second = other.second;
		return (*this);
	}
};

template<class T1, class T2>
ft::pair<T1, T2> make_pair(T1 t, T2 u)
{
	return (ft::pair<T1, T2>(t, u));
}

template< class T1, class T2 >
bool operator==( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!(lhs == rhs));
}

template< class T1, class T2 >
bool operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
}

template< class T1, class T2 >
bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!(rhs < lhs));
}

template< class T1, class T2 >
bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (rhs < lhs);
}
template< class T1, class T2 >
bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!(lhs < rhs));
}
#endif
