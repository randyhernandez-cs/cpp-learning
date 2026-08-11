#include "circle_functions.h"

bool negativeCheck(double radius)
{
	return radius < 0;
}
double circleDiameter(double radius) {
	return radius * 2;
}
double circleArea(double radius, double pi) {
	return radius * radius * pi;
}
double circleCircumference(double radius, double pi) {
	return  radius * pi * 2;
}