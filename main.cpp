#include <vector>
#include "vector.hpp"
#include <ostream>
#include <iostream>

int main ()
{   
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
    
  it = myvector.begin();
  it = myvector.insert( it , 200 );
  
  myvector.insert(it,2,300);
  
  // "it" no longer valid, get a new one:
  it = myvector.begin();
  
  ft::vector<int> anothervector(2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert(myvector.begin(), myarray, myarray+3);

  cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "--DIFF---"<< std::endl;

  std::vector<int> urvector (3,100);
  std::vector<int>::iterator itu;
    
  itu = urvector.begin();
  itu = urvector.insert ( itu , 200 );
  
  urvector.insert (it,2,300);
  
  // "it" no longer valid, get a new one:
  itu = urvector.begin();
  
  vector<int> anothervector (2,400);
  urvector.insert (itu+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  urvector.insert (urvector.begin(), myarray, myarray+3);

  cout << "urvector contains:";
  for (itu=urvector.begin(); itu<urvector.end(); itu++)
    std::cout << ' ' << *itu;
  std::cout << '\n';
  return 0;
}
