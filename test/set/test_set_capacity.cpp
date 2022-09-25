#include "../include/include.hpp"

static void             test_size(void)
{
        std::cout << std::endl;
        std::cout << ">> Test size function" << std::endl;
        std::cout << std::endl;
        
        NAMESPACE::set<int>                  s1;
        NAMESPACE::set<char>                 s2;
        
        std::cout << ">> Push 4 elem in s1" << std::endl;
        s1.insert(11);
        s1.insert(12);
        s1.insert(13);
        s1.insert(14);
	std::cout << "s1.size() = " << s1.size() << std::endl;
	std::cout << "s2.size() = " << s2.size() << std::endl;
        
	std::cout << std::endl;
}

static void             test_max_size(void)
{
        std::cout << std::endl;
	std::cout << ">> Test max size function" << std::endl;
	std::cout << std::endl;
        NAMESPACE::set<bool>	boolean;
	NAMESPACE::set<std::string>	strs;
        
	strs.insert("string");
        boolean.insert(true); 
        boolean.insert(false);
        boolean.insert(true);
        
        print_set(boolean);
        print_set(strs);
        
        std::cout << "nbrs.max_size() = " << boolean.max_size() << std::endl;
        std::cout << "strs.max_size() = " << strs.max_size() << std::endl;
        
        std::cout << std::endl;
}

static void             test_empty(void)
{
        NAMESPACE::set<int>                          empty_set;
        NAMESPACE::set<int>                  filled_set;


	filled_set.insert(1);
	filled_set.insert(1);
	filled_set.insert(1);
	filled_set.insert(1);
        std::cout << std::endl;
        std::cout << ">> Test empty function" << std::endl;
        std::cout << std::endl;

        std::cout << ">> empty set" << std::endl;
        print_set(empty_set);
        std::cout << ">> filled set" << std::endl;
        print_set(filled_set);

        std::cout << "empty_set.empty() = "<< empty_set.empty() << std::endl;
        std::cout << "filled_set.empty() = "<< filled_set.empty() << std::endl;

        std::cout << std::endl;
}

