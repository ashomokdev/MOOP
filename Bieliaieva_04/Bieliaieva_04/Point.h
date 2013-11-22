#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	Point (double x=0, double y=0);
	Point (const Point &);
	~Point();
	Point& operator=(const Point &);
	double& x();
	double& y();
	const double& x()const;
	const double& y()const;
	const int getID() const;
	static int amount();
};

ostream& operator<<(ostream&, const Point&);
const Point operator+(const Point&, const Point&);
Point& operator+=(Point&, const Point&);
bool operator==(const Point&, const Point&);
bool operator!=(const Point&, const Point&);
