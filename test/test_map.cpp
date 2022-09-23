#include "include/include.hpp"

typedef NAMESPACE::map<std::string, std::string>::value_type _P;
typedef std::string T;

void print_map(NAMESPACE::map<T,T> &mymap)
{
	for(NAMESPACE::map<T, T>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << "["<< it->first << "]"<< "->" << "[" << it->second << "]" << std::endl;
	std::cout << std::endl << "size = "<< mymap.size() <<std::endl;
}

void construct_map()
{
	NAMESPACE::map<std::string, std::string> m1;
	std::cout << "map1 contain:" <<std::endl;
	print_map(m1);
	m1["1"] = "un";
	m1["2"] = "deux";
	m1["3"] = "trois";
	m1["4"] = "auqwtre";
	m1["5"] = "cinq";
	std::cout << "map1 contain now:" <<std::endl;
	print_map(m1);
	NAMESPACE::map<std::string, std::string> m2(m1);
	std::cout << "map copy construct contain :" <<std::endl;
	print_map(m2);
	NAMESPACE::map<std::string, std::string> m3 = m1;
	std::cout << "map assignement operator :" <<std::endl;
	print_map(m3);
	NAMESPACE::map<std::string, std::string> m4(m1.begin(), m1.end());
	std::cout << "map construct iterator range :" <<std::endl;
	print_map(m4);
}

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

}

void test_map()
{
	std::cout << "############CONSTRUCT_MAP############" << std::endl;
	construct_map();
	std::cout << "############INS_ERAS_MAP############" << std::endl;
	insert_erase_map();
}
