#pragma once

#include <cmath>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"

class StopCriterion
{
protected:
	int numberOfIterations = 1000;
	Function& function;
	Rectangle& rectangle;
public:
	double eps = 0.1;
	StopCriterion(Function& _function, Rectangle& _rectangle);
	StopCriterion(Function& _function, Rectangle& _rectangle, int _numberOfIterations);
	StopCriterion(Function& _function, Rectangle& _rectangle, double _eps);
	StopCriterion(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps);
	virtual ~StopCriterion() {};
	virtual bool ifStop(const Vector& x_current, const Vector& x_previous) = 0;
};

class byGradient : public StopCriterion
{
public:
	byGradient(Function& _function, Rectangle& _rectangle);
	byGradient(Function& _function, Rectangle& _rectangle, int _numberOfIterations);
	byGradient(Function& _function, Rectangle& _rectangle, double _eps);
	byGradient(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps);
	~byGradient() {};
	bool ifStop(const Vector& x_current, const Vector& x_previous) override;
};

class byDifference : public StopCriterion
{
public:
	byDifference(Function& _function, Rectangle& _rectangle);
	byDifference(Function& _function, Rectangle& _rectangle, int _numberOfIterations);
	byDifference(Function& _function, Rectangle& _rectangle, double _eps);
	byDifference(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps);
	~byDifference() {};
	bool ifStop(const Vector& x_current, const Vector& x_previous) override;
};