#include "name_analyzer.h"
#include <iostream>
#include <string>

int countCharacters(std::string name) 
{
	std::cout << name << " has " << name.length() << " characters" << '\n'; // Prints the name and its character count
	return 0;
}
void findCharacters(std::string name) {	
	size_t spacePosition{ name.find(' ') };
	size_t initialPosition{ name.find('0') };
	std::cout << "The First Initial is: " << name[spacePosition + 1] << '\n';
	std::cout << "The Second Initial is: " << name[initialPosition + 1] << '\n';
} 