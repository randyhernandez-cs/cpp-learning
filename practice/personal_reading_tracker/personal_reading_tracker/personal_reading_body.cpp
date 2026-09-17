#include <iostream>
#include <vector>
#include <string>
#include "reader_tracker_header.h"
// Checks if the value matches "Y,y,N,n", retrying on invalid entries.
// .ignore() is put in every branch to discard leftover buffer characters.
// if no .ignore(), inputs such "yy", "yes", or "as" corrupts the next cin/getline call.
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
// Displays the book at the given index.
// const ref: read-only access, and copying by value would be too expensive.
void bookSelection(const std::vector<Book>& collection,const size_t choice)
{
	std::cout << "The title of this book is called " << collection[choice].title << '\n';
	std::cout << "Your current page is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
}
// Displays the selected book's progress and updates it with the user's input.
// non-const ref: mutates the caller's actual Book data.
// copying would be too expensive and isn't needed since we're modifying in place.
void progressUpdate(std::vector<Book>& collection, const size_t choice)
{
	std::cout << "The books outdated progress is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
	std::cout << "Please insert the updated progress:";
	std::cin >> collection[choice].currentPage;
	std::cout << "Your updated progress for " << collection[choice].title << " is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
}
//Creates a placeholder Book struct into the vector storage
//non-const ref: mutates the caller's actual book data, adding to its total length
//Copying would destroy the copied vector with the modified new element, having it never reach the real collection
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