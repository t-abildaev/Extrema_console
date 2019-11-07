#include <cmath>
#include "Function.h"
#include <iostream>

Vector Function::gradientII(const Vector& x, double h)
{
	int dimension = x.dimension;
	Vector e(dimension);
	Vector g(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		e[i] = h;
		g[i] = ((*this)(x + e) - (*this)(x)) / h;
		e[i] = 0;
	}
	return(g);
}

Vector Function::gradientIII(const Vector& x, double h)
{
	int dimension = x.dimension;
	Vector e(dimension);
	Vector g(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		e[i] = h;
		g[i] = ((*this)(x + e) - (*this)(x - e)) / (h * h);
		e[i] = 0;
	}
	return(g);
}

double Hyperbolic::operator ()(const Vector& x)
{
	double X = 2 * x.coordinates[0];
	double Y = 2 * x.coordinates[1];
	return(0.25 * (exp(X) + exp(-X) - exp(Y) - exp(-Y) + 4));
	//f(x1, x2) = ch^2(x1) - sh^2(x2)
}

double Rosenbrock::operator ()(const Vector& x)
{
	Vector X((Vector) x);
	return((1 - X[0]) * (1 - X[0]) + 100 * (X[1] - X[0] * X[0]) * (X[1] - X[0] * X[0]) + (1 - X[1]) * (1 - X[1]) + 100 * (X[2] - X[1] * X[1]) * (X[2] - X[1] * X[1]));
	//f(x1, x2, x3) = (1 - x1)^2 + 100(x2 - x1^2)^2 + (1 - x2)^2 + 100(x3 - x2^2)^2
}

double Quadratic::operator ()(const Vector& x)
{
	Vector X((Vector)x);
	return(((X[0] - 1) * (X[0] - 1) + 1) * ((X[1] - 2) * (X[1] - 2) + 1) * ((X[2] - 3) * (X[2] - 3) + 1) * ((X[3] - 4) * (X[3] - 4) + 1));
	//f(x1, x2, x3, x4) = ((x1 - 1)^2 + 1)((x2 - 2)^2 + 1)((x3 - 3)^2 + 1)((x4 - 4)^2 + 1)
}