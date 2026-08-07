#include "name_analyzer.h"
#include <iostream>
#include <string>
// prints the name and its character count
void countCharacters(const std::string& name) 
{
	std::cout << name << " has " << name.length() << " characters" << '\n'; 
}
// finds specific position for initials
void findCharacters(const std::string& name) 
{	
	size_t spacePosition{ name.find(' ') };
	std::cout << "The First Initial is: " << name[0] << '\n';
	std::cout << "The Second Initial is: " << name[spacePosition + 1] << '\n';
} 
// checks and marks for each capital found
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
// checks and marks for each lowercase found
int countLowercase(const std::string& name)
{
	int x{ 0 };
	for (int i{ 0 }; i < name.length(); ++i)
	{
		if (name[i] >= 'a' && name[i] <= 'z')
		{
			x += 1;
		}
	}
	return x;
}