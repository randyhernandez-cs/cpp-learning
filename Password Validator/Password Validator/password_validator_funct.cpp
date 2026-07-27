#include "password_validator.h"
#include <string>
#include <iostream>
bool isLongEnough(std::string passwordLimit) 
{
	return (passwordLimit.length() >= 8);
}
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