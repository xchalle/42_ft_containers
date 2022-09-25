#include "../include/include.hpp"

#define TBH 10

typedef int T;

static void test_non_member()
{
	NAMESPACE::set<T> myset1;
	for(T i = 0; i < TBH; i++)
        	myset1.insert( i);
	NAMESPACE::set<T> myset2;
	for(T i = 0; i < TBH + 1; i++)
        	myset2.insert( i);
 	std::cout << "myset1 == myset2" << (myset1 == myset2) <<std::endl;
        std::cout << "myset1 != myset2" << (myset1 != myset2) <<std::endl;
        std::cout << "myset1 <= myset2" << (myset1 <= myset2) <<std::endl;
        std::cout << "myset1 >= myset2" << (myset1 >= myset2) <<std::endl;
        std::cout << "myset1 < myset2" << (myset1 < myset2) <<std::endl;
        std::cout << "myset1 > myset2" << (myset1 > myset2) <<std::endl;
        std::cout << "non member functions swap:" << std::endl;
        std::cout << std::endl;
        std::cout << "before swap:" << std::endl;
        std::cout <<"myset1.size= " << myset1.size() << std::endl;
        std::cout <<"myset2.size= " << myset2.size() << std::endl;
	NAMESPACE::swap(myset1, myset2);
        std::cout << "before swap:" << std::endl;
        std::cout <<"myset1.size= " << myset1.size() << std::endl;                 
        std::cout <<"myset2.size= " << myset2.size() << std::endl;   

}
