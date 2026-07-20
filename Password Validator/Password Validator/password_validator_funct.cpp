#include "password_validator.h"
#include <string>
#include <iostream>
bool isLongEnough(std::string passwordLimit) 
{
	return (passwordLimit.length() >= 8);
}
bool hasUpperCase(std::string passwordLimit)
{
	return (passwordLimit[0] >= 'A' && passwordLimit[0] <= 'Z') || (passwordLimit[1] >= 'A' && passwordLimit[1] <= 'Z') || (passwordLimit[2] >= 'A' && passwordLimit[2] <= 'Z');
}