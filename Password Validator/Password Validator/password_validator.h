#pragma once
#include <string>
bool isLongEnough(std::string passwordLimit);	// 8+ characters
bool hasUpperCase(std::string passwordLimit);	// contains A-Z
bool hasNumber(std::string passwordNumber);		// contains 0-9
bool hasSpecial(std::string passwordSpecial);	// contains !@#$%^&*
bool passwordCheck(std::string passwordSpecial);	// runs all checks, reports results