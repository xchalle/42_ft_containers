#include "../include/include.hpp"

#define TBH 10

typedef int T;

static void test_at_operator()
{
	NAMESPACE::vector<T> a;
	for(T i = 0; i < TBH; i++)
		a.push_back(i);
	std::cout << " print vector.at(i) " <<std::endl;
	for(T i = 0; i < TBH; i++)
		std::cout << " at(" <<i<<") = "<< a.at(i) <<std::endl;
	try {
		a.at(TBH + 10);
	}
	catch( const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << " print vector[i] " <<std::endl;
	for(T i = 0; i < TBH; i++)
		std::cout << " vector[" <<i<<"] = "<< a[i] <<std::endl;
}

static void test_front_back_data()
{
	NAMESPACE::vector<T> a;
	for(T i = 0; i < TBH; i++)
		a.push_back(i);
	std::cout << " print vector.front() " <<std::endl;
		std::cout << a.front() <<std::endl;
	std::cout << " print vector.back() " <<std::endl;
		std::cout << a.back() <<std::endl;
	std::cout << " print vector.data() " <<std::endl;
	T* array = a.data();
	for(T i = 0; array[i]; i++)
		std::cout << " array[" <<i<<"] = "<< array[i] <<std::endl;
}

void vector_elem_access()
{
	std::cout <<"##########ELEMENT_ACCESS##########" << std::endl;
        std::cout << std::endl;
        std::cout <<"----------operator[]/at--------------" << std::endl;
        std::cout << std::endl;
        test_at_operator();
        std::cout <<"----------front/back/data--------------" << std::endl;
        std::cout << std::endl;
        test_front_back_data();

}
