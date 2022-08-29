#include <iterator>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

int main()
{
        ft::vector<int> a;
        //std::cout << a.size() << std::endl;
        //std::cout << a.capacity() << std::endl;
        //ft::vector<int>::iterator it = a.begin();
        a.push_back(9);
	ft::vector<int>::const_iterator tmp = a.begin();
        //std::cout << a.size() << std::endl;
        //std::cout << a.capacity() << std::endl;
        //std::cout << a[0] << std::endl;
/*        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(6);*/
}
