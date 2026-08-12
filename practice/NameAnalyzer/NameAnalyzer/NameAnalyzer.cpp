#include <iostream>
#include <string>
#include "name_analyzer.h"

int main()
{
    std::string retry{};
    do
    {
        std::cout << "Please enter your full name for analyization:";
        std::string name{};
        std::getline(std::cin >> std::ws,name);    // reads full line, discards leading whitespace
        // counts capital letters in name
        std::cout << "You have a total of " << countCapitilization(name) << " capital letters!" << '\n';
        // counts lowercase letters in name
        std::cout << "You have a total of " << countLowercase(name) << " lowercase letters!" << '\n';
        countCharacters(name);  // displays character count of the entered name
        findCharacters(name);   // extracts and displays initials
        std::cout << "Do you want to try a new name? (y/n):";
        std::getline(std::cin, retry);
    } while (retry == "Y" || retry == "y");
}

