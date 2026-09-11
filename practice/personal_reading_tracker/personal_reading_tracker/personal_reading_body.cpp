#include <iostream>
#include <vector>
#include "reader_tracker_header.h"

void bookSelection(const std::vector<Book>& collection,const size_t choice)
{
	std::cout << "The title of this book is called " << collection[choice].title << '\n';
	std::cout << "Your current page is " << collection[choice].currentPage << " out of " << collection[choice].totalPage << " pages" << '\n';
}