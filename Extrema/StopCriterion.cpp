#include "StopCriterion.h"


StopCriterion::StopCriterion(Function & _function, Rectangle & _rectangle) :
	function(_function), rectangle(_rectangle) {}

StopCriterion::StopCriterion(Function & _function, Rectangle & _rectangle, int _num_of_iter) :
	function(_function), rectangle(_rectangle), num_of_iter(_num_of_iter) {}

StopCriterion::StopCriterion(Function & _function, Rectangle & _rectangle, double _eps) :
	function(_function), rectangle(_rectangle), eps(_eps) {}

StopCriterion::StopCriterion(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps) :
	function(_function), rectangle(_rectangle), num_of_iter(_num_of_iter), eps(_eps) {}

by_gradient::by_gradient(Function & _function, Rectangle & _rectangle) :
	StopCriterion(_function, _rectangle) {}

by_gradient::by_gradient(Function & _function, Rectangle & _rectangle, int _num_of_iter) :
	StopCriterion(_function, _rectangle, _num_of_iter) {}

by_gradient::by_gradient(Function & _function, Rectangle & _rectangle, double _eps) :
	StopCriterion(_function, _rectangle, _eps) {}

by_gradient::by_gradient(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps) :
	StopCriterion(_function, _rectangle, _num_of_iter, _eps) {}

bool by_gradient::if_stop(const Vector & x_current, const Vector & x_previous)
{
	if (num_of_iter == 0 || abs(norm(function.gradient(x_current, EPS))) < eps)
		return(true);
	--num_of_iter;
	return(false);
}

by_difference::by_difference(Function & _function, Rectangle & _rectangle) :
	StopCriterion(_function, _rectangle) {}

by_difference::by_difference(Function & _function, Rectangle & _rectangle, int _num_of_iter) :
	StopCriterion(_function, _rectangle, _num_of_iter) {}

by_difference::by_difference(Function & _function, Rectangle & _rectangle, double _eps) :
	StopCriterion(_function, _rectangle, _eps) {}

by_difference::by_difference(Function & _function, Rectangle & _rectangle, int _num_of_iter, double _eps) :
	StopCriterion(_function, _rectangle, _num_of_iter, _eps) {}

bool by_difference::if_stop(const Vector & x_current, const Vector & x_previous)
{
	if (num_of_iter == 0 || abs(function(x_current) - function(x_previous)) < eps)
		return(true);
	--num_of_iter;
	return(false);
}