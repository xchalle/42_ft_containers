#include <iterator>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

	int main ()
{
	try {
	std::vector<int> a(9, 600);
	int i = std::distance(a.end(), a.begin());
	(void)i;
	}
	catch(std::exception& e) {std::cout << e.what();}

  return 0;

}

