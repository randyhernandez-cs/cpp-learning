#include "circle_functions.h"
#include <iostream>

int main()
{
    Calculations circle;
    char retry{};
    do
    {
        std::cout << "Enter a radius to find the circumfrence, diameter, and area of your circle" << '\n' << "Radius: ";
        std::cin >> circle.radius;
        if (negativeCheck(circle))
        {
            std::cout << "Invalid radius. Do you want to try a different number? (y/n): ";
            std::cin >> retry;
        }
        else
        {
            std::cout << "Your values are:" << '\n' << "Diameter: " << circleDiameter(circle) << '\n' << "Area: " << circleArea(circle) << '\n' << "Circumference: " << circleCircumference(circle) << '\n';
            std::cout << "Do you want to try a different number? (y/n): " << '\n';
            std::cin >> retry;
        }
    } while (retry == 'Y' || retry == 'y');
}