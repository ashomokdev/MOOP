#pragma once
#ifndef _CONVEX_CPP_
#define _CONVEX_CPP_

#include "Convex.h"
#include "Segment.h"
#include "Triangle.h"
#include <cassert>


Convex::Convex():
	_angles(zero),_pm(NULL)
{

}

Convex::~Convex()
{
	if ( _angles == many)
		delete _pm;
}

void Convex::process0(const Point& p)
{
	_a = p;
	_angles = one;
}

void Convex::process1(const Point& p)
{
	if (_a != p)
	{
		_b = p;
		_angles = two;
	}
}

void Convex::process2(const Point& p)
{
	if (Segment (_a, _b).distance(p) > 0)
	{
		_pm = new Polygon(_a, _b, p);
		_angles = many;
	}

	else if (Triangle (_b, Segment(_a,p)).area()==0)
		_b = p;
	else if (Triangle(_a,Segment(p,_b)).area()==0)
		_a = p;
}

void Convex::processN(const Point& p)
{
	_pm->process(p);
}

Convex& Convex::add(const Point& p)
{
	switch ( _angles)
	{
	case zero:
		process0(p);
		break;
	case one:
		process1(p);
		break;
	case two:
		process2(p);
		break;
	case many:
		processN(p);
		break;
	default:
		assert(false);
	}
	return *this;
}

double Convex::perimeter() const
{
	double ans = 0.0;
	switch ( _angles)
	{
	case many:
		ans = _pm->perimeter();
		break;
	case two:
		ans = 2 * Segment(_a,_b).length();
		break;
	default:
		ans = 0.0;
	}
	return ans;
}

double Convex::area() const
{
	return ( _angles == many) ? _pm->area() : 0.0;
}

ostream& operator<<(ostream& os, const Convex& c)
{
	switch(c. _angles)
	{
	case Convex::many:
		os<< *(c._pm);
		break;
	case Convex::two:
		os<< Segment(c._a, c._b);
		break;
	case Convex::one:
		os<< c._a;
		break;
	case Convex::zero:
		os<< "<empty>";
		break;
	}
	return os;
}

#endif