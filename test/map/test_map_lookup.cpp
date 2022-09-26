#include "../include/include.hpp"

static void		test_find(void)
{
	std::cout << std::endl;
	std::cout << ">> test find function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<std::string, std::string>				animal_size;
	NAMESPACE::map<std::string, std::string>::iterator		it;

	animal_size["mouse"] = "2 inches";
	animal_size["cat"] = "1 foot";
	animal_size["elephant"] = "5 yards";

	const NAMESPACE::map<std::string, std::string>					const_animal_size(animal_size.begin(), animal_size.end());
	NAMESPACE::map<std::string, std::string>::const_iterator		c_it;

	print_map(animal_size);
	print_map(const_animal_size);

	it = animal_size.find("elephant");
	c_it = const_animal_size.find("elephant");

	std::cout << "it = animal_size.find(\"elephant\")" << std::endl;
	std::cout << "cit = animal_size.find(\"elephant\")" << std::endl << std::endl;

	std::cout << "it->first = " << it->first << std::endl;
	std::cout << "it->second = " << it->second << std::endl << std::endl;

	std::cout << "cit->first = " << c_it->first << std::endl;
	std::cout << "cit->second = " << c_it->second << std::endl;

	std::cout << std::endl;
}

static void		test_count(void)
{
	std::cout << std::endl;
	std::cout << ">> test count function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<int, std::string>		c1;

	c1[1] = "one";
	c1[2] = "two";
	c1[3] = "three";
	c1[4] = "four";
	c1[5] = "five";

        print_map(c1);

	std::cout << "c1.count(4) = " << c1.count(4) << std::endl;
	std::cout << "c1.count(23) = " << c1.count(23) << std::endl;

	std::cout << std::endl;
}

static void		test_lower_bound(void)
{
	std::cout << std::endl;
	std::cout << ">> test lower_bound function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<int, std::string>		c1;

	c1[15] = "fiveteen";
	c1[20] = "twenty";
	c1[25] = "twenty-five";
	c1[30] = "thirty";
	c1[35] = "thirty-five";
	const NAMESPACE::map<int, std::string>		const_c1(c1);

	print_map(c1);

	std::cout << "c1.lower_bound(7)->first) = " << c1.lower_bound(7)->first << std::endl;
	std::cout << "c1.lower_bound(25)->first) = " << c1.lower_bound(25)->first << std::endl;
	std::cout << "c1.lower_bound(32)->first) = " << c1.lower_bound(32)->first << std::endl << std::endl;

	print_map(const_c1);
	std::cout << "const_c1.lower_bound(7)->first) = " << const_c1.lower_bound(7)->first << std::endl;
	std::cout << "const_c1.lower_bound(25)->first) = " << const_c1.lower_bound(25)->first << std::endl;
	std::cout << "const_c1.lower_bound(32)->first) = " << const_c1.lower_bound(32)->first << std::endl;

	std::cout << std::endl;
}

static void		test_upper_bound(void)
{
	std::cout << std::endl;
	std::cout << ">> test upper_bound function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<int, std::string>		c1;

	c1[15] = "fiveteen";
	c1[20] = "twenty";
	c1[25] = "twenty-five";
	c1[30] = "thirty";
	c1[35] = "thirty-five";


	print_map(c1);

	std::cout << "c1.upper_bound(7)->first) = " << c1.upper_bound(7)->first << std::endl;
	std::cout << "c1.upper_bound(25)->first) = " << c1.upper_bound(25)->first << std::endl;
	std::cout << "c1.upper_bound(32)->first) = " << c1.upper_bound(32)->first << std::endl << std::endl;

	const NAMESPACE::map<int, std::string>		const_c1(c1);

	print_map(const_c1);
	std::cout << "const_c1.upper_bound(7)->first) = " << const_c1.upper_bound(7)->first << std::endl;
	std::cout << "const_c1.upper_bound(25)->first) = " << const_c1.upper_bound(25)->first << std::endl;
	std::cout << "const_c1.upper_bound(32)->first) = " << const_c1.upper_bound(32)->first << std::endl;

	std::cout << std::endl;
}

static void		test_equal_range(void)
{
	std::cout << std::endl;
	std::cout << ">> test equal_range function" << std::endl;
	std::cout << std::endl;

	NAMESPACE::map<int, std::string>		c1;
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::iterator, NAMESPACE::map<int, std::string>::iterator>		ret;

	c1[15] = "fiveteen";
	c1[20] = "twenty";
	c1[25] = "twenty-five";
	c1[30] = "thirty";
	c1[35] = "thirty-five";
	print_map(c1);

	std::cout << "ret = c1.equal_range(15)" << std::endl;
	ret = c1.equal_range(15);
	std::cout << "(ret.first)->first = " << (ret.first)->first << std::endl;
	std::cout << "(ret.first)->first = " << (ret.second)->first << std::endl << std::endl;

	std::cout << "ret = c1.equal_range(16)" << std::endl;

	ret = c1.equal_range(16);
	std::cout << "(ret.first)->first = " << (ret.first)->first << std::endl;
	std::cout << "(ret.first)->first = " << (ret.second)->first << std::endl << std::endl;

	const NAMESPACE::map<int, std::string>		const_c1(c1);
	NAMESPACE::pair<NAMESPACE::map<int, std::string>::const_iterator, NAMESPACE::map<int, std::string>::const_iterator>		const_ret;
	
	print_map(const_c1);

	std::cout << "ret = const_c1.equal_range(15)" << std::endl;
	const_ret = const_c1.equal_range(15);
	
	std::cout << "(const_ret.first)->first = " << (const_ret.first)->first << std::endl;
	std::cout << "(const_ret.first)->first = " << (const_ret.second)->first << std::endl << std::endl;

	std::cout << "const_ret = const_c1.equal_range(16)" << std::endl;
	
	const_ret = const_c1.equal_range(16);

	std::cout << "(const_ret.first)->first = " << (const_ret.first)->first << std::endl;
	std::cout << "(const_ret.first)->first = " << (const_ret.second)->first << std::endl;

	std::cout << std::endl;
}

void map_lookup()
{
	        std::cout <<"##########LOOKUP##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------find--------------" << std::endl;
        std::cout << std::endl;

	test_find();
        std::cout <<"----------count--------------" << std::endl;
        std::cout << std::endl;
	test_count();
        std::cout <<"----------lower_bound--------------" << std::endl;
        std::cout << std::endl;
	test_lower_bound();
        std::cout <<"----------upper_bound--------------" << std::endl;
        std::cout << std::endl;
	test_upper_bound();
        std::cout <<"----------equal_range--------------" << std::endl;
        std::cout << std::endl;
	test_equal_range();
}

