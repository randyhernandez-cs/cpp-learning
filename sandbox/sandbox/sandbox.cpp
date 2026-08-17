// Sandbox - for testing and experimenting with C++ concepts

#include <iostream>
#include <string>

int main()
{
	int x{ 10 };
	std::cout << "the value of x is " << x << '\n';
	std::cout << "x also has an address of " << &x << '\n';
	int& y{ x };
	std::cout << "input integer for y " << '\n';
	std::cin >> y;
	std::cout << "the value of x is " << x << '\n';
	std::cout << "x has an address of " << &x << '\n';
	std::cout << "y also has an address of " << &y << '\n';
	std::cout << "y is referenced to x and thus y shares an address with x, both are the same int " << '\n';
	int* z{&y};
	std::cout << "z holds the address of x, a pointer holds an address, z can dereference, telling it to go to the address, potentially change, view " << '\n';
	std::cout << "z has the stored address of " << z << '\n';
	std::cout << "input integer to dereference z " << '\n';
	std::cin >> *z;
	std::cout << "the value of x is " << x << '\n';
}
