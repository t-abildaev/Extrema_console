#pragma once

#include <chrono>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"
#include "StopCriterion.h"
#include "Random.h"

class Method
{
public:
	int dimension;
	Function* function;
	Rectangle* rectangle;
	StopCriterion* stopCriterion;
	Vector initial = Vector(dimension);
	Method(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion);
	Method(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector _initial);
	virtual ~Method() {};
	virtual void optimize() = 0;
	void setInitial(const Vector& vector);
};

class RSS :
	public Method
{
public:
	RSS(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion);
	RSS(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector initial);
	void optimize();
};

class PRCG :
	public Method
{
public:
	PRCG(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion);
	PRCG(int _dimension, Function* _function, Rectangle* _rectangle, StopCriterion* _stopCriterion, Vector initial);
	void optimize();
};