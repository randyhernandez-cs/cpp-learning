#include <iostream>
#include <string>
#include "name_analyzer.h"

int main()
{
    std::cout << "Please enter your full name for analyization: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    countCharacters(name);
}

