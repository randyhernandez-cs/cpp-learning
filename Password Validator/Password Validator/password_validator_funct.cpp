#include "password_validator.h"
#include <string>
bool isLongEnough(std::string passwordLimit) 
{
	return passwordLimit.length() >= 8;
}
