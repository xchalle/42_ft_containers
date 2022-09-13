#include <utility>
#include <map>
#include <set>
#include <iostream>
//#include "map.hpp"
#include "set.hpp"

int main()
{
/*	std::set<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	std::set<int>::iterator it();
	it = a.begin();*/
	/*while (it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}*/
	ft::set<int> a;
	a.insert(1);
	a.insert(3);
	a.insert(5);
	a.insert(7);
	a.insert(9);
	a.insert(11);
	a.insert(13);
	a.insert(15);
	ft::set<int>::iterator it = a.upper_bound(4);
	while (it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	ft::set<int> b;
	b.insert(0);
	b.insert(2);
	b.insert(4);
	b.insert(6);
	b.insert(8);
	b.insert(10);
	b.insert(12);
	b.insert(14);
	ft::set<int>::iterator ib = b.begin();
	while (ib != b.end())
	{
		std::cout << *ib << std::endl;
		ib++;
	}
	a.swap(b);
	ft::set<int>::iterator it2 = a.begin();
	while (it2 != a.end())
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	ft::set<int>::iterator ib2 = b.begin();
	while (ib2 != b.end())
	{
		std::cout << *ib2 << std::endl;
		ib2++;
	}
//	ft::map<int, int> a;
//	ft::pair<int , int> b(1, 9);
//	ft::pair<int , int> c(8, 19);
//	ft::pair<int , int> d(7, 29);
//	ft::pair<int , int> u(0, 39);
//	a.insert(b);
//	a.insert(c);
//	a.insert(d);
//	a.insert(u);
//	a.printTree();
}
