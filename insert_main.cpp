
#include <vector>
#include <iostream>
#include "vector.hpp"


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


int main ()
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  it = myvector.insert ( it , 300 );
  myvector.insert (it,5,300);
	std::vector<int>::iterator ite = myvector.begin();
	while(ite != myvector.end())
	{
		std::cout << "in " << *ite << std::endl;
		ite++;
	}
  std::cout << myvector.capacity() << std::endl;
  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
