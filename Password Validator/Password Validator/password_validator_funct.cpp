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
	return (passwordNumber[0] >= '0' && passwordNumber[0] <= '9'|| passwordNumber[1] >= '0' && passwordNumber[1] <= '9'|| passwordNumber[2] >= '0' && passwordNumber[2] <= '9');
}
bool hasSpecial(std::string passwordSpecial)
{
	return (passwordSpecial[0] == '!' || passwordSpecial[0] == '@' || passwordSpecial[0] == '#' || passwordSpecial[0] == '$' );
}
