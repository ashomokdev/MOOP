#ifndef _SEGMENT_H_
#define _SEGMENT_H_
#include <iostream>
#include "Point.h"
using namespace std;
class Segment
{
private:
// ������ ���������� ������
static int _freeID;
const int _myId;
// ����� ������� ������
Point _a;
// ����� ���� ������
Point _b;

public:
// ������������ ������
// 1) �� ������������ ���� �����
Segment(const double x1=0, const double y1=0,
const double x2=1, const double y2=0);
// 2) �� ������� ������� � ����
Segment(const Point &start, const Point &end);
// 3) ����������� �����������
Segment(const Segment&);
// ����������
~Segment();
// ���������
Segment& operator=(const Segment&);
// ���������  �����
const Point& start() const;
const Point& end() const;
// ���������-������������ �����
Point &Segment::start();
Point &Segment::end();
// ��������� ��������� �����
const double &Segment::startX() const;
const double &Segment::startY() const;
const double &Segment::endX() const;
const double &Segment::endY() const;
// ���������-������������ ��������� �����
double &Segment::startX();
double &Segment::startY();
double &Segment::endX();
double &Segment::endY();
// ���������� ������� ������
double length () const;
// ���������� ������ �� ������ �� �����
double distance (const Point&) const;
// �������� ID
const int getID() const;
const Point nearest(const Point& c) const;
};

ostream& operator<<(ostream & k, const Segment & s);

#endif
