#include "include/include.hpp"


int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ft_container <container>/all" << std::endl;
		return 0;
	}
	std::string tmp = av[1];
	if (tmp == std::string("vector"))
		test_vector();
	if (tmp == std::string("map"))
		test_map();
	if (tmp == std::string("set"))
		test_set();
	if (tmp == std::string("stack"))
		test_stack();
}
