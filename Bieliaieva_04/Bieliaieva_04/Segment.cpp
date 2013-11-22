#include "Segment.h"
#include <cmath>
int Segment::_freeID(0);

Segment::Segment(const double x1, const double y1,
				 const double x2, const double y2):
	_a(x1, y1), _b(x2, y2), _myId(++_freeID) {}

Segment::Segment(const Point &start, const Point &end):
	_a(start), _b(end), _myId(++_freeID) {}

Segment::Segment(const Segment& s):
	_a(s._a), _b(s._b), _myId(_freeID++) {}

Segment::~Segment() {}

Segment& Segment::operator=(const Segment& s) {
	_a = s.start();
	_b = s.end();
	return *this;
	};

const Point& Segment::start() const{
	return _a;
};

const Point& Segment::end() const{
	return _b;
};

Point& Segment::start(){
	return _a;
};

Point& Segment::end(){
	return _b;
};

const double &Segment::startX() const {
	return _a.x();
}

const double &Segment::startY() const {
	return _a.y();
}

const double &Segment::endX() const {
	return _b.x();
}

const double &Segment::endY() const {
	return _b.y();
}

double &Segment::startX() {
	return _a.x();
}

double &Segment::startY() {
	return _a.y();
}

double &Segment::endX() {
	return _b.x();
}

double &Segment::endY()  {
	return _b.y();
}

double Segment::length () const {
	return sqrt((endX()-startX())*(endX()-startX()) + (endY()-startY())*(endY()-startY()));
}

double Segment::distance (const Point& c) const{
	//c - point, ab - segment 
	double ab = this->length();
	double ac = sqrt((_a.x()-c.x())*(_a.x()-c.x())+(_a.y()-c.y())*(_a.y()-c.y()));
	double bc = sqrt((_b.x()-c.x())*(_b.x()-c.x())+(_b.y()-c.y())*(_b.y()-c.y()));
	
	//cosinus theorem:
	if (bc*bc >= ab*ab + ac*ac){
		return ac;
	}

	if (ac*ac >= ab*ab + bc*bc){
		return bc;
	}else{
		//Heron theorem:
		double p = 0.5 * (ab + ac + bc);
		double S = sqrt(p*(p-ab)*(p-bc)*(p-ac));
		return 2 * S / ab;
	}
};

const int Segment::getID() const {
	return _myId;
}

ostream& operator<<(ostream & k, const Segment & s) {
	k << s.start() << s.end();
	return k;
};





