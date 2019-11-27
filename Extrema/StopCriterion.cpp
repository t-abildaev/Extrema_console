#include "StopCriterion.h"

StopCriterion::StopCriterion(Function& _function, Rectangle& _rectangle) :
	function(_function), rectangle(_rectangle) {}

StopCriterion::StopCriterion(Function& _function, Rectangle& _rectangle, int _numberOfIterations) :
	StopCriterion(_function, _rectangle)
{
	numberOfIterations = _numberOfIterations;
}

StopCriterion::StopCriterion(Function& _function, Rectangle& _rectangle, double _eps) :
	StopCriterion(_function, _rectangle)
{
	eps = _eps;
}

StopCriterion::StopCriterion(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps) :
	StopCriterion(_function, _rectangle)
{
	numberOfIterations = _numberOfIterations;
	eps = _eps;
}

byGradient::byGradient(Function& _function, Rectangle& _rectangle) :
	StopCriterion(_function, _rectangle) {}

byGradient::byGradient(Function& _function, Rectangle& _rectangle, int _numberOfIterations) :
	StopCriterion(_function, _rectangle, _numberOfIterations) {}

byGradient::byGradient(Function& _function, Rectangle& _rectangle, double _eps) :
	StopCriterion(_function, _rectangle, _eps) {}

byGradient::byGradient(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps) :
	StopCriterion(_function, _rectangle, _numberOfIterations, _eps) {}

bool byGradient::ifStop(const Vector& x_current, const Vector& x_previous)
{
	Vector h(x_current.dimension, false);
	double alpha = rectangle.howFar(x_current, h);
	alpha = alpha < eps ? alpha : eps;
	if (numberOfIterations == 0 || abs(norm(function.gradientII(x_current, alpha))) < eps)
		return(true);
	--numberOfIterations;
	return(false);
}

byDifference::byDifference(Function& _function, Rectangle& _rectangle) :
	StopCriterion(_function, _rectangle) {}

byDifference::byDifference(Function& _function, Rectangle& _rectangle, int _numberOfIterations) :
	StopCriterion(_function, _rectangle, _numberOfIterations) {}

byDifference::byDifference(Function& _function, Rectangle& _rectangle, double _eps) :
	StopCriterion(_function, _rectangle, _eps) {}

byDifference::byDifference(Function& _function, Rectangle& _rectangle, int _numberOfIterations, double _eps) :
	StopCriterion(_function, _rectangle, _numberOfIterations, _eps) {}

bool byDifference::ifStop(const Vector& x_current, const Vector& x_previous)
{
	if (numberOfIterations == 0 || abs(function(x_current) - function(x_previous)) < eps)
		return(true);
	--numberOfIterations;
	return(false);
}