#include "../include/include.hpp"

static void             test_size(void)
{
        std::cout << std::endl;
        std::cout << ">> Test size function" << std::endl;
        std::cout << std::endl;

        NAMESPACE::map<int, std::string>                  s1;
        NAMESPACE::map<int, std::string>                 s2;

        std::cout << ">> Push 4 elem in s1" << std::endl;
        s1[1] = "11";
        s1[2] = "tzo";
        s1[3] = "three";
        s1[4] = "four";
        std::cout << "s1.size() = " << s1.size() << std::endl;
	std::cout << "s2.size() = " << s2.size() << std::endl;
	std::cout << std::endl;
}

static void             test_max_size(void)
{                                                             std::cout << std::endl;                             std::cout << ">> Test max size function" << std::endl;
        std::cout << std::endl;
	NAMESPACE::map<int, std::string>                         s1;

        s1[1] = "11";
        s1[2] = "tzo";
        s1[3] = "three";
        s1[4] = "four";


        std::cout << "nbrs.max_size() = " << s1.max_size() << std::endl;
        
        std::cout << std::endl;
}

static void             test_empty(void)
{
        NAMESPACE::map<int, std::string>                          s2;
        NAMESPACE::map<int, std::string>                  s1;

        s1[1] = "11";

        std::cout << std::endl;
        std::cout << ">> Test empty function" << std::endl;
        std::cout << std::endl;

	std::cout << "empty map" << std::endl;
        print_map(s2);
	std::cout << "filled map" << std::endl;
        print_map(s1);

        std::cout << "s2.empty() = "<< s2.empty() << std::endl;
        std::cout << "s1.empty() = "<< s1.empty() << std::endl;

        std::cout << std::endl;
}

void map_capacity()
{
	test_empty();
	test_max_size();
	test_size();
}
