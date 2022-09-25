#include "../include/include.hpp"

typedef NAMESPACE::map<std::string, std::string>::value_type _P;
typedef std::string T;

static void iterator_map()
{
        NAMESPACE::map<std::string, std::string> m1;
        std::cout << "map1 contain:" <<std::endl;
        print_map(m1);
        std::cout << "inserting one: "<< m1.insert(_P("1", "one")).second << std::endl;
        std::cout << "inserting two: "<< m1.insert(_P("2", "two")).second << std::endl;
        std::cout << "inserting three: "<< m1.insert(_P("3", "three")).second << std::endl;
        std::cout << "inserting four: "<< m1.insert(_P("4", "four")).second << std::endl;
        std::cout << "inserting four: "<< m1.insert(_P("5", "five")).second << std::endl;
        NAMESPACE::map<T, T>::iterator it = m1.begin();        NAMESPACE::map<T, T>::const_iterator ite = m1.end();
        NAMESPACE::map<T, T>::reverse_iterator rit = m1.rbegin();
        NAMESPACE::map<T, T>::const_reverse_iterator rite = m1.rend();
        std::cout << "map content:" << std::endl;
        for (;it != ite; it++)
                std::cout << it->second << std::endl;
        std::cout << "map reverse_content:" << std::endl;
        for (;rit != rite; rit++)
                std::cout << rit->second << std::endl;
	std::cout << "it == ite" << (it == ite) << std::endl;
	std::cout << "it != ite" << (it != ite) << std::endl;
}

void map_iterator()
{
        std::cout <<"##########ITERATOR##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------iterator--------------" << std::endl;
        std::cout << std::endl;
        iterator_map();

}
