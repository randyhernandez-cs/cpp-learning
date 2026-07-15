#include <iostream>
#include <string>

int main()
{
    std::string password{};
    std::cout << "A password should have these things for minimum password protection:" << '\n';
    std::cout << "At least 8 characters." << '\n';
    std::cout << "Contains at least one A-Z and a-z" << '\n';
    std::cout << "Contains at least one 0-9" << '\n';
    std::cout << "Contains !@#$% etc." << '\n';
    std::cout << "Password Validation Check:" << '\n';
    std::getline(std::cin >> std::ws, password);
}

