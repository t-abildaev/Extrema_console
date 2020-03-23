#include <cmath>
#include "Function.h"
#include <iostream>


Vector Function::gradient(const Vector & x, double h)
{
	int dimension = x.dimension;
	Vector direction(dimension);
	Vector grad(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		direction[i] = h;
		grad[i] = ((*this)(x + direction) - (*this)(x)) / h;
		direction[i] = 0;
	}
	return(grad);
}

double Trigonometric::operator ()(const Vector & x)
{
	Vector X((Vector) x);
	return(sin(X[0]) + cos(X[1]));
	//T(x1, x2) = sin(x1) + cos(x2)
}

double Exponential::operator ()(const Vector& x)
{
	Vector X((Vector) x);
	return(exp(X[0]) + exp(X[1]));
	//H(x1, x2) = e^x1 + e^x2
}

double Rosenbrock::operator ()(const Vector & x)
{
	Vector X((Vector) x);
	return((1 - X[0]) * (1 - X[0]) + 100 * (X[1] - X[0] * X[0]) * (X[1] - X[0] * X[0]) + (1 - X[1]) * (1 - X[1]) + 100 * (X[2] - X[1] * X[1]) * (X[2] - X[1] * X[1]));
	//R(x1, x2, x3) = (1 - x1)^2 + 100(x2 - x1^2)^2 + (1 - x2)^2 + 100(x3 - x2^2)^2
}

double Quadratic::operator ()(const Vector & x)
{
	Vector X((Vector) x);
	return((X[0] - 1) * (X[0] - 1) + (X[1] - 2) * (X[1] - 2) + (X[2] - 3) * (X[2] - 3) + (X[3] - 4) * (X[3] - 4));
	//Q(x1, x2, x3, x4) = (x1 - 1)^2 + (x2 - 2)^2 + (x3 - 3)^2 + (x4 - 4)^2
}