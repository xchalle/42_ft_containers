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
	std::cout << "\nINSERT\n";
	ft::vector<int> test(2, 42);
	ft::vector<ft::vector<int> >    insert_in_me;
        for (int i = 0; i < 15; i++)
        {
		ft::vector<int>     j(2, i);
                insert_in_me.push_back(j);
        }
        for (size_t i = 0; i < insert_in_me.size(); i++)
        {
                for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
                        std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
        }
        
	ft::vector<ft::vector<int> >::iterator  tmp;                 
        test.assign(23, 19);
        tmp = insert_in_me.begin() + 4;
        insert_in_me.insert(tmp, 8, test);
        for (size_t i = 0; i < insert_in_me.size(); i++)
        {
                for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
                        std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
        }

	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


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
	/*std::vector<int> a(21, 1);
	std::vector<int> b(3, 2);
	a.assign(300, 10); 
	std::cout << "a cap = " << a.capacity() <<std::endl;
		std::cout << "b cap = " << b.capacity() <<std::endl;*/
}

