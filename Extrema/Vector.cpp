#include <cmath>
#include "Vector.h"
#include <iostream>

Vector::Vector(int _dimension, bool indicator)
{
	dimension = _dimension;
	coordinates = new double[dimension] {};
	if (!indicator)
		for (int i = 0; i < dimension; ++i)
			(*this)[i] = 1;
}

Vector::Vector(double* _coordinates, int _dimension) :
	Vector(_dimension)
{
	for (int i = 0; i < dimension; ++i)
		coordinates[i] = _coordinates[i];
}

Vector::Vector(const Vector& vector) :
	Vector(vector.coordinates, vector.dimension) {}

double& Vector::operator [](int i)
{
	return(this->coordinates[i]);
}

Vector& Vector::operator =(const Vector& vector)
{
	if (this->dimension == vector.dimension)
		for (int i = 0; i < dimension; ++i)
			this->coordinates[i] = vector.coordinates[i];
	return(*this);
}

Vector& Vector::operator +=(const Vector& vector)
{
	if (this->dimension == vector.dimension)
		for (int i = 0; i < dimension; ++i)
			this->coordinates[i] += vector.coordinates[i];
	return(*this);
}

Vector& Vector::operator -=(const Vector& vector)
{
	if (this->dimension == vector.dimension)
		for (int i = 0; i < dimension; ++i)
			this->coordinates[i] -= vector.coordinates[i];
	return(*this);
}

Vector& Vector::operator -()
{
	Vector vector(*this);
	vector = (-1) * vector;
	return(vector);
}

bool Vector::operator <=(const Vector& vector)
{
	for (int i = 0; i < this->dimension; ++i)
		if ((*this).coordinates[i] > vector.coordinates[i])
			return(false);
	return(true);
}

Vector operator +(const Vector& vector1, const Vector& vector2)
{
	Vector vector = vector1;
	return(vector += vector2);
}

Vector operator -(const Vector& vector1, const Vector& vector2)
{
	Vector vector = vector1;
	return(vector -= vector2);
}

Vector operator *(double lambda, const Vector& vector1)
{
	Vector vector = vector1;
	for (int i = 0; i < vector1.dimension; ++i)
		vector[i] *= lambda;
	return(vector);
}

Vector operator *(const Vector& vector1, double lambda)
{
	Vector vector = vector1;
	for (int i = 0; i < vector1.dimension; ++i)
		vector[i] *= lambda;
	return(vector);
}

Vector operator /(const Vector& vector1, double lambda)
{
	Vector vector = vector1;
	for (int i = 0; i < vector1.dimension; ++i)
		vector[i] /= lambda;
	return(vector);
}

double operator *(const Vector& vector1, const Vector& vector2)
{
	double s{};
	if (vector1.dimension == vector2.dimension)
		for (int i = 0; i < vector1.dimension; ++i)
			s += vector1.coordinates[i] * vector2.coordinates[i];
	return(s);
}

double norm(const Vector& vector)
{
	double s{};
	for (int i = 0; i < vector.dimension; ++i)
		s += vector.coordinates[i] * vector.coordinates[i];
	return(sqrt(s));
}