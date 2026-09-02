#include "circle_functions.h"
// Checks if the integer inserted is negative or positive
bool negativeCheck(const Calculations& x)
{
	return x.radius < 0;
}
// Returns the diameter after radius is inputted
double circleDiameter(const Calculations& x) 
{
	return x.radius * 2;
}
// Returns the area after radius is inputted
double circleArea(const Calculations& x)
{
	return x.radius * x.radius * pi;
}
// Returns the circumference after radius is inputted
double circleCircumference(const Calculations& x)
{
	return  x.radius * pi * 2;
}