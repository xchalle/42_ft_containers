#include "../include/include.hpp"

#define TBH 10
typedef int T;

static void test_non_member()
{
	NAMESPACE::vector<T> vec1(10, 0);
	NAMESPACE::vector<T> vec2(11, 0);
	std::cout << "vec1 == vec2" <<( vec1 == vec2) <<std::endl;
        std::cout << "vec1 != vec2" <<( vec1 != vec2) <<std::endl;
        std::cout << "vec1 <= vec2" <<( vec1 <= vec2) <<std::endl;
        std::cout << "vec1 >= vec2" <<( vec1 >= vec2) <<std::endl;
        std::cout << "vec1 < vec2" << (vec1 < vec2) <<std::endl;
        std::cout << "vec1 > vec2" << (vec1 > vec2) <<std::endl;
	std::cout << "non member functions swap:" << std::endl;
	std::cout << std::endl;
	std::cout << "before swap:" << std::endl;
	std::cout <<"vec1.size= " << vec1.size() <<std::endl;
	std::cout <<"vec2.size= " << vec2.size() <<std::endl;
	NAMESPACE::swap(vec1, vec2);
	std::cout << "before swap:" << std::endl;
	std::cout <<"vec1.size= " << vec1.size() <<std::endl;
	std::cout <<"vec2.size= " << vec2.size() <<std::endl;
}

void vector_non_member()
{
	        std::cout <<"##########NON_MEMBER##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------non_member--------------" << std::endl;
        std::cout << std::endl;
        test_non_member();

}
