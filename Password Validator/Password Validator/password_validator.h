#pragma once
#include <string>
bool isLongEnough(const std::string& passwordLength);	// 8+ characters
bool hasUpperCase(const std::string& passwordCase);		// contains A-Z
bool hasNumber(const std::string& passwordNumber);		// contains 0-9
bool hasSpecial(const std::string& passwordSpecial);	// contains !@#$%^&*
bool passwordCheck(const std::string& passwordCheck);	// runs all checks, reports results