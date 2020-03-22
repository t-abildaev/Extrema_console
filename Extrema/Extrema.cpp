﻿// Extrema.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cmath>
#include <iostream>
#include "Vector.h"
#include "Function.h"
#include "Rectangle.h"
#include "StopCriterion.h"
#include "Method.h"

void begin()
{
	int k = 0;
	int l = 0;
	int dimension = 0;
	double p = 0;
	double delta = 0;
	double eps = 0;

	Function * function{};
	StopCriterion * sc{};
	Method * method{};

	std::cout << "Please, choose the function:" << std::endl;
	std::cout << "1. 'Exponential': f(x, y) = exp(x) + exp(y)" << std::endl;
	std::cout << "2. 'Trigonometric': f(x, y) = sin(x) + cos(y)" << std::endl;
	std::cout << "3. 'Rosenbrock': f(x, y, z) = (1 - x)^2 + 100(y - x)^2 + (1 - y)^2 + 100(z - y)^2" << std::endl;
	std::cout << "4. 'Quadratic': f(x, y, z, t) = (x - 1)^2 + (y - 2)^2 + (z - 3)^2 + (t - 4)^2" << std::endl;
	std::cin >> k;

	switch (k)
	{
	case 1:
		function = new Exponential;
		dimension = 2; break;
	case 2:
		function = new Trigonometric;
		dimension = 2; break;
	case 3:
		function = new Rosenbrock;
		dimension = 3; break;
	case 4:
		function = new Quadratic;
		dimension = 4; break;
	}
	std::cout << std::endl;

	std::cout << "Please, enter segments" << std::endl;
	Vector a(dimension);
	Vector b(dimension);
	for (int i = 0; i < dimension; ++i)
	{
		std::cin >> p;
		a[i] = p;
		std::cin >> p;
		b[i] = p;
	}
	Rectangle* rectangle = new Rectangle(a, b);
	Vector init(dimension);
	std::cout << std::endl;

	std::cout << "Please, enter initial guess" << std::endl;
	for (int i = 0; i < dimension; ++i)
	{
		std::cin >> p;
		init[i] = p;
	}
	std::cout << std::endl;

	std::cout << "Please, enter number of iterations" << std::endl;
	std::cin >> l;
	std::cout << std::endl;
	std::cout << "Please, enter eps of stop criterion" << std::endl;
	std::cin >> eps;
	std::cout << std::endl;
	std::cout << "Please, choose the stop criterion:" << std::endl;
	std::cout << "1. Stop by difference" << std::endl;
	std::cout << "2. Stop by norm of gradient" << std::endl;
	std::cin >> k;
	switch (k)
	{
	case 1:
		sc = new by_difference(*function, *rectangle, l, eps);
		break;
	case 2:
		sc = new by_gradient(*function, *rectangle, l, eps);
		break;
	}
	std::cout << std::endl;

	std::cout << "Please, choose the method:" << std::endl;
	std::cout << "1. 'RSS': Random Search Simple method" << std::endl;
	std::cout << "2. 'PRCG': Polak-Ribiere Conjugate Gradient method" << std::endl;
	std::cin >> k;
	std::cout << std::endl;
	switch (k)
	{
	case 1:
		std::cout << "Please, enter p" << std::endl;
		std::cin >> p;
		std::cout << std::endl;
		std::cout << "Please, enter delta for neighbourhood (0 < delta < 1)" << std::endl;
		std::cin >> delta;
		method = new RSS(dimension, *function, *rectangle, init, *sc, p, delta);
		break;
	case 2:
		method = new PRCG(dimension, *function, *rectangle, init, *sc);
		break;
	}
	std::cout << std::endl;

	method->optimize();
	std::cout << std::endl;

	delete method;
	delete function;
	delete rectangle;
	delete sc;
}

int main()
{
	int k = 0;
	bool b = true;
	while (b)
	{
		begin();
		std::cout << std::endl;
		std::cout << "1. Continue" << std::endl;
		std::cout << "2. Quit" << std::endl;
		std::cin >> k;
		if (k == 2) b = false;
		std::cout << std::endl;
	}
}

//int main()
//{
//	Function * function{};
//	StopCriterion*  sc{};
//	Method * method{};
//	Rectangle * rectangle{};
//
//	int n = 100;
//	double p = 0.5;
//	double delta = 0.25;
//	double eps = 0.00001;
//
//	int dimension = 2;
//	Vector a(dimension, -1);
//	Vector b(dimension, 1);
//	Vector initial(dimension, 0.5);
//	function = new Trigonometric;
//	//function = new Exponential;
//
//	int dimension = 3;
//	Vector a(dimension, 0);
//	Vector b(dimension, 10);
//	Vector initial(dimension, 5);
//	function = new Rosenbrock;
//
//	int dimension = 4;
//	Vector a(dimension, 0);
//	Vector b(dimension, 5);
//	Vector initial(dimension, 1);
//	function = new Quadratic;
//
//	rectangle = new Rectangle(a, b);
//
//	sc = new by_gradient(*function, *rectangle, n, eps);
//	sc = new by_difference(*function, *rectangle, n, eps);
//	
//	method = new PRCG(dimension, *function, *rectangle, initial , *sc);
//	method->optimize();
//
//	delete method;
//	delete function;
//	delete rectangle;
//	delete sc;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
