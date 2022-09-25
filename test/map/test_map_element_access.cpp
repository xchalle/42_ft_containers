#include "../include/include.hpp"

static void		test_subscript_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> test operator[]" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<int, std::string>		c1;

	display_map(c1);
	std::cout << "c1[3] = \"three\"" << std::endl;
	std::cout << "c1[10] = \"ten\"" << std::endl << std::endl;

	c1[3] = "three";
	c1[10] = "ten";

	display_map("c1", c1);
	std::cout << "c1[10] = " << c1[10] << std::endl;

	std::cout << "c1[10] = \"dix\"" << std::endl << std::endl;
	c1[10] = "dix";

	display_map("c1", c1);
}

void map_elem_access()
{
	std::cout <<"##########ELEMENT_ACCESS##########" << std::endl;
	std::cout << std::endl;
	std::cout <<"----------operator[]--------------" << std::endl;
	std::cout << std::endl;
	test_subscript_operator();
}
