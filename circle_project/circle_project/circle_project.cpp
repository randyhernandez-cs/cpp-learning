#include "circle_functions.h"
#include <iostream>

int main()
{
    char retry{};
    do
    {
        double radius{};
        constexpr double pi{ 3.14159 };
        std::cout << "Give me your radius to find the circumfrence, diameter, and area of your circle" << '\n' << "Radius: ";
        std::cin >> radius;
        std::cout << "Your values are:" << '\n' << "Diameter: " << circleDiameter(radius) << '\n' << "Area: " << circleArea(radius, pi) << '\n' << "Circumference: " << circleCircumference(radius, pi);
        std::cout << "Do you want to try a different number? (y/n): " << '\n';
        std::cin >> retry;
    }
        while (retry == 'Y' || retry == 'y');
    {

    }
}