#include <iostream>
#include <string>

// Pointer and reference practice
// Covers references, addresses, pointers, dereferencing,
// and redirecting a pointer to another object.

void pointAndRef()
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
	int* z{ &y };
	std::cout << "zz stores an address, and *z dereferences z to access the object at that address " << '\n';
	std::cout << "z has the stored address of " << z << '\n';
	std::cout << "input integer to dereference z " << '\n';
	std::cin >> *z;
	std::cout << "the value of x is " << x << '\n';
	int c{ 5 };
	std::cout << "We create c with the address of " << &c << " and a value of " << c << '\n';
	std::cout << "With a new int, we can change where z points at" << '\n';
	z = &c;
	std::cout << "since z is now pointed at c, z holds the address of " << z << '\n';
	std::cout << "enter an integer to dereference z" << '\n';
	std::cin >> *z;
	std::cout << "The value of c is " << c << '\n';
	std::cout << "The value of x remains unchanged: " << x << '\n';
}