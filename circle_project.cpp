#include "circle_functions.h"

#include <iostream>

int main()
{
    double Radius{};
    double pi{ 3.14159 };
    std::cout << "Give me your radius to find the circumfrence, diameter, and area of your circle" << '\n' << "Radius: ";
    std::cin >> Radius;
    std::cout << "Your values are:" << '\n' << "Diameter: " << circleDiameter(Radius) << '\n' << "Area: " << circleArea(Radius, pi) << '\n' << "Circumference: " << circleCircumference(Radius, pi);
    return 0;
}

