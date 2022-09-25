#include "../include/include.hpp"


typedef NAMESPACE::map<std::string, std::string>::value_type _P;
typedef std::string T;

void insert_erase_map()
{
        NAMESPACE::map<std::string, std::string> m1;
        std::cout << "map1 contain:" <<std::endl;
        print_map(m1);
        std::cout << "inserting one: "<< m1.insert(_P("1", "one")).second << std::endl;
        std::cout << "inserting two: "<< m1.insert(_P("2", "two")).second << std::endl;
        std::cout << "inserting three: "<< m1.insert(_P("3", "three")).second << std::endl;
        std::cout << "inserting four: "<< m1.insert(_P("4", "four")).second << std::endl;
        std::cout << "inserting four: "<< m1.insert(_P("5", "five")).second << std::endl;
        std::cout << "insert an existing pair" << std::endl;
        std::cout << "inserting four: "<< m1.insert(_P("5", "cinq")).second << std::endl;
        
        std::cout << "map1 contain:" <<std::endl;
        print_map(m1);
        NAMESPACE::map<std::string, std::string> m2;
        std::cout << "insert it range m2.insert(++(m1.begin()), --(m1.end())):" <<std::endl;
        m2.insert(++(m1.begin()), --(m1.end()));
        print_map(m2);
        std::cout << "erase the first elem by pos:" <<std::endl;
        m1.erase(m1.begin());
        print_map(m1);
        std::cout << "erase the new first elem by key:" <<std::endl;
        m1.erase("2");
        print_map(m1);
        std::cout << "erase all elem it range:" <<std::endl;
        m1.erase(m1.begin(), m1.end());
        print_map(m1);

        std::cout << "create third map:" <<std::endl;
        NAMESPACE::map<std::string, std::string> m3;
        print_map(m3);
        std::cout << "inserting one: "<< m3.insert(_P("r", "ogifdo")).second << std::endl;
        std::cout << "inserting two: "<< m3.insert(_P("fdlsa", "tfd")).second << std::endl;
        std::cout << "inserting three: "<< m3.insert(_P("fdjsa", "tfdols")).second << std::endl;
        std::cout << "inserting four: "<< m3.insert(_P("444448723", "rouf")).second << std::endl;
        std::cout << "inserting four: "<< m3.insert(_P("5555", "evif")).second << std::endl;
        std::cout << "swap map:" <<std::endl;
	m1.swap(m3);
        std::cout << "map1:" <<std::endl;
        print_map(m1);
        std::cout << "map3:" <<std::endl;
        print_map(m3);
	m1.clear();
	m2.clear();
        std::cout << "map3 after clear:" <<std::endl;
        print_map(m3);
        std::cout << "map1 after clear:" <<std::endl;
        print_map(m1);
}

void map_modifier()
{
	        std::cout <<"##########MODIFIER##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------all-in one--------------" << std::endl;
        std::cout << std::endl;
        insert_erase_map();

}
