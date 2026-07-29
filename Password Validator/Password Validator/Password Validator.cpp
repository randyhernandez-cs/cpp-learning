#include <iostream>
#include <string>
#include "password_validator.h"
int main()  // Application to detect if password is viable to be a password.
{
    char retry{};
    do
    {
        std::string password{};
        std::cout << "A password should have these things for minimum password protection:" << '\n';
        std::cout << "At least 8 characters." << '\n';
        std::cout << "Contains at least one A-Z and a-z" << '\n';
        std::cout << "Contains at least one 0-9" << '\n';
        std::cout << "Contains !@#$% etc." << '\n';
        std::cout << "Password Validation Check:";
        std::getline(std::cin >> std::ws, password);
        passwordCheck(password);
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> retry;
    } while (retry == 'Y' || retry == 'y');
        std::cout << "closing program! goodbye!";
}

