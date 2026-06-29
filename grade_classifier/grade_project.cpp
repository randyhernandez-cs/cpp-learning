#include <iostream>
bool GradePorF(int Grade)	// Returns bool value if high enough grade
{
	return Grade >= 60;
}


int main()	// Grading calculator that turns numeral form into letter form
{
	
	unsigned int Grade{};
	std::cout << "Please enter grade in number form to convert to letter form:" << '\n';
	std::cin >> Grade;
	if (GradePorF(Grade))	// Checks if the score is high enough to be passable
	{
		std::cout << "You Passed!" << '\n';
	}
	else
	{
		std::cout << "you Failed!" << '\n';
	}
	if (Grade < 99 && Grade >= 90)		// If-else chain clarifying which number goes to which letter form
		std::cout << "You got a A!" << '\n';
	else if (Grade == 100)
		std::cout << "You got a perfect score!" << '\n';
	else if (Grade <= 89 && Grade >= 80)
		std::cout << "You got a B!" << '\n';
	else if (Grade <= 79 && Grade >= 70)
		std::cout << "You got a C!" << '\n';
	else if (Grade <= 69 && Grade >= 60)
		std::cout << "You got a D!" << '\n';
	else
		std::cout << "You got an F!" << '\n';
	return 0;

}