#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include <iostream>
#include "Segment.h"
using namespace std;

class Triangle: private Segment //означає, що клас Triangle побудований на основі класів Segment, Point 
{	
private:

	// тут необхідно використовувати композицію, бо точка і сегмент - невідємні складові трикутника.
	// композиція задає найбільш жорстку залежність існування екземплярів класу контейнеру (Triangle)
	// і екземплярів класів, що в ньому містяться (Point, Segment)
	
	Point _a,_b,_c;

	mutable Segment* _ab;
	mutable Segment* _bc;
	mutable Segment* _ca;

	mutable Segment* _height_a;
	mutable Segment* _height_b;
	mutable Segment* _height_c;

	mutable Point* _height_base_a;
	mutable Point* _height_base_b;
	mutable Point* _height_base_c;
	

	static unsigned int _freeID;
	const unsigned int _myID;

public:
	struct BadTriangle;

	Triangle(const double x1=0, const double y1=0,
		const double x2=1, const double y2=0,
		const double x3=0, const double y3=1);
	Triangle(const Point &a, const Point& b, const Point& c);
	Triangle(const Point &a, const Segment & s);
	Triangle (const Triangle&);
	~Triangle();

	Triangle & operator = (const Triangle &);
	double perimeter() const;
	double area() const;

	// Вершини
	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	// Сторони
	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	// Довжини сторін
	double length_ab() const;
	double length_bc() const;
	double length_ca() const;

	// Висоти
	// Бонус: Як потрібно визначити трикутник, щоб висоти набули сигнатури
const Segment& height_a() const;
const Segment& height_b() const;
const Segment& height_c() const;

const Point base_of_heightA() const;
const Point base_of_heightB() const;
const Point base_of_heightC() const;
};

struct Triangle::BadTriangle{
	Point _a, _b, _c;
	Triangle::BadTriangle(const Point &a, const Point& b, const Point& c):_a(a), _b(b), _c(c){};
	Triangle::BadTriangle(const double x1, const double y1,
				   const double x2, const double y2,
				   const double x3, const double y3):_a(x1,y1), _b(x2, y2), _c(x3, y3){};
	Triangle::BadTriangle(const Point &a, const Segment & s): _a(a), _b(s.start()), _c(s.end()){};
};

ostream& operator<<(ostream &, const Triangle &);
ostream& operator<<(ostream &, const Triangle::BadTriangle &);

#endif