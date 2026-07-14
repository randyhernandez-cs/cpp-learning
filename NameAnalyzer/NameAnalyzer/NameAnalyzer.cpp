#include <iostream>
#include <string>
#include "name_analyzer.h"

int main()
{
    std::cout << "Please enter your full name for analyization: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);    // reads full line, discards leading whitespace
    countCharacters(name);  // displays character count of the entered name
    findCharacters(name);   // extracts and displays initials
}

