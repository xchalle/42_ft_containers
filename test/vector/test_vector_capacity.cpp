#include "../include/include.hpp"

static void		test_size(void)
{
	std::cout << std::endl;
	std::cout << ">> Test size function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::vector<int>			v1;
	NAMESPACE::vector<char>			v2;

	std::cout << ">> Push 4 elem in v1" << std::endl;
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);

	std::cout << "v1.size() = " << v1.size() << std::endl;
	std::cout << "v2.size() = " << v2.size() << std::endl;

	std::cout << std::endl;
}

static void		test_max_size(void)
{
	std::cout << std::endl;
	std::cout << ">> Test max size function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::vector<int>				nbrs;
	NAMESPACE::vector<std::string>			strs(3, "string");

	nbrs.push_back(1);
	nbrs.push_back(2);
	nbrs.push_back(3);

	std::cout << "print vector1" << std::endl;
	print_vector(nbrs);
	std::cout << "print vector2" << std::endl;
	print_vector(strs);

	std::cout << "nbrs.max_size() = " << nbrs.max_size() << std::endl;
	std::cout << "strs.max_size() = " << strs.max_size() << std::endl;

	std::cout << std::endl;
}

static void		test_resize(void)
{
	NAMESPACE::vector<int>		hundreds(3, 100);

	std::cout << std::endl;
	std::cout << ">> Test resize function" << std::endl;
	std::cout << std::endl;

	print_vector(hundreds);

	hundreds.resize(6, 200);
	std::cout << std::endl;
	std::cout << "hundreds.resize(6, 200)" << std::endl;
	std::cout << std::endl;

	print_vector(hundreds);


	hundreds.resize(4);
	std::cout << std::endl;
	std::cout << "hundreds.resize(4)" << std::endl;
	std::cout << std::endl;

	print_vector(hundreds);
}

static void		test_reserve(void)
{
	std::cout << std::endl;
	std::cout << ">> Test reserve function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::vector<int>				nbrs;

	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(2)" << std::endl;
	nbrs.reserve(2);
	
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(10)" << std::endl;
	nbrs.reserve(10);
	
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(nbrs.max_size() + 1) ==> exception" << std::endl;
	try
	{
		nbrs.reserve(nbrs.max_size() + 1);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void		test_capacity(void)
{
	std::cout << std::endl;
	std::cout << ">> Test capacity function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::vector<std::string>		plants;

	print_vector(plants);

	std::cout << "plants.capacity() = " << plants.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "plants.push_back(\"tree\")" << std::endl;
	plants.push_back("tree");
	print_vector(plants);

	std::cout << "plants.capacity() = " << plants.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "plants.push_back(\"tulip\")" << std::endl;
	std::cout << "plants.push_back(\"daisy\")" << std::endl;
	plants.push_back("tulip");
	plants.push_back("daisy");
	print_vector(plants);

	std::cout << "plants.capacity() = " << plants.capacity() << std::endl;
	std::cout << std::endl;
}

static void		test_empty(void)
{
	NAMESPACE::vector<int>				empty_vector;
	NAMESPACE::vector<int>			filled_vector(4, 1);


	std::cout << std::endl;
	std::cout << ">> Test empty function" << std::endl;
	std::cout << std::endl;

	print_vector(empty_vector);
	print_vector(filled_vector);

	std::cout << "empty_vector.empty() = "<< empty_vector.empty() << std::endl;
	std::cout << "filled_vector.empty() = "<< filled_vector.empty() << std::endl;

	std::cout << std::endl;
}

void vector_capacity()
{
	        std::cout <<"##########CAPACITY##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------empty--------------" << std::endl;
        std::cout << std::endl;
        test_empty();
        std::cout <<"----------size--------------" << std::endl;
        std::cout << std::endl;
        test_size();
        std::cout <<"----------max_size--------------" << std::endl;
        std::cout << std::endl;
        test_max_size();
        std::cout <<"----------resize--------------" << std::endl;
        std::cout << std::endl;
        test_resize();
        std::cout <<"----------reserve--------------" << std::endl;
        std::cout << std::endl;
        test_reserve();
        std::cout <<"----------capacity--------------" << std::endl;
        std::cout << std::endl;
        test_capacity();


}
