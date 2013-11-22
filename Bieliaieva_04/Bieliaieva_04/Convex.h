#pragma once
#ifndef _CONVEX_
#define _CONVEX_
#include "Polygon.h"

using namespace std;

// ������������ ���� ������ ��������
class Convex
{
	//
	friend ostream& operator<<(ostream& os, const Convex& c);
public:
	Convex();
	~Convex();
	// �������� ������� �����
	Convex& add(const Point&);
	// ������� �� ������� ����� � ��������
	// (����, �� ��� �����) ��������� �������� ���
	// ���������� �� ��������� ����������
	double perimeter() const;
	// �� � ���� � ������
	double area() const;

private:
	// �������������� ������� ����� � ��������:
	// �����, ����, �� ��� ����� ����
	enum Angles {zero, one, two, many};
	Angles _angles;
	// ����� �� ����� ��������
	Point _a, _b;
	// ����������� (������� ����� �������� ����� ����)
	Polygon * _pm;

	// �������� ����� �����
	void process0(const Point&);

	// �������� ����� �����
	void process1(const Point&);

	// �������� ����� �����
	void process2(const Point&);

	// �������� �������� ���� ������ �����
	void processN(const Point&);
};

ostream& operator<<(ostream& os, const Convex& c);

#endif