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
	Function & function;
	Rectangle & rectangle;
	Vector initial;
	StopCriterion & stopCriterion;
public:
	Method(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	virtual ~Method() {};
	virtual void optimize() = 0;
	void set_init(const Vector & vector);
};

class RSS :
	public Method
{
protected:
	double p = 0.5;
	double delta = 0.25;
public:
	RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	RSS(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion, double _p, double delta);
	void optimize();
};

class PRCG :
	public Method
{
public:
	PRCG(int _dimension, Function & _function, Rectangle & _rectangle, Vector _initial, StopCriterion & _stopCriterion);
	void optimize();
};