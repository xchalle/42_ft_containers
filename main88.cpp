#include <utility>
#include <map>
#include <iostream>
//#include "map.hpp"
#include "set.hpp"

int main()
{
	ft::set<int> a;
	a.insert(1);
	a.insert(8);
	a.insert(9);
	a.insert(6);
	a.insert(7);
	a.insert(17);
	a.insert(0);
	a.insert(2);
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
	a.test();
}
