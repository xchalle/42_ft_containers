typedef NAMESPACE::map<std::string, std::string>::value_type _P;

test_map()
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
	NAMESPACE::map<std::string, std::string> m4(m1.begin, m1.last);
	std::cout << "map construct iterator range :" <<std::endl;
	print_map(m4);

}
