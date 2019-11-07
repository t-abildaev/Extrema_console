#pragma once

#include "Vector.h"

class Rectangle
{
public:
	Vector a, b;
	Rectangle(Vector _a, Vector _b);
	Rectangle(double* _a, double* _b, int dimension);
	~Rectangle() { /*delete[] a.coordinates; delete[] b.coordinates;*/ };
	bool isInRectangle(const Vector& vector);
	double howFar(const Vector& vector, const Vector& direction);
};