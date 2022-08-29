#include <iterator>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

int main()
{
	ft::vector<int> a;
	//std::cout << ft::enable_if<ft::is_integral<int>::value, bool>::type << std::endl;
//		std::cout << ft::enable_if<!ft::is_integral<ft::vector<int>>::value, bool>::type << std::endl;
//		std::cout << std::enable_if<!std::is_integral<std::vector<int>>::value, bool> << std::endl;
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        ft::vector<int>::iterator it = a.begin();
        a.push_back(9);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::cout << a[0] << std::endl;
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(6);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::cout << a[1] << std::endl;
	a.insert(a.begin() + 2, 10, 9);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::cout << a.size() << std::endl;
	ft::vector<int> b;
	b.push_back(5);
	b.push_back(5);
	b.insert(b.begin() + 1, a.begin(), a.end());
	std::cout << "A =>" << std::endl;
	ft::vector<int>::iterator ite = a.end();
	for ( ft::vector<int>::iterator it = a.begin(); it != ite; it++)
		std::cout << *it << std::endl;
	std::cout << "B =>" << std::endl;
	ft::vector<int>::iterator ite2 = b.end();
	for ( ft::vector<int>::iterator it2 = b.begin(); it2 != ite2; it2++)
		std::cout << *it2 << std::endl;
	//std::cout << *it << std::endl;
/*	ft::vector<int> vec(9, 1);
	ft::vector<int> vec2(3, 2);
	//vec.push_back(8);
	ft::vector<int>::iterator rit(vec.begin());
	ft::vector<int>::iterator eit(vec.end());
	ft::vector<int>::iterator rit2(vec2.begin());
	ft::vector<int>::iterator eit2(vec2.begin());
	rit = rit + 6;
	//vec.insert(rit, 2, (int)6);
	rit = vec.erase(rit);
	ft::vector<int>::iterator bit(vec.begin());
	//rit--;
	//vec.push_back(8);
	while (bit != eit)
	{
		std::cout << *bit << std::endl;
		bit++;
	}
	//std::cout << *rit << std::endl;
	//rit = rit - 2;
	//std::cout << *rit << std::endl;*/
/*	ft::vector<int> vec(6, 8);
	std::cout << "size=" << vec.size() << std::endl;
	std::cout << vec.print_test() << std::endl;
	ft::random_access_iterator<int> ite(vec.begin());
	std::cout << "test = " << *vec.data() << std::endl;
	std::cout << *ite << std::endl;
	ite++;
	std::cout << *ite << std::endl;
	ite--;
	std::cout << *ite << std::endl;
	ft::reverse_iterator<ft::random_access_iterator<int>> rite(ite);
	rite--;
	std::cout << "lala" << *rite << std::endl;
	rite = rite - 3;
	std::cout << *rite << std::endl;*/
	//ft::random_access_iterator<int> ite();
	//ite = vec.begin();
}
