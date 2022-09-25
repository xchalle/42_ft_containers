#include "../include/include.hpp"

static void test_non_member()
{
	NAMESPACE::map<int, int> a;
	a[1] = 0;
	a[2] = 0;
	a[3] = 0;
	a[4] = 0;
	a[5] = 0;
	a[6] = 0;
	a[7] = 0;
	NAMESPACE::map<int, int> b;
	b[1] = 0;
	b[2] = 0;
	b[3] = 8;
	b[4] = 9;
	b[5] = 1;
	b[6] = 3;
	b[7] = 0;
	std::cout << "first map" << std::endl;
	print_map(a);
	std::cout << "second map" << std::endl;
	print_map(b);
	std::cout << "first map == second map" << (a == b) << std::endl;
	std::cout << "first map != second map" << (a != b) << std::endl;
	std::cout << "first map <= second map" << (a <= b) << std::endl;
	std::cout << "first map >= second map" << (a >= b) << std::endl;
	std::cout << "first map < second map" << (a < b) << std::endl;
	std::cout << "first map > second map" << (a > b) << std::endl;
	std::cout << "swap map" << std::endl;
	NAMESPACE::swap(a, b);
	std::cout << "first map" << std::endl;
	print_map(a);
	std::cout << "second map" << std::endl;
	print_map(b);
}

void map_non_member()
{
	        std::cout <<"##########NON_MEMBER##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------non_member--------------" << std::endl;
        std::cout << std::endl;
        test_non_member();

}
