#pragma once

#include "Vector.h"

class Function
{
public:
	Function() {};
	virtual ~Function() {};
	virtual double operator () (const Vector & x) = 0;
	Vector gradient(const Vector & x, double h);
};

class Exponential : public Function
{
public:
	Exponential() {};
	~Exponential() {};
	double operator ()(const Vector & x) override;
};

class Trigonometric : public Function
{
public:
	Trigonometric() {};
	~Trigonometric() {};
	double operator ()(const Vector & x) override;
};

class Rosenbrock : public Function
{
public:
	Rosenbrock() {};
	~Rosenbrock() {};
	double operator ()(const Vector & x) override;
};

class Quadratic : public Function
{
public:
	Quadratic() {};
	~Quadratic() {};
	double operator ()(const Vector & x) override;
};