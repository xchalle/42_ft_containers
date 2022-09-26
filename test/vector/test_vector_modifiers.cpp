#include "../include/include.hpp"

#define TBH 10

typedef int T;

static void test_modifier()
{
	NAMESPACE::vector<T> a;
	std::cout << " vector1.insert(vector1.end(), T& value) " <<std::endl;
	for(T i = 0; i < TBH; i++)
                a.insert(a.end(), i);
	NAMESPACE::vector<T> b;
	std::cout << " vector2.insert(vector2.end(), vector1.begin(), vector1.end()) " <<std::endl;
	b.insert(b.end(),a.begin(), a.end());
	std::cout << " vector2.insert(vector2.end(),  size_type, T& value) " <<std::endl;
	b.insert(b.end(), TBH, 5);
	std::cout << " vector2.erase(vector2.first(),  vector2.last()) " <<std::endl;
	b.erase(b.end() - TBH, b.end());
	std::cout << " vector2.erase(vector2.iterator()) " <<std::endl;
	b.erase(b.end());
	std::cout << " vector2.pop_back() " <<std::endl;
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	b.pop_back();
	std::cout << "print vector 1" <<std::endl;
	print_vector(a);
	std::cout << "print vector 2" <<std::endl;
	print_vector(b);
	b.resize(TBH, 10);
	b.swap(a);
	std::cout << "print vector 1" <<std::endl;
	print_vector(a);
	std::cout << "print vector 2" <<std::endl;
	print_vector(b);
	b.assign(a.begin(), a.end());
	a.assign(TBH, 11);
	std::cout << "print vector 1" <<std::endl;
	print_vector(a);
	std::cout << "print vector 2" <<std::endl;
	print_vector(b);
	a.clear();
	b.clear();
	std::cout << "print vector 1" <<std::endl;
	print_vector(a);
	std::cout << "print vector 2" <<std::endl;
	print_vector(b);
}

void vector_modifiers()
{
	std::cout <<"##########MODIFIERS##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------insert/clear/erase/pop_back/swap/assign--------------" << std::endl;
        std::cout << std::endl;
        test_modifier();

}
