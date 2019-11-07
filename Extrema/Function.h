#pragma once

#include "Vector.h"

class Function
{
public:
	Function() {};
	virtual ~Function() {};
	virtual double operator () (const Vector& x) = 0;
	Vector gradientII(const Vector& x, double h);
	Vector gradientIII(const Vector& x, double h);
};

class Hyperbolic : public Function
{
public:
	Hyperbolic() {};
	~Hyperbolic() {};
	double operator ()(const Vector& x) override;
};

class Rosenbrock : public Function
{
public:
	Rosenbrock() {};
	~Rosenbrock() {};
	double operator ()(const Vector& x) override;
};

class Quadratic : public Function
{
public:
	Quadratic() {};
	~Quadratic() {};
	double operator ()(const Vector& x) override;
};