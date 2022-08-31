#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include "utils.hpp"
#include "iterator.hpp"
#include "vector.hpp"

class Awesome {
  
          public:
  
                  Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allo    cator (which calls the copy constructor)
                  Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
                  Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
                  virtual ~Awesome(void) {}
  
                  Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
                  bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
                  bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
                  bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
                  bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
                  bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
                  bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
                  void operator+=(int rhs){ _n += rhs; }
                  int get( void ) const { return this->_n; }
  
          private:
  
                  int _n;
  };
  
  std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get    (); return o; }

	int main ()
{
	/*long a = 1;
	long b = 1; 
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;*/
/*	std::vector<int> a(9, 1);

	std::cout << "cap=" << a.capacity() << std::endl;
	a.insert(a.begin(), 6, 12);
	std::cout << "cap=" << a.capacity() << std::endl;
	std::vector<int>::iterator it=a.begin();
	while (it != a.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "top " << std::endl;
	std::vector<int> b;
	std::cout << "cap=" << b.capacity() << std::endl;
	b.insert(b.begin(), a.begin(), a.end());
	std::cout << "cap=" << b.capacity() << std::endl;

*/
	std::vector<int> a(21, 1);
	std::vector<int> b(3, 2);
	a.assign(300, 10); 
	std::cout << "a cap = " << a.capacity() <<std::endl;
		std::cout << "b cap = " << b.capacity() <<std::endl;
}

