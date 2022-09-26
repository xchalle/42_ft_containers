#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <map.hpp>
#include <stack.hpp>
#include <vector.hpp>
#include <set.hpp>

#include <deque>
#include <map>
#include <set>
#include <stack>
#include <vector>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

#include <iostream>
#include <string>

#include <stdlib.h>

void test_map();
void test_vector();
void test_stack();
void test_set();

template <typename T, typename U>
void print_map(const NAMESPACE::map<T, U> &mymap)
{
        for(typename NAMESPACE::map<T, U>::const_iterator it = mymap.begin(); it != mymap.end(); it++)
                std::cout << "["<< it->first << "]"<< "->" << "[" << it->second << "]" << std::endl;
        std::cout << std::endl << "size = "<< mymap.size() <<std::endl;
}

template <typename T>
void print_vector(const NAMESPACE::vector<T> &myvec)
{
        for(typename NAMESPACE::vector<T>::const_iterator it = myvec.begin(); it != myvec.end(); it++)
                std::cout << "["<< *it << "]"<< std::endl;
        std::cout << std::endl << "size = "<< myvec.size() <<std::endl;
}
template <typename T>
void print_set(NAMESPACE::set<T> &myset)
{
        for(typename NAMESPACE::set<T>::iterator it = myset.begin(); it != myset.end(); it++)
                std::cout << "["<< *it << "]"<< std::endl;
        std::cout << std::endl << "size = "<< myset.size() <<std::endl;
}

#endif
