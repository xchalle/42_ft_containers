#include <iostream>
#include <iterator>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

int main()
{
	std::vector<int> vec(9, 1);
	std::vector<int> vec2(3, 2);
	//vec.push_back(8);
	std::vector<int>::iterator rit(vec.begin());
	std::vector<int>::iterator eit(vec.end());
	std::vector<int>::iterator rit2(vec2.begin());
	std::vector<int>::iterator eit2(vec2.begin());
	rit = rit + 6;
	//vec.insert(rit, 2, (int)6);
	rit = vec.erase(rit);
	std::vector<int>::iterator bit(vec.begin());
	//rit--;
	//vec.push_back(8);
	while (bit != eit)
	{
		std::cout << *bit << std::endl;
		bit++;
	}
	//std::cout << *rit << std::endl;
	//rit = rit - 2;
	//std::cout << *rit << std::endl;
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
