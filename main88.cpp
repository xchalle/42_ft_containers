#include <utility>
#include <map>
#include <set>
#include <iostream>
//#include "map.hpp"
#include "set.hpp"

int main()
{
	ft::node<int> toadd(2);
	ft::set<ft::node<int>> b;
	b.insert(toadd);
	ft::set<ft::node<int>>::iterator ib = b.begin();
	std::cout << ib->parent << std::endl;
	std::map<int, int> a;
	a.insert(std::make_pair(1, 9));
	a.insert(std::make_pair(2, 2));
	std::map<int, int>::iterator it = a.begin();
	//std::pair<int, int> pai = *it;
	std::cout << it->first << std::endl;
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
	/*ft::set<int> a;
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
	}*/
/*	ft::set<int> myset;
	ft::set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it);

  myset.erase (40);

  it = myset.find (60);
  myset.erase (it, myset.end());

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
*/
	/*ft::set<int> a;
	a.erase(a.begin(), a.end());
	ft::set<int>::iterator it = a.begin();
	std::cout << *(it) << std::endl;*/
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
