#include "Method.h"
#include <iostream>

Method::Method(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion) :
	dimension(_dimension), function(_function), rectangle(_rectangle), stopCriterion(_stopCriterion) {}

Method::Method(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector _initial) :
	Method(_dimension, _function, _rectangle, _stopCriterion)
{
	initial = _initial;
}

void Method::setInitial(const Vector& vector)
{ 
	initial = vector;
}

RSS::RSS(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion) :
	Method(_dimension, _function, _rectangle, _stopCriterion)
{
	mtinit(std::chrono::system_clock::now().time_since_epoch().count());
}

RSS::RSS(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector _initial) :
	Method(_dimension, _function, _rectangle, _stopCriterion, _initial)
{
	mtinit(std::chrono::system_clock::now().time_since_epoch().count());
}

void RSS::optimize()
{
	int i = 0;
	Vector x_current(initial);
	Vector x_previous(dimension);
	Vector x_next(dimension);
	double value_current = (*function)(x_current);
	double value_next = 0;
	while (!(stopCriterion->ifStop(x_current, x_previous)))
	{
		for (int j = 0; j < dimension; ++j)
			x_next[j] = (rectangle->b[j] - rectangle->a[j]) * mtunif() + rectangle->a[j];
		value_next = (*function)(x_next);
		if (value_current > value_next)
		{
			x_previous = x_current;
			x_current = x_next;
			value_current = value_next;
		}
		++i;
	}
	std::cout << "x: (";
	for (int j = 0; j < dimension - 1; ++j)
		std::cout << x_current[j] << ", ";
	std::cout << x_current[dimension - 1] << ")" << std::endl;
	std::cout << "f(x): " << value_current << std::endl;
	std::cout << "Number of iterations: " << i;
}

PRCG::PRCG(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion) :
	Method(_dimension, _function, _rectangle, _stopCriterion) {}

PRCG::PRCG(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector _initial) :
	Method(_dimension, _function, _rectangle, _stopCriterion, _initial) {}

void PRCG::optimize()
{
	int i = 0;
	Vector x_current(initial);
	Vector x_previous(dimension);
	Vector direction(dimension);
	Vector gradient_current(function->gradientII(x_current, stopCriterion->eps));
	Vector gradient_next(dimension);
	direction = direction - gradient_current;
	double value = (*function)(x_current);
	double temp = 0;
	double alpha = 0;
	double dAlpha = 0;
	double beta = 0;
	int k = 0;
	while (!(stopCriterion->ifStop(x_current, x_previous)))
	{
		k = 0;
		alpha = rectangle->howFar(x_current, direction);
		dAlpha = alpha / 10;
		for (int j = 1; j < 10; ++j)
		{
			value = (*function)(x_current + k * dAlpha * direction);
			temp = (*function)(x_current + j * dAlpha * direction);
			if (temp < value)
			{
				value = temp;
				k = j;
			}
		}
		x_previous = x_current;
		x_current = x_current + k * dAlpha * direction;
		gradient_next = function->gradientII(x_current, stopCriterion->eps);
		beta = (gradient_next * (gradient_next - gradient_current)) / (gradient_current * gradient_current);
		direction = beta * direction - gradient_current;
		gradient_current = gradient_next;
		++i;
	}
	std::cout << "x: (";
	for (int i = 0; i < dimension - 1; ++i)
		std::cout << x_current[i] << ", ";
	std::cout << x_current[dimension - 1] << ")" << std::endl;
	std::cout << "f(x): " << value << std::endl;
	std::cout << "Number of iterations: " << i;
}