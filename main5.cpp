#include <iterator>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

	int main ()
{
	        ft::vector<int> myvector (3,100);
        ft::vector<int>::iterator it;

  it = myvector.begin();
  std::cout << myvector.capacity() << std::endl;
  it = myvector.insert( it , 200 );
  std::cout << myvector.capacity() << std::endl;
  myvector.insert( it, 2, 300 );
  std::cout << myvector.capacity() << std::endl;

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector(2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());
  std::cout << myvector.capacity() << std::endl;

  int myarray [] = { 501,502,503 };
  myvector.insert(myvector.begin(), myarray, myarray+3);
  std::cout << myvector.capacity() << std::endl;

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "--DIFF---"<< std::endl;

  std::vector<int> urvector (3,100);
  std::vector<int>::iterator itu;

  itu = urvector.begin();
  std::cout << urvector.capacity() << std::endl;
  itu = urvector.insert ( itu , 200 );
  std::cout << urvector.capacity() << std::endl;

  urvector.insert ( itu , 2, 300 );
  std::cout << urvector.capacity() << std::endl;

  // "it" no longer valid, get a new one:
  itu = urvector.begin();

  std::vector<int> anothervector2 (2,400);
  urvector.insert (itu+2,anothervector2.begin(),anothervector2.end());
  std::cout << urvector.capacity() << std::endl;

  int urarray [] = { 501,502,503 };
  urvector.insert (urvector.begin(), urarray, urarray+3);
  std::cout << urvector.capacity() << std::endl;

  std::cout << "urvector contains:";
  for (itu=urvector.begin(); itu<urvector.end(); itu++)
    std::cout << ' ' << *itu;
  std::cout << '\n';
  return 0;

}

