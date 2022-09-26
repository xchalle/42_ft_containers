#include "../include/include.hpp"

typedef int T;

void print_stack(NAMESPACE::stack<T> a)
{
	NAMESPACE::stack<T> tmp = a;
	while(tmp.empty() == 0)
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

void test_stack()
{
	std::cout << "############STACK_CONSTRUCT############" << std::endl;
	NAMESPACE::stack<T> a;
	std::cout << "first stack(empty):" << std::endl;
	print_stack(a);
	std::cout << "############STACK_PUSH############" << std::endl;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	NAMESPACE::stack<T> b(a);
	std::cout << "first stack:" << std::endl;
	print_stack(a);
	std::cout << "second stack:" << std::endl;
	print_stack(b);
	std::cout << "############STACK_OPERATOR=############" << std::endl;
	std::cout << "create third stack" << std::endl;
	NAMESPACE::stack<T> c = a;
	std::cout << "add elem to first stack" << std::endl;
	a.push(6);
	std::cout << "first stack:" << std::endl;
	print_stack(a);
	std::cout << "third stack:" << std::endl;
	print_stack(c);
	std::cout << "############STACK_TOP############" << std::endl;
	std::cout << "acces top first stack:" << a.top() << std::endl;

	std::cout << "############STACK_POP############" << std::endl;
	std::cout << "pop 2 elem of first stack:" << std::endl;
	a.pop();
	a.pop();
	std::cout << "first stack:" << std::endl;
	print_stack(a);
	a.pop();
	a.pop();
	std::cout << "first stack:" << std::endl;
	print_stack(a);
	std::cout << std::boolalpha << a.empty() << "first stack empty" << std::endl;

	std::cout << "############STACK_COMP############" << std::endl;
	if (c == b)
		std::cout << "b == c" << std::endl;
	if (c != b)
		std::cout << "b != c" << std::endl;
	if (c < b)
		std::cout << "b < c" << std::endl;
	if (c > b)
		std::cout << "b > c" << std::endl;
	if (c <= b)
		std::cout << "b <= c" << std::endl;
	if (c >= b)
		std::cout << "b >= c" << std::endl;
}
