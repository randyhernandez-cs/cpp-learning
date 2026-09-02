#include "circle_functions.h"

bool negativeCheck(const Calculations& x)
{
	return x.radius < 0;
}
double circleDiameter(const Calculations& x) 
{
	return x.radius * 2;
}
double circleArea(const Calculations& x)
{
	return x.radius * x.radius * pi;
}
double circleCircumference(const Calculations& x)
{
	return  x.radius * pi * 2;
}