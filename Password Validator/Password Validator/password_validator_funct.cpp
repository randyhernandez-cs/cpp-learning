#include "password_validator.h"
#include <string>
#include <iostream>
// Returns true if password is at least 8 characters
bool isLongEnough(std::string passwordLimit) 
{
	return (passwordLimit.length() >= 8);
}
// Returns true if password contains at least one uppercase letter
bool hasUpperCase(std::string passwordLimit)
{
	for (int i{ 0 }; i < passwordLimit.length(); ++i)
	{
		if (passwordLimit[i] >= 'A' && passwordLimit[i] <= 'Z')
		{
			return true;
		}
	}
	return false;
}
// Returns true if password contains at least one digit
bool hasNumber(std::string passwordNumber)
{
	for (int i{ 0 }; i < passwordNumber.length(); ++i)
	{
		if (passwordNumber[i] >= '0' && passwordNumber[i] <= '9')
		{
			return true;
		}
	}
	return false;
}
// Returns true if password contains at least one special character
bool hasSpecial(std::string passwordSpecial)
{
		for (int i{ 0 }; i < passwordSpecial.length(); ++i)
		{
			if (passwordSpecial[i] == '!' || passwordSpecial[i] == '@'|| passwordSpecial[i] == '#' || passwordSpecial[i] == '$' || passwordSpecial[i] == '%' || passwordSpecial[i] == '^' || passwordSpecial[i] == '&' || passwordSpecial[i] == '*' )
			{
				return true;
			}
		}
		return false;
}
// Runs all password checks, prints results, returns true only if all checks pass
bool passwordCheck(std::string password)
{
	bool x{ true };
	if (isLongEnough(password)) 
	{
		std::cout << "Password is long enough.\n";
	}
	else
	{
		std::cout << "Password is too short.\n";
		x = false;
	}
	if (hasUpperCase(password)) // Detects if password has uppercase.
	{
		std::cout << "You have a capital letter!" << '\n';
	}
	else
	{
		std::cout << "You do not have a capital letter!" << '\n';
		x = false;
	}
	if (hasNumber(password)) // Detects if password has number.
	{
		std::cout << "You have a number!" << '\n';
	}
	else
	{
		std::cout << "You do not have a number" << '\n';
		x = false;
	}
	if (hasSpecial(password)) // Detects if first integer has special variable
	{
		std::cout << "You have a special number!" << '\n';
	}
	else
	{
		std::cout << "You do not have a special number!" << '\n';
		x = false;
	}
	if (x)
	{
		std::cout << "You have a valid password!" << '\n';
	}
	else 
	{
		std::cout << "You do not have a valid password!" << '\n';
	}
	return x;
}