#pragma once
#ifndef _POLYGON_CPP_
#define _POLYGON_CPP_

#include "Polygon.h"
#include "Triangle.h"

Polygon::Polygon(const Point& a, const Point& b, const Point& c)
{
	_d.push_front(b);
	if (illuminated(Segment(a,c),b))
	{
		_d.push_front(a);
		_d.push_back(c);
	}
	else
	{
		_d.push_front(c);
		_d.push_back(a);
	}
	_edges = 3;
	_perimeter = Segment(a,b).length() + Segment(b,c).length() + Segment(c,a).length();
	_area = Triangle (a, b,c).area();
}

Polygon::~Polygon()
{}

void Polygon::delEdge(const Segment& s, const Point& p)
{
	_edges--;
	_perimeter -= s.length();
	_area += Triangle (p, s).area();
}

void Polygon::process(const Point &t)
{
	Point currentPoint;
	for (int i=0; i<_edges&&!illuminated(Segment(_d.back(), _d.front()), t); ++i)
	{
		currentPoint=_d.front();
		_d.pop_front();
		_d.push_back(currentPoint);
	}

	if(!illuminated(Segment(_d.back(), _d.front()), t))
		return;

	delEdge(Segment(_d.back(), _d.front()), t);
	currentPoint=_d.front();
	_d.pop_front();

	while(illuminated(Segment(currentPoint, _d.front()), t))
	{
		delEdge(Segment(currentPoint, _d.front()), t);
		currentPoint=_d.front();
		_d.pop_front();
	}
	_d.push_front(currentPoint);
	currentPoint=_d.back();
	_d.pop_back();

	while(illuminated(Segment(_d.back(), currentPoint), t))
	{
		delEdge(Segment(_d.back(), currentPoint), t);
		currentPoint= _d.back();
		_d.pop_back();
	}
	_d.push_back(currentPoint);

	_edges += 2;
	_perimeter += Segment(_d.back(), t).length()+ Segment(t,_d.front()).length();
	_d.push_front(t);
}

bool Polygon::illuminated(const Segment& s, const Point& p) const
{
	double a = Triangle (p, s).area();
	return ((a < 0.0) || (a == 0.0 && !Triangle (p, s).area()==0));
}

std::ostream& operator<<(std::ostream& os, Polygon p)
{
	os<< '{';
	for(deque<Point>::const_iterator i(p._d.begin()); i != p._d.end(); i++)
	{
		if(i != p._d.begin())
			os<< ',';
		os<< (*i);
	}
	os<< '}';
	return os;
}

#endif