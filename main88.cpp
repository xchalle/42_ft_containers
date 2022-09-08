#include <utility>
#include <map>
#include <iostream>
#include "map.hpp"

int main()
{
	ft::map<int, int> a;
	ft::pair<int , int> b(1, 9);
	ft::pair<int , int> c(8, 19);
	ft::pair<int , int> d(7, 29);
	ft::pair<int , int> u(0, 39);
	a.insert(b);
	a.insert(c);
	a.insert(d);
	a.insert(u);
//	a.printTree();
	a.test();
}
