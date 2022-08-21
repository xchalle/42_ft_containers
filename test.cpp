#include <iostream>
#include <utility>

int main()
{
	int a1 = 5;
	int a2 = 4;
	int b1 = 2;
	int b2 = 3;
	std::pair<int, int> n1(a1, b1);
	std::pair<int, int> n2(a2, b2);
	if (n1 < n2)
		std::cout << "cool" << std::endl;
}
