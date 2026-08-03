#include "name_analyzer.h"
#include <iostream>
#include <string>

void countCharacters(const std::string& name) 
{
	std::cout << name << " has " << name.length() << " characters" << '\n'; // Prints the name and its character count
}
void findCharacters(const std::string& name) 
{	
	size_t spacePosition{ name.find(' ') };
	size_t initialPosition{ name.find('0') };
	std::cout << "The First Initial is: " << name[initialPosition + 1] << '\n';
	std::cout << "The Second Initial is: " << name[spacePosition + 1] << '\n';
} 