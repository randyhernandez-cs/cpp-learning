#ifndef CIRCLE_FUNCTIONS_H
#define CIRCLE_FUNCTIONS_H
constexpr double pi{ 3.14159 };

struct Calculations
{
	double radius{};
};
double circleDiameter(const Calculations& x);
double circleArea(const Calculations& x);
double circleCircumference(const Calculations& x);
bool negativeCheck(const Calculations& x);
#endif