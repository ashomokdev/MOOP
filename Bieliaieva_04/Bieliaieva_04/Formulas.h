#pragma once
#ifndef _FORMULAS_
#define _FORMULAS_

#include "Segment.h"
#include <cmath>

//inline double triangleArea(const Point & a, const Point & b, const Point & c)
//{
//	return 0.5*((a.x() - c.x()) * (b.y() - c.y()) - (a.y() - c.y()) * (b.x() - c.x()));
//}
//
//inline bool sameLine(const Point & a, const Point & b, const Point & c)
//{
//	return !(bool)triangleArea(a,b,c);
//}

inline double dist(const Point & a, const Point & b)
{
	return Segment(a,b).length();
}

inline bool belongs(const Point & t, const Segment & s)
{
	return (dist(s.start(),t) + dist(t,s.end()) <= dist(s.start(),s.end()));
}

inline double round(double d, double prec = 1.0)
{
	return (fabs(d - floor(d)) >= 0.5?ceil(d):floor(d));
}

#endif