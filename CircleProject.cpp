#include "circlefunctions.h"

#include <iostream>

int main()
{
    double Radius{};
    double pi{ 3.14159 };
    std::cout << "Give me your radius to find the circumfrence, diameter, and area of your circle" << '\n' << "Radius: ";
    std::cin >> Radius;
    std::cout << "Your values are!" << '\n' << "Diameter: " << CircleDiameter(Radius) << '\n' << "Area: " << CircleArea(Radius, pi) << '\n' << "Circumference: " << CircleCircumference(Radius, pi);
    return 0;
}

