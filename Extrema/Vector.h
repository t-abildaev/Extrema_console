#pragma once

class Vector
{
public:
	int dimension;
	double* coordinates;
	Vector(int _dimension, bool indicator = true);
	Vector(double* _coordinates, int _dimension);
	Vector(const Vector& vector);
	~Vector() { delete[] coordinates; };
	double& operator [](int i);
	Vector& operator =(const Vector& vector);
	Vector& operator +=(const Vector& vector);
	Vector& operator -=(const Vector& vector);
	Vector& operator -();
	bool operator <=(const Vector& vector);
	friend Vector operator +(const Vector& vector1, const Vector& vector2);
	friend Vector operator -(const Vector& vector1, const Vector& vector2);
	friend Vector operator *(double lambda, const Vector& vector1);
	friend Vector operator *(const Vector& vector1, double lambda);
	friend Vector operator /(const Vector& vector1, double lambda);
	friend double operator *(const Vector& vector1, const Vector& vector2);
	friend double norm(const Vector& vector);
};