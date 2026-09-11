#include <iostream>
#include <vector>
#include "reader_tracker_header.h"

int main()
{
	char retry{};
	size_t choice{};
	Book book1{ "The Fifth Season", 512, 512 };
	Book book2{ "Wool", 15, 592 };
	Book book3{ "Evolution of Desire", 0, 448 };
	std::vector collection{ book1, book2, book3 };
	do 
	{
		std::cout << "please choose a book out of this catalogue (0-2)" << '\n';
		std::cout << "0.The Fifth Season" << '\n' << "1.Wool" << '\n' << "2.Evolution of Desire" << '\n';
		std::cin >> choice;
		bookSelection(collection, choice);
		std::cout << "Would you like to change the progress of a book? (y/n)" << '\n';
		std::cin >> retry;
		if (retry == 'y' || retry == 'Y')
		{
			std::cout << "Which book would you like to change progress on? (0-2)" << '\n';
			std::cout << "0.The Fifth Season" << '\n' << "1.Wool" << '\n' << "2.Evolution of Desire" << '\n';
			std::cin >> choice;
		}
		std::cout << "(y/n) to restart or end the application" << '\n';
		std::cin >> retry;
	} 
	while (retry == 'y' || retry == 'Y');
}