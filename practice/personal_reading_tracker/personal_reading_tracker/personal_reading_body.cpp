#include <iostream>
#include <vector>
#include "reader_tracker_header.h"
bool decision(char& retry)
{
	char failure{};
	do 
	{
		std::cout << "(y/n)" << '\n';
		std::cin >> retry;
		if (retry == 'Y' || retry == 'y')
		{
			return true;
		}
		else if (retry == 'N' || retry == 'n')
		{
			return false;
		}
		else
		{
			std::cout << "Please enter a correct choice option!" << '\n';
			failure = 'y';
			std::cin.ignore(100, '\n');
		}
	} while (failure == 'y');
}
void bookSelection(const std::vector<Book>& collection,const size_t choice)
{
	std::cout << "The title of this book is called " << collection[choice].title << '\n';
	std::cout << "Your current page is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
}
void progressUpdate(std::vector<Book>& collection, const size_t choice)
{
	std::cout << "The books outdated progress is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
	std::cout << "Please insert the updated progress:";
	std::cin >> collection[choice].currentPage;
	std::cout << "Your updated progress for " << collection[choice].title << " is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
}
void bookAdd(std::vector<Book>& collection, const size_t choice)
{

}