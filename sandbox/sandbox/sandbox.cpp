// Sandbox - for testing and experimenting with C++ concepts

#include <iostream>
#include <string>

int main()
{
	int x{ 10 };
	std::cout << x << '\n';
	std::cout << "the value of x is " << x << '\n';
	int& y{ x };
	std::cout << "input integer for y " << '\n';
	std::cin >> y;
	std::cout << "the value of x is " << x << '\n';
	std::cout << "y is referenced to x, and thus y changes as well since y is technically x " << '\n';
	int* z{&y};
	std::cout << "z is pointed at y's address, changing z will change the address of y, which is references to x " << '\n';
	*z = {3};
	std::cout << "the value of x is " << x << '\n';
}
