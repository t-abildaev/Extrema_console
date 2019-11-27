#pragma once

#include <chrono>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"
#include "StopCriterion.h"
#include "Random.h"

class Method
{
protected:
	int dimension;
	Function& function;
	Rectangle& rectangle;
	StopCriterion& stopCriterion;
	Vector initial = Vector(dimension);
public:
	Method(int _dimension, Function& _function, Rectangle& _rectangle, StopCriterion& _stopCriterion, Vector _initial);
	virtual ~Method() {};
	virtual void optimize() = 0;
	void setInitial(const Vector& vector);
};

class RSS :
	public Method
{
protected:
	double p = 0.5;
public:
	RSS(int _dimension, Function& _function, Rectangle& _rectangle, StopCriterion& _stopCriterion, Vector initial, double _p);
	void optimize();
};

class PRCG :
	public Method
{
public:
	PRCG(int _dimension, Function& _function, Rectangle& _rectangle, StopCriterion& _stopCriterion, Vector initial);
	void optimize();
};