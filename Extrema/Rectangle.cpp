#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Vector _a, Vector _b) :
	a(_a), b(_b) {}

Rectangle::Rectangle(double* _a, double* _b, int dimension) :
	a(_a, dimension), b(_b, dimension) {}

bool Rectangle::isInRectangle(const Vector& vector)
{
	return(a <= vector && (Vector) vector <= b);
}

double Rectangle::howFar(const Vector& vector, const Vector& direction)
{
	double alpha = b[0] - a[0];
	double temp = 0;
	for (int i = 0; i < a.dimension; ++i)
	{
		if (direction.coordinates[i] > 0)
			temp = (b[i] - vector.coordinates[i]) / direction.coordinates[i];
		if (direction.coordinates[i] < 0)
			temp = (a[i] - vector.coordinates[i]) / direction.coordinates[i];
		if (temp < alpha)
			alpha = temp;
	}
	return(alpha);
}