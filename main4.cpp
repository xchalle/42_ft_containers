
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"

template <class T>
void	print(ft::vector<ft::vector<T> >& lst)
{
	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main()    
{    
//	std::cout << "\nINSERT\n";    
	ft::vector<std::string>  insert_in_me;    
        for (size_t i = 0; i < 15; i++)    
                insert_in_me.push_back(std::to_string(i) + " I love hbaudet\n");
	std::cout << "after push_back, before at\n";    
       // for (size_t i = 0; i < insert_in_me.size(); i++)    
         //       std::cout << insert_in_me.at(i) << ' ';    
	std::cout << '\n';    
    
	ft::vector<std::string>::iterator        tmp;    
        tmp = insert_in_me.begin() + 14;    
        insert_in_me.insert(tmp, 8, "Norminet\n");    
        for (size_t i = 0; i < insert_in_me.size(); i++)    
                std::cout << insert_in_me.at(i) << ' ';    
	std::cout << '\n';    
    
	ft::vector<std::string>::const_iterator const_it(insert_in_me.begin());    
	std::cout << "Const it : " << std::endl;    
	std::cout << *const_it << '\n';    
//      *const_it = 89; // Does not compile because it's a const_iterator


  return 0;
}
