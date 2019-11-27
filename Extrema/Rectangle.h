#pragma once

#include "Vector.h"

class Rectangle
{
protected:
	Vector a, b;
public:
	Rectangle(Vector _a, Vector _b);
	Rectangle(double* _a, double* _b, int dimension);
	~Rectangle() {};
	bool isInRectangle(const Vector& vector);
	Vector& getLeft();
	Vector& getRight();
	double howFar(const Vector& vector, const Vector& direction);
};