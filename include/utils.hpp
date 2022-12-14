#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator.hpp"

namespace ft{

	struct nullptr_p 
	{
		nullptr_p()
		{}
		void operator&() const;  // Can't take address of nullptr
		template<class T>
			inline operator T*() const { return 0; }
		template<class C, class T>
			inline operator T C::*() const { return 0; }
	};
	#define nullptr_ nullptr_p()

	template < class InputIt1, class InputIt2>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
		{
			for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
			{
				if (*first1 < *first2) return true;
				if (*first2 < *first1) return false;
			}
			return (first1 == last1) && (first2 != last2);
		};

	template<class InputIt1, class InputIt2, class Compare>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	template<class It>
		typename ft::iterator_traits<It>::difference_type distance(It first, It last)
	{
		typename ft::iterator_traits<It>::difference_type result = 0;
		while (first != last)
		{
			first++;
			result++;
		}
		return result;
	}
 
	template<class InputIt1, class InputIt2>
		bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
		bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2)) 
				return false;
		}
		return true;
	}
}

#endif
