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
		test_vector();
	if (tmp == std::string("map"))
		test_map();
	if (tmp == std::string("set"))
		test_set();
	if (tmp == std::string("stack"))
		test_stack();
	if (tmp == std::string("all"))
	{
		test_stack();
		test_set();
		test_map();
		test_vector();
	}
	gettimeofday(&tv, NULL);
	long long int time2;
	time2 = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	std::cout << "execution time : " << (time2 - time1) << "ms" << std::endl;
}
