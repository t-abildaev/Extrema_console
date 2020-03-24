#pragma once

#include <chrono>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"
#include "StopCriterion.h"
#include "Random.h"


/**
@class Method
The class is an abstract class. It represents abstract optimization
method and should be the parent class for class which represents
specific method.
*/
class Method
{
protected:
	///This constant determines closeness of two numbers and exactness of calculating gradient
	const double EPS = 1e-6;
	///Dimension of domain of the function
	int dimension; 
	///Function to be optimized
	Function & function;
	///Rectangle where the function is optimized
	Rectangle & rectangle;
	///Initial guess for optimization process
	Vector initial;
	///Stop criterion for optimization process
	StopCriterion & stopCriterion; 
public:
	Method(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	virtual ~Method() {};
	///This method optimizes the function and prints the results
	virtual void optimize() = 0; 
	void set_init(const Vector & vector);
};

/**
@class Method
The class represents Random Search (Simple) method of optimization.
Next vector is being searched in small neighbourhood of current vector
(with probability p) or in the whole area (with probability 1 - p).
Delta determines the smallness of neighbourhood and decreases if search
in neighbourhood were succesfull.
*/
class RSS :
	public Method
{
protected:
	///Must be in (0,1)
	double p = 0.5;
	///Must be in (0,1)
	double delta = 0.25;
public:
	RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion, double _p, double delta);
	void optimize();
};

/**
@class Method
The class represents Polak-Ribiere Conjugate Gradient method of
optimization.
*/
class PRCG :
	public Method
{
public:
	PRCG(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	void optimize();
};