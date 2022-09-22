#ifndef COMPARE_HPP
#define COMPARE_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
		struct binary_function
		{
			typedef Arg1 first_argument_type;
			typedef Arg2 second_argument_type;
			typedef Result result_type;
		};
	template <typename T>
		struct less : public binary_function< T, T, bool >
	{
		bool operator() (const T x, const T y) const
		{
			return (x < y);
		}
	};
	template <typename T>
		struct greater : public binary_function< T, T, bool >
	{
		bool operator() (const T x, const T y) const
		{
			return (x > y);
		}
	};
}
#endif
