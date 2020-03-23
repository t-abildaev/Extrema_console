#include "Method.h"
#include <iostream>


Method::Method(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion) :
	dimension(_dimension), function(_function), rectangle(_rectangle), initial(_initial), stopCriterion(_stopCriterion) {}

void Method::set_init(const Vector & vector)
{ 
	initial = vector;
}

RSS::RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion) :
	Method(_dimension, _function, _rectangle, _initial, _stopCriterion)
{
	mtinit(std::chrono::system_clock::now().time_since_epoch().count());
}

RSS::RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion, double _p, double _delta) :
	Method(_dimension, _function, _rectangle, _initial, _stopCriterion)
{
	p = _p;
	delta = _delta;
	mtinit(std::chrono::system_clock::now().time_since_epoch().count());
}

void RSS::optimize()
{
	int i = 0;
	double rand = 0;
	Vector x_current(initial);
	Vector x_previous = x_current + 1;
	Vector x_next(dimension);
	double value_current = function(x_current);
	double value_next = 0;
	Vector a = rectangle.get_a();
	Vector b = rectangle.get_b();
	double r = 0.5 * rectangle.min_length();

	Vector left = x_current - delta * r;
	Vector right = x_current + delta * r;
	for (int i = 0; i < dimension; ++i)
	{
		if (a[i] > left[i]) left[i] = a[i];
		if (b[i] < right[i]) right[i] = b[i];
	}

	while (!(stopCriterion.if_stop(x_current, x_previous)))
	{
		rand = mtunif();
		if (rand < p)
			for (int j = 0; j < dimension; ++j)
				x_next[j] = (right[j] - left[j]) * mtunif() + left[j];
		else
			for (int j = 0; j < dimension; ++j)
				x_next[j] = (b[j] - a[j]) * mtunif() + a[j];
		value_next = function(x_next);

		if (value_current > value_next)
		{
			x_previous = x_current;
			x_current = x_next;
			value_current = value_next;
			if (rand < p)
			{
				delta = 0.5 * delta;
				left = x_current - delta * r;
				right = x_current + delta * r;
				for (int i = 0; i < dimension; ++i)
				{
					if (a[i] > left[i]) left[i] = a[i];
					if (b[i] < right[i]) right[i] = b[i];
				}
			}
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

PRCG::PRCG(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion) :
	Method(_dimension, _function, _rectangle, _initial, _stopCriterion) {}

void PRCG::optimize()
{
	int i = 0;
	double alpha = 0;
	double phi = 0.5 * (1 + sqrt(5));
	double left = 0;
	double right = 0;
	double _left = 0;
	double _right = 0;
	double f_left = 0;
	double f_right = 0;
	Vector a = rectangle.get_a();
	Vector b = rectangle.get_b();
	Vector x_current(initial);
	Vector x_previous = x_current + 1;
	Vector grad_current(function.gradient(x_current, 1e-6));
	Vector direction = -grad_current;
	Vector grad_next(dimension);

	while (!(stopCriterion.if_stop(x_current, x_previous)))
	{
		alpha = rectangle.how_far(x_current, direction);

		left = 0;
		right = alpha;
		_left = right - (right - left) / phi;
		_right = left + (right - left) / phi;
		f_left = function(x_current + _left * direction);
		f_right = function(x_current + _right * direction);
	
		while (right - left > 1e-6)
		//while ((right - left) * norm(direction) > 1e-6)
		{
			//std::cout << function(x_current + left * direction) << "    " << function(x_current + _left * direction) << "    " << function(x_current + _right * direction) << "    " << function(x_current + right * direction) << std::endl;
			if (f_left < f_right)
			{
				right = _right;
				_right = _left;
				f_right = f_left;
				_left = right - (right - left) / phi;
				f_left = function(x_current + _left * direction);
			}
			else
			{
				left = _left;
				_left = _right;
				f_left = f_right;
				_right = left + (right - left) / phi;
				f_right = function(x_current + _right * direction);
			}
		}
		//std::cout << std::endl;
		
		//std::cout << i << " " << x_current[0] << " " << x_current[1] << " " << x_current[2] << "    " << alpha << "    " << norm(direction) << std::endl;
		//std::cout << (x_current + alpha * direction)[0] << " " << (x_current + alpha * direction)[1] << " " << (x_current + alpha * direction)[2] << std::endl << std::endl;
		x_previous = x_current;
		x_current = x_previous + 0.5 * (left + right) * direction;
		grad_next = function.gradient(x_current, 1e-6);
		alpha = (grad_next * (grad_next - grad_current)) / (grad_current * grad_current);
		direction = -grad_current + alpha * direction;
		grad_current = grad_next;
		++i;
	}

	std::cout << "x: (";
	for (int i = 0; i < dimension - 1; ++i)
		std::cout << x_current[i] << ", ";
	std::cout << x_current[dimension - 1] << ")" << std::endl;
	std::cout << "f(x): " << function(x_current) << std::endl;
	std::cout << "Number of iterations: " << i;
}