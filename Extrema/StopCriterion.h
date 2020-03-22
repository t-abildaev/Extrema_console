#pragma once

#include <cmath>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"

class StopCriterion
{
protected:
	int num_of_iter = 1000;
	double eps = 0.05;
	Function & function;
	Rectangle & rectangle;
public:
	StopCriterion(Function & _function, Rectangle & _rectangle);
	StopCriterion(Function & _function, Rectangle & _rectangle, int _num_of_iter);
	StopCriterion(Function & _function, Rectangle & _rectangle, double _eps);
	StopCriterion(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps);
	virtual ~StopCriterion() {};
	virtual bool if_stop(const Vector & x_current, const Vector & x_previous) = 0;
};

class by_gradient : public StopCriterion
{
public:
	by_gradient(Function & _function, Rectangle & _rectangle);
	by_gradient(Function & _function, Rectangle & _rectangle, int _num_of_iter);
	by_gradient(Function & _function, Rectangle & _rectangle, double _eps);
	by_gradient(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps);
	~by_gradient() {};
	bool if_stop(const Vector & x_current, const Vector & x_previous) override;
};

class by_difference : public StopCriterion
{
public:
	by_difference(Function & _function, Rectangle & _rectangle);
	by_difference(Function & _function, Rectangle & _rectangle, int _num_of_iter);
	by_difference(Function & _function, Rectangle & _rectangle, double _eps);
	by_difference(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps);
	~by_difference() {};
	bool if_stop(const Vector & x_current, const Vector & x_previous) override;
};