#include "../include/include.hpp"

#define TBH 10
 
typedef int T;
 
void test_modifier()
{   
        NAMESPACE::set<T> a;
        std::cout << " set1.insert(T& value) " <<std::endl;
        for(T i = 0; i < TBH; i++)
                a.insert( i);
        NAMESPACE::set<T> b;
        std::cout << " set2.insert(set1.begin(), set1.end()) " <<std::endl;
        b.insert(a.begin(), a.end());
        std::cout << " set2.insert(iterator = set.end(), T& value) " <<std::endl;
        b.insert(a.end(), 5);
        std::cout << " set2.erase(set2.first(),  set2.last()) " <<std::endl;
        b.erase(--(--b.end()), b.end());
        //std::cout << " set2.erase(set2.iterator()) " <<std::endl;
        //b.erase(b.end());
        //std::cout << " set2.erase(set2.iterator()) " <<std::endl;
        //b.erase(b.end());
	std::cout << "set1.erase(key) = " << a.erase(0)<< std::endl;
	std::cout << "set1.erase(key) = " << a.erase(-1)<< std::endl;
	std::cout << " set2.pop_back() " <<std::endl;
        b.swap(a);
	b.clear();
	a.clear();
}

void set_modifier()
{
	                std::cout <<"##########MODIFIER##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------modifier--------------" << std::endl;
        std::cout << std::endl;
        test_modifier();

}
