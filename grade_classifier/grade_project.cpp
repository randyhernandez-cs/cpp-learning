#include <iostream>
bool GradePorF(int Grade) {
	if (Grade >= 70 && Grade <= 100)
		std::cout << "You Passed!" << '\n';
	else
		std::cout << "You failed!" << '\n';
	return 0;
}


int main()
{
	
	unsigned int Grade{};
	std::cout << "Please enter grade in number form to convert to letter form:" << '\n';
	std::cin >> Grade;
	GradePorF(Grade);
	if (Grade < 100 && Grade >= 90)
		std::cout << "You got a A!" << '\n';
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