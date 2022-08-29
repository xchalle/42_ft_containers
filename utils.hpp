#ifndef UTILS_H
#define UTILS_H
#include "iterator.hpp"
namespace ft{

	struct nullptr_p 
	{
		void operator&() const;  // Can't take address of nullptr
		template<class T>
			inline operator T*() const { return 0; }
		template<class C, class T>
			inline operator T C::*() const { return 0; }
	};
	nullptr_p nullptr_a = {};

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
 
	/*template<class It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, ft::random_access_iterator_tag)
	{
		return last - first ;
	}
 
	template<class It>
	typename ft::iterator_traits<It>::difference_type distance(It first, It last)
	{
		return do_distance(first, last, typename ft::iterator_traits<It>::iterator_category());
	}*/
}
#endif
