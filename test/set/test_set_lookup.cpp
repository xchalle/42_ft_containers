#include "../include/include.hpp"

#define TBH 11

typedef int T;

static void test_lookup()
{
	NAMESPACE::set<T> a;
	for(T i = 0; i < TBH; i++)
        	a.insert(i + 5); 
	std::cout << "set contain:" << std::endl;
	print_set(a);
	std::cout << "count 0 is in the set " << a.count(0) << std::endl;
	std::cout << "count TBH is in the set " << a.count(TBH) << std::endl;
	std::cout << "find 5  in the set " << *(a.find(5)) << std::endl;
//	std::cout << "diff is ok = find out of the set TBH " << *(a.find(TBH + 128)) << std::endl;
	std::cout << "equal range of 5" << *((a.equal_range(5)).first) << *((a.equal_range(5)).second) << std::endl;
	std::cout << "lower TBH  in the set " << *(a.lower_bound(5)) << std::endl;
	std::cout << "upper TBH  in the set " << *(a.upper_bound(5)) << std::endl;
}

template <typename U>
struct testcomp
{
	bool operator()(const U& x, const U& y)
	{
		std::cout << "this is testcomp" <<std::endl;
		return (x < y);
	}
};

static void test_observer()
{
	
	NAMESPACE::set<T, testcomp<T> > a;
	NAMESPACE::set<T, testcomp<T> >::key_compare key_compare;
	NAMESPACE::set<T, testcomp<T> >::value_compare value_compare;
	key_compare = a.key_comp();
	value_compare = a.value_comp();

	std::cout << "key_comp = " << key_compare(1, 2)<< std::endl;
	std::cout << "value_comp = " << value_compare(1, 2) << std::endl;
}

void set_lookup()
{
	                std::cout <<"##########LOOKUP##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------lookup--------------" << std::endl;
        std::cout << std::endl;
        test_lookup();
        std::cout <<"----------observer--------------" << std::endl;
        std::cout << std::endl;
        test_observer();

}
