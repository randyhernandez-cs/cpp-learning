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
	std::cout << "The First Initial is: " << name[0] << '\n';
	std::cout << "The Second Initial is: " << name[spacePosition + 1] << '\n';
} 
int countCapitilization(const std::string& name)
{
	int x{ 0 };
	for (int i{ 0 }; i < name.length(); ++i)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			x += 1;
		}
	}
	return x;
}