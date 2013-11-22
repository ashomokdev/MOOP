#include "Triangle.h"
#include <cmath>

unsigned int Triangle::_freeID = 0;

Triangle::Triangle(const double x1, const double y1,
				   const double x2, const double y2,
				   const double x3, const double y3):_a(x1,y1), _b(x2, y2), _c(x3, y3), _myID(_freeID++),
				   _ab(0), _bc(0), _ca(0),_height_a(0), _height_b(0), _height_c(0){
					   if (area()<0) 
						   throw BadTriangle(x1,y1,x2,y2,x3,y3);
}

Triangle::Triangle(const Point &a, const Point& b, const Point& c):_a(a), _b(b), _c(c), _myID(_freeID++),
	_ab(0), _bc(0), _ca(0), _height_a(0), _height_b(0), _height_c(0){
		if (area()<0) 
			throw BadTriangle(a,b,c);
}

Triangle::Triangle(const Point &a, const Segment & s): _a(a), _b(s.start()), _c(s.end()), _myID(_freeID++),
	_ab(0), _bc(0), _ca(0), _height_a(0), _height_b(0), _height_c(0){
		if (area()<0) 
			throw BadTriangle(a,s);
}

Triangle::Triangle (const Triangle& t): _a(t._a), _b(t._b), _c(t._c), _myID(_freeID++),
	_ab(0), _bc(0), _ca(0), _height_a(0), _height_b(0), _height_c(0){}

Triangle::~Triangle(){
	if(_ab != 0)
	{
		delete _ab;
		_ab = 0;
	}
	if(_bc != 0)
	{
		delete _bc;
		_bc = 0;
	}
	if(_ca != 0)
	{
		delete _ca;
		_ca = 0;
	}

	if(_height_a != 0)
	{
		delete _height_a;
		_height_a = 0;
	}
	if(_height_b != 0)
	{
		delete _height_b;
		_height_b = 0;
	}
	if(_height_c != 0)
	{
		delete _height_c;
		_height_c = 0;
	}
}

Triangle & Triangle::operator = (const Triangle& t){
	if (this==&t)
		return *this;
	_a=t._a;
	_b=t._b;
	_c=t._c; 
	_ab=t._ab;
	_bc=t._bc;
	_ca=t._ca;
	_height_a=t._height_a;
	_height_b=t._height_b;
	_height_c=t._height_c;
	return *this;
}

double Triangle::perimeter() const{
	return length_ab()+length_bc()+length_ca();
}

//ф-ла Герона
double Triangle::area() const{
	return sqrt((0.5*perimeter())*((0.5*perimeter())-length_ab())*((0.5*perimeter())-length_bc())*((0.5*perimeter())-length_ca()));
}

const Point& Triangle::apexA() const{
	return _a;
}

const Point& Triangle::apexB() const{
	return _b;
}

const Point& Triangle::apexC() const{
	return _c;
}

const Segment& Triangle::side_a() const{
	if(_bc == 0)
		_bc = new Segment(_b, _c);
	return *_bc;
}

const Segment& Triangle::side_b() const{
	if(_ca == 0)
		_ca = new Segment(_c, _a);
	return *_ca;
}

const Segment& Triangle::side_c() const{
	if(_ab == 0)
		_ab = new Segment(_a, _b);
	return *_ab;
}

double Triangle::length_ab() const{
	return side_c().length(); // виклик методу від методу
}

double Triangle::length_bc() const{
	return side_a().length(); 
}

double Triangle::length_ca() const{
	return side_b().length(); 
}

//формула для знаходження координат основи висоти
const Point Triangle:: base_of_heightA() const{
	double x, y;
	x=((apexA().y()-apexB().y())*(apexC().x()-apexB().x())*(apexC().y()-apexB().y())+(apexC().x()-apexB().x())*(apexC().x()-apexB().x())*apexA().x()+(apexC().y()-apexB().y())*(apexC().y()-apexB().y())*apexB().x())/((apexC().x()-apexB().x())*(apexC().x()-apexB().x())+(apexC().y()-apexB().y())*(apexC().y()-apexB().y()));
	if (apexC().x()==apexB().x()) y=apexA().y(); else
		y=apexB().y()+((apexC().y()-apexB().y())*(x-apexB().x()))/(apexC().x()-apexB().x());
	return Point (x,y);
}

const Point Triangle:: base_of_heightB() const{
	double x, y;
	x=((apexB().y()-apexC().y())*(apexA().x()-apexC().x())*(apexA().y()-apexC().y())+(apexA().x()-apexC().x())*(apexA().x()-apexC().x())*apexB().x()+(apexA().y()-apexC().y())*(apexA().y()-apexC().y())*apexC().x())/((apexA().x()-apexC().x())*(apexA().x()-apexC().x())+(apexA().y()-apexC().y())*(apexA().y()-apexC().y()));
	if (apexA().x()==apexC().x()) y=apexB().y(); else
		y=apexC().y()+((apexA().y()-apexC().y())*(x-apexC().x()))/(apexA().x()-apexC().x());
	return Point (x,y);
}

const Point Triangle:: base_of_heightC() const{
	double x, y;
	x=((apexC().y()-apexA().y())*(apexB().x()-apexA().x())*(apexB().y()-apexA().y())+(apexB().x()-apexA().x())*(apexB().x()-apexA().x())*apexC().x()+(apexB().y()-apexA().y())*(apexB().y()-apexA().y())*apexA().x())/((apexB().x()-apexA().x())*(apexB().x()-apexA().x())+(apexB().y()-apexA().y())*(apexB().y()-apexA().y()));
	if (apexB().x()==apexA().x()) y=apexC().y(); else
		y=apexA().y()+((apexB().y()-apexA().y())*(x-apexA().x()))/(apexB().x()-apexA().x());
	return Point (x,y);
}

const Segment& Triangle::height_a() const{
	if(_height_a == 0)
	{
		_height_base_a = new Point(base_of_heightA());
		_height_a = new Triangle::Segment(_a, *_height_base_a);
	}
	return *_height_a;
}

const Segment& Triangle::height_b() const{
	if(_height_b == 0)
	{
		_height_base_b = new Point(base_of_heightB());
		_height_b = new Triangle::Segment(_b, *_height_base_b);
	}
	return *_height_b;
}

const Segment& Triangle::height_c() const{
	if(_height_c == 0)
	{
		_height_base_c = new Point(base_of_heightC());
		_height_c = new Triangle::Segment(_c, *_height_base_c);
	}
	return *_height_c;
}

ostream& operator<<(ostream & os, const Triangle & t){
	os << "Points " << t.apexA() << t.apexB() << t.apexC() << endl 
		<< "Sides: " << "A: " << t.side_a() << "  B: " << t.side_b() << "  C: " << t.side_c() << endl
		<< "Lengths of sides: " << "AB: " << t.length_ab() << ";  BC: " << t.length_bc() << ";  CA: " << t.length_ca() << endl
		<< "Heights: " <<" From A: " << t.height_a() << "From B: " << t.height_b() << "From C: " << t.height_c() << endl
		<< "Perimeter: " << t.perimeter() << endl
		<< "Area: " << t.area();
	return os;
}

ostream& operator<<(ostream & os, const Triangle::BadTriangle & t){
	os << "Points " << t._a << t._b << t._c << endl;
	return os;
}
