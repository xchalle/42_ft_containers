#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a;
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::vector<int>::iterator it = a.begin();
        a.push_back(7);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::cout << a[0] << std::endl;
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        a.push_back(8);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::cout << a[1] << std::endl;
        a.insert(a.begin() + 2, 10, 9);
        std::cout << a.size() << std::endl;
        std::cout << a.capacity() << std::endl;
        std::vector<int>::iterator ite = a.end();
        for ( std::vector<int>::iterator it = a.begin(); it != ite; it++)
                std::cout << *it << std::endl;                                       
        std::cout << a.size() << std::endl;
	(void)it;
	}
