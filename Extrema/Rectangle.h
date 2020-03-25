#pragma once

#include "Vector.h"

/**
@class Rectangle
The class represents rectangle in R^n. It contains two fields: vectors
that are boundaries of rectangle.
*/
class Rectangle
{
protected:
	Vector a, b;
public:
	Rectangle(Vector _a, Vector _b);
	Rectangle(double * _a, double * _b, int dimension);
	~Rectangle() {};
	///The method indicates if vector is within rectangle
	bool is_in_rectangle(const Vector & vector);
	///The method returns vector that is the left boundary of rectangle
	Vector & get_a() { return(a); };
	///The method returns vector that is the right boundary of rectangle
	Vector & get_b() { return(b); };
	///The method calculates distance from vector to boundary along the direction
	double how_far(const Vector & vector, const Vector & direction);
	///The method calculates the maximal length of the side of an inscribed square
	double min_length();
};