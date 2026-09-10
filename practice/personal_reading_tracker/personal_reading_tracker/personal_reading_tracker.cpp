#include <iostream>
#include <vector>
#include "reader_tracker_header.h"

int main()
{
	size_t choice{};
	Book book1{"The Fifth Season", 512, 512};
	Book book2{"Wool", 15, 592 };
	Book book3{"Evolution of Desire", 0, 448};
	std::vector collection{book1, book2, book3};
	std::cout << "please choose a book out of this catalogue (0-2)" << '\n';
	std::cout << "0.The Fifth Season" << '\n' << "1.Wool" << '\n' << "2.Evolution of Desire" << '\n';
	std::cin >> choice;
}