#pragma once
#ifndef _CONVEX_
#define _CONVEX_
#include "Polygon.h"

using namespace std;

// Інтерфейсний клас опуклої оболонки
class Convex
{
	//
	friend ostream& operator<<(ostream& os, const Convex& c);
public:
	Convex();
	~Convex();
	// Долучити чергову точку
	Convex& add(const Point&);
	// Залежно від кількості точок в оболонці
	// (одна, дві або більше) обчислити периметр або
	// звернутися до периметра многутника
	double perimeter() const;
	// Те ж саме з площею
	double area() const;

private:
	// Характеристика кількості точок в оболонці:
	// жодної, одна, дві або більше двох
	enum Angles {zero, one, two, many};
	Angles _angles;
	// Перші дві точки оболонки
	Point _a, _b;
	// Многокутник (кількість точок оболонки більша двох)
	Polygon * _pm;

	// Обробити першу точку
	void process0(const Point&);

	// Обробити другу точку
	void process1(const Point&);

	// Обробити третю точку
	void process2(const Point&);

	// Обробити наступну після третьої точки
	void processN(const Point&);
};

ostream& operator<<(ostream& os, const Convex& c);

#endif