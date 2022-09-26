#include "../include/include.hpp"

static void		test_key_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test key_comp function" << std::endl;
	std::cout << std::endl;
	NAMESPACE::map<int, int>::key_compare			compare;
	NAMESPACE::map<int, int>						c1;

	compare = c1.key_comp();
	std::cout << "compare = c1.key_comp()" << std::endl << std::endl;

	std::cout << "compare(1, 5) = " << compare(1, 5) << std::endl;
	std::cout << "compare(6, 5) = " << compare(6, 5) << std::endl;

	std::cout << std::endl;
}

static void		test_value_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test value_comp function" << std::endl;
	std::cout << std::endl;
	NAMESPACE::map<int, int>						c1;
	NAMESPACE::map<int, int>::iterator				it;
	NAMESPACE::map<int, int>::iterator				it_2;
	

	c1[1] = 1;
	c1[2] = 2;
	c1[3] = 3;
	c1[4] = 4;

	print_map(c1);
	std::cout << "it = c1.find(2)" << std::endl;
	it = c1.find(2);
	std::cout << "it_2 = c1.find(4)" << std::endl << std::endl;
	it_2 = c1.find(4);

	std::cout << "c1.value_comp()(*it, *it_2) = "
		<< c1.value_comp()(*it, *it_2) << std::endl;
	std::cout << "c1.value_comp()(*it_2, *it) = "
		<< c1.value_comp()(*it_2, *it) << std::endl;

	std::cout << std::endl;
}

void map_observers()
{
	        std::cout <<"##########OBSERVERS##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------value_comp--------------" << std::endl;
        std::cout << std::endl;
        test_value_comp();
        std::cout <<"----------key_comp--------------" << std::endl;
        std::cout << std::endl;
        test_key_comp();

}
