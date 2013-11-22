#pragma once
#ifndef _POLYGON_
#define _POLYGON_

#include <deque>
#include <iostream>
#include "Segment.h"

using namespace std;

using std::deque;

// ���� Polygon ��������� ��������� ������ �������� �
// ������������ �����, � ��� ����������� �� �����
class Polygon
{
	friend std::ostream& operator<<(std::ostream&, Polygon);
public:
	// ������� �� ������������ ����� ��� �����
	Polygon(const Point&,const Point&,const Point&);
	~Polygon();

	//�������� ����� �� ������������
	void process(const Point&);
	double perimeter() const {return _perimeter;}
	double area() const {return _area;}

private:
	//������� ������ ��������, �������� � ����������� ����
	deque <Point> _d;

	//ʳ������ ������ � ������ ��������
	int _edges;

	//�������� ���������
	double _perimeter;

	//�������� �����
	double _area;

	//���������, �� ����������� ����� a �� �������� s
	bool illuminated(const Segment& s, const Point& a) const;

	// ������� ������� s ����� ������ ���������, ������ ������� s � ������ a

	void delEdge(const Segment& s, const Point& a);
};

std::ostream& operator<<(std::ostream&, Polygon);

#endif