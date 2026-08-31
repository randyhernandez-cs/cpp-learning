#ifndef CIRCLE_FUNCTIONS_H
#define CIRCLE_FUNCTIONS_H
struct Calculations
{
	double radius{};
	const double pi{ 3.14159 };
};
double circleDiameter(const Calculations& x);
double circleArea(const Calculations& x);
double circleCircumference(const Calculations& x);
bool negativeCheck(const Calculations& x);
#endif