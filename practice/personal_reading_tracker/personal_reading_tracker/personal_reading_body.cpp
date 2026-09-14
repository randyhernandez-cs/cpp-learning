#include <iostream>
#include <vector>
#include <string>
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
			std::cin.ignore(100, '\n');
			return true;
		}
		else if (retry == 'N' || retry == 'n')
		{
			std::cin.ignore(100, '\n');
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
void bookAdd(std::vector<Book>& collection)
{
	collection.push_back(Book {"unnamed", 0, 0});
	std::cout << "Please insert the name of the book:";
	std::getline(std::cin, collection.back().title);
	std::cout << '\n' << "Please insert the total pages of the book:";
	std::cin >> collection.back().totalPage;
	std::cout <<'\n' << "Please insert your current page on the book:";
	std::cin >> collection.back().currentPage;
	std::cout << "The book you added is called: " << collection.back().title << '\n';
	std::cout << "its current and total page number is: " << collection.back().currentPage << "/" << collection.back().totalPage << '\n';
}