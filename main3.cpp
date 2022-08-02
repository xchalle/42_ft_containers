#include <iostream>
#include <iterator>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

int main()
{
/*	std::vector<int> vec(3, 1);
	vec.push_back(8);
	std::vector<int>::reverse_iterator rit(vec.rbegin());
	std::cout << *rit << std::endl;
	rit = rit - 2;
	std::cout << *rit << std::endl;*/
	ft::vector<int> vec(6, 8);
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
	std::cout << *rite << std::endl;
	//ft::random_access_iterator<int> ite();
	//ite = vec.begin();
}
