#include <iostream>
#include <iostream>
#include "vector.hpp"

int main()
{
	ft::vector<int> a(4, 6);
	ft::vector<int> b(2, 8);

	b.swap(a);
	ft::vector<int>::iterator it = a.begin();
	ft::vector<int>::iterator ite = b.begin();
	while (it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	while (ite != b.end())
	{
		std::cout << *ite << std::endl;
		ite++;
	}
}
