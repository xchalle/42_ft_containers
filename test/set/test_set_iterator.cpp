#include "../include/include.hpp"

#define TBH 10

void test_iterator()
{
        NAMESPACE::set<int> a;
	for (int i; i < TBH; i++)
		a.insert(i);
        a.insert(11);
	print_set(a);
        NAMESPACE::set<int>::iterator it = a.begin();
        NAMESPACE::set<int>::const_iterator ite = a.end();
        NAMESPACE::set<int>::reverse_iterator rit = a.rbegin();
        NAMESPACE::set<int>::const_reverse_iterator rite = a.rend();
        std::cout << "it == ite" << (it == ite) <<std::endl;
	std::cout << "it != ite" << (it != ite) <<std::endl;
        std::cout << "set contain:" << std::endl;
        for (; it != ite; it++)
                std::cout << *it << std::endl;
        std::cout << "reverse set contain:" << std::endl;
        for (; rit != rite; rit++)
                std::cout << *rit << std::endl;

        std::cout << " iterator++/--:" << std::endl;
	it--;
	++it;
	--it;
                std::cout << *it << std::endl;
        std::cout  << std::endl;
}
void set_iterator()
{
        std::cout <<"##########ITERATOR##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------iterator--------------" << std::endl;
        std::cout << std::endl;
        test_iterator();
}
