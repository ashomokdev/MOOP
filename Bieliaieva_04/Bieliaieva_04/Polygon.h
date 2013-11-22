#pragma once
#ifndef _POLYGON_
#define _POLYGON_

#include <deque>
#include <iostream>
#include "Segment.h"

using namespace std;

using std::deque;

// Клас Polygon забезпечує інтерфейс опуклої оболонки і
// двосторонньої черги, в якій зберігаються її точки
class Polygon
{
	friend std::ostream& operator<<(std::ostream&, Polygon);
public:
	// Занести до многокутника перші три точки
	Polygon(const Point&,const Point&,const Point&);
	~Polygon();

	//Долучити точку до многокутника
	void process(const Point&);
	double perimeter() const {return _perimeter;}
	double area() const {return _area;}

private:
	//Вершини опуклої оболонки, збережені в двосторонній черзі
	deque <Point> _d;

	//Кількість вершин в опуклій оболонці
	int _edges;

	//Значення периметру
	double _perimeter;

	//Значення площі
	double _area;

	//Перевірити, чи знаходиться точка a за стороною s
	bool illuminated(const Segment& s, const Point& a) const;

	// Замінити сторону s двома новими сторонами, кінцями сторони s і точкою a

	void delEdge(const Segment& s, const Point& a);
};

std::ostream& operator<<(std::ostream&, Polygon);

#endif