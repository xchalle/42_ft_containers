#include "include/include.hpp"
#include <sys/time.h>

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ft_container <container>/all" << std::endl;
		return 0;
	}
	std::string tmp = av[1];
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long long int time1;
	time1 = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if (tmp == std::string("vector"))
	{
		std::cout << std::endl;
		std::cout <<"TEST VECTOR" << std::endl;
		std::cout << std::endl;
		test_vector();
	}
	if (tmp == std::string("map"))
	{
		std::cout << std::endl;
		std::cout <<"TEST MAP" << std::endl;
		std::cout << std::endl;
		test_map();
	}
	if (tmp == std::string("set"))
	{
		std::cout << std::endl;
		std::cout <<"TEST SET" << std::endl;
		std::cout << std::endl;
		test_set();
	}
	if (tmp == std::string("stack"))
	{
		std::cout << std::endl;
		std::cout <<"TEST STACK" << std::endl;
		std::cout << std::endl;
		test_stack();
	}
	if (tmp == std::string("all"))
	{
		std::cout << std::endl;
		std::cout <<"TEST STACK" << std::endl;
		std::cout << std::endl;
		test_stack();
		std::cout << std::endl;
		std::cout <<"TEST SET" << std::endl;
		std::cout << std::endl;
		test_set();
		std::cout << std::endl;
		std::cout <<"TEST MAP" << std::endl;
		std::cout << std::endl;
		test_map();
		std::cout << std::endl;
		std::cout <<"TEST VECTOR" << std::endl;
		std::cout << std::endl;
		test_vector();
	}
	gettimeofday(&tv, NULL);
	long long int time2;
	time2 = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	std::cout << "execution time : " << (time2 - time1) << "ms" << std::endl;
}
