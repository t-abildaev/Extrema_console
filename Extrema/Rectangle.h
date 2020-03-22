#pragma once

#include "Vector.h"


class Rectangle
{
protected:
	Vector a, b;
public:
	Rectangle(Vector _a, Vector _b);
	Rectangle(double * _a, double * _b, int dimension);
	~Rectangle() {};
	bool is_in_rectangle(const Vector & vector);
	Vector & get_a() { return(a); };
	Vector & get_b() { return(b); };
	double how_far(const Vector & vector, const Vector & direction);
	double min_length();
};