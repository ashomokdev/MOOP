#include "Point.h"

int Point::freeID = 0;

Point::Point(double x, double y):
	_x(x), _y(y), pointID(++freeID)
{

}

Point::Point(const Point& u):
	_x(u._x), _y(u._y), pointID(++freeID)
{

}


Point::~Point()
{

}

Point& Point::operator=(const Point& p)
{
	_x = p._x;
	_y = p._y;
	return *this;
}

double& Point::x()
{
	return _x;
}

double& Point::y()
{
	return _y;
}

const double& Point::x()const
{
	return _x;
}

const double& Point::y()const
{
	return _y;
}

const int Point::getID() const
{
	return pointID;
}

int Point::amount()
{
	return freeID;
}


ostream& operator<<(ostream& os, const Point& p)
{
	cout << '(' << p.x() << ',' << p.y() << ')';
	return os;
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x()+v.x(), u.y()+v.y());
}

Point& operator+=(Point& p, const Point& cp)
{
	p.x() += cp.x();
	p.y() += cp.y();
	return p;
}

bool operator==(const Point & u, const Point &v)
{
	return u.x() == v.x() && u.y() == v.y() ? true : false;
}

bool operator!=(const Point &u, const Point &v)
{
	return !(u == v);
}