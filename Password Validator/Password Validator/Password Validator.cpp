#include <iostream>
#include <string>
#include "password_validator.h"
int main()  // Application to detect if password is viable to be a password.
{
    std::string password{};
    std::cout << "A password should have these things for minimum password protection:" << '\n';
    std::cout << "At least 8 characters." << '\n';
    std::cout << "Contains at least one A-Z and a-z" << '\n';
    std::cout << "Contains at least one 0-9" << '\n';
    std::cout << "Contains !@#$% etc." << '\n';
    std::cout << "Password Validation Check:";
    std::getline(std::cin >> std::ws, password);
    if (isLongEnough(password)) // Detects if password is long enough
    {
        std::cout << "Password is long enough.\n";
    }
    else
    {
        std::cout << "Password is too short.\n";
    }
    if (hasUpperCase(password)) // Detects if password has uppercase.
    {
        std::cout << "You have a capital letter!" << '\n';
    }
    else
    {
        std::cout << "You do not have a capital letter!" << '\n';
    }
    if (hasNumber(password)) // Detects if password has number.
    {
        std::cout << "You have a number!" << '\n';
    }
    else
    {
        std::cout << "You do not have a number" << '\n';
    }
    if (hasSpecial(password)) // Detects if first integer has special variable
    {
        std::cout << "You have a special number!" << '\n';
    }
    else
    {
        std::cout << "You do not have a special number!" << '\n';
    }
    if (isLongEnough(password) && hasNumber(password) && hasUpperCase(password) && hasSpecial(password))
    {
        std::cout << "You have a password with minimum protection!" << '\n';
    }
    else
    {
        std::cout << "You do not have a password with minimum protection!" << '\n';
    }
}

