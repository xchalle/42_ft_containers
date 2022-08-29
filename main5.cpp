#include <iterator>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "stack.hpp"

	int main ()
{
	ft::vector<int> a(5, 8);
	ft::vector<int> b(a);
	ft::vector<int>::iterator it = b.begin();
	ft::vector<int>::iterator iti = a.begin();
	while(iti != a.end())
	{
		std::cout << *iti << std::endl;
		iti++;
	}
	while(it != b.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	
/*	ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';*/

  return 0;
}

