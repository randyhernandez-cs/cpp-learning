#include "NumberClassifier.h"
#include <iostream>

bool isSingleDigit(int Numbertest4) {	// returns true if number is between 1-9
	if (Numbertest4 < 10) {
		return true;
	}
	else {
		return false;
	}
}

bool EorO(int Numbertest){
	if (Numbertest % 2 == 0)	// remainder is zero → number is even
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Prints whether a number is even or odd using EorO()
double Classification(int NumberTest2){
	if (EorO(NumberTest2))
	{
		std::cout << "this number is even" << '\n';
}
	else 
	{
		std::cout << "this number is odd" << '\n';
	}
	return 0;
}
// Prints whether a number is positive, negative, or zero
double PorNorO(int NumberTest3) {
	if (NumberTest3 > 0) {
		std::cout << "This number is positive" << '\n';
	}
	else if (NumberTest3 < 0) {
		std::cout << "This number is negative" << '\n';
	}
	else if (NumberTest3 == 0) {
		std::cout << "This number is 0" << '\n';
	}
	return 0;
}
// Prints whether a number is single (1-9), double (10-99), triple (100-999), or quad digit (1000+)
double numberRange(int NumberTest4) {
	if (isSingleDigit(NumberTest4)) {
		std::cout << "This number is single digit" << '\n';
	}
	else if (NumberTest4 < 100) {
		std::cout << "This number is double digit" << '\n';
	}
	else if (NumberTest4 < 1000) {
		std::cout << "This number is triple digit" << '\n';
	}
	else if (NumberTest4 > 999) {
		std::cout << "This number is quad digit" << '\n';
	}
	return 0;
}