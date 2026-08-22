// Sandbox - for testing and experimenting with C++ concepts
#include <iostream>
#include <string>
#include <vector>
void indexDisplay(const std::vector<int>& x)
{
		for (int y{}; y < x.size(); ++y)
	{
		std::cout << x.at(y) << '\n';
	}
}

int main()
{
	int x{};
	std::vector integers{1,10,100,1000,10000};
	std::cout << "index 0 on this vector is: " << integers.at(0) << '\n';
	std::cout << "index 3 on this vector is: " << integers.at(3) << '\n';
	std::cout << "Please choose an index between 0-4: " << '\n';
	std::cin >> x;
	std::cout << integers.at(x) << '\n';
	indexDisplay(integers);
}