#include "../include/include.hpp"

void test_iterator()
{
	NAMESPACE::vector<int> a(10, 10);
	a.push_back(11);
	NAMESPACE::vector<int>::iterator it = a.begin();
	NAMESPACE::vector<int>::const_iterator ite = a.end();
	NAMESPACE::vector<int>::reverse_iterator rit = a.rbegin();
	NAMESPACE::vector<int>::const_reverse_iterator rite = a.rend();
	std::cout << "a == b" << (it == ite) <<std::endl;
	std::cout << "a != b" << (it != ite) <<std::endl;
	std::cout << "a <= b" << (it <= ite) <<std::endl;
	std::cout << "a >= b" << (it >= ite) <<std::endl;
	std::cout << "a < b" << (it < ite) <<std::endl;
	std::cout << "a > b" << (it > ite) <<std::endl;
	std::cout << "vector contain:" << std::endl;
	for (; it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "reverse vector contain:" << std::endl;
	for (; rit != rite; rit++)
		std::cout << *rit << std::endl;
	std::cout << "it[10]" << it[10] <<std::endl;
	std::cout  << std::endl;
	std::cout << "ITERATOR +/-" << std::endl;
	std::cout  << std::endl;
	std::cout << "*it = " << *it <<std::endl;
	it -= 3;
	it += 3;
	it  = it - 5;
	it  = it + 5;
	it  = 5 + it;
	std::cout << "*it = " << *it <<std::endl;
	it  = it - 5;
	std::cout << "ite - it = " << ite - it <<std::endl;
}

void vector_iterator()
{
        std::cout <<"##########ITERATOR##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------iterator--------------" << std::endl;
        std::cout << std::endl;
        test_iterator();

}
