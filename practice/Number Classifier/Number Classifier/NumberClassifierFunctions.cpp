#include "NumberClassifier.h"
#include <iostream>

bool isSingleDigit(int number) {	// returns true if number is between 1-9
	if (number < 10) {
		return true;
	}
	else {
		return false;
	}
}

bool isEven(int number){
	if (number % 2 == 0)	// remainder is zero → number is even
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Prints whether a number is even or odd using isEven()
double printEvenOrOdd(int number){
	if (isEven(number))
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
double printPositiveNegativeZero(int number) {
	if (number > 0) {
		std::cout << "This number is positive" << '\n';
	}
	else if (number < 0) {
		std::cout << "This number is negative" << '\n';
	}
	else if (number == 0) {
		std::cout << "This number is 0" << '\n';
	}
	return 0;
}
// Prints whether a number is single (1-9), double (10-99), triple (100-999), or quad digit (1000+)
double printMagnitude(int number) {
	if (isSingleDigit(number)) {
		std::cout << "This number is single digit" << '\n';
	}
	else if (number < 100) {
		std::cout << "This number is double digit" << '\n';
	}
	else if (number < 1000) {
		std::cout << "This number is triple digit" << '\n';
	}
	else if (number > 999) {
		std::cout << "This number is quad digit" << '\n';
	}
	return 0;
}