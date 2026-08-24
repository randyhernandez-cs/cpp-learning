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
void indexChange(std::vector<int>& x)
{
	int y{};
	std::cout << "Which index would you like to change? (0-4)" << '\n';
	std::cin >> y;
	if (y >= x.size() || y <= -1)
	{
		std::cout << "Please enter a valid integer!" << '\n' << y << " is not a valid index" << '\n';
		return;
	}
	std::cout << "What new value do you want it to be?" << '\n';
	std::cin >> x.at(y);
	std::cout << x.at(y);
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
	indexChange(integers);
}