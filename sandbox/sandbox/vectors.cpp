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
bool askValidIndex(const std::vector<int>& x, int& y)
{
	bool fail{};
	do
	{
		fail = false;
		std::cout << "Which index would you like to choose? (0-4)" << '\n';
		std::cin >> y;
		if (y <= -1 || y >= x.size())
		{
			std::cout << "Please enter a valid integer!" << '\n' << y << " is not a valid index" << '\n';
			fail = true;
		}
	} while (fail);
	return true;
}
void indexChange(std::vector<int>& x)
{
	int y{};
	if (askValidIndex(x, y))
	{
		std::cout << "What new value do you want it to be?" << '\n';
		std::cin >> x.at(y);
		std::cout << x.at(y) << '\n';
	}
}

void index()
{
	char retry{};
	do
	{
		int x{};
		std::vector integers{ 1,10,100,1000,10000 };
		std::cout << "index 0 on this vector is: " << integers.at(0) << '\n';
		std::cout << "index 3 on this vector is: " << integers.at(3) << '\n';
		if (askValidIndex(integers, x))
		{
			std::cout << integers.at(x) << '\n';
			indexDisplay(integers);
			indexChange(integers);
		}
		std::cout << "Do you want to reset? (Y/N)" << '\n';
		std::cin >> retry;
	} while (retry == 'Y' || retry == 'y');
}