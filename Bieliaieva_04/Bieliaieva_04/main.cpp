#include <iostream>
#include "Convex.h"
#include <cassert>



using namespace std;

void convInfo(const Convex&);



int main()
{
	{
		cout<< "Creating convex" << endl;
		Convex c;
		convInfo(c);
		cout<< "Adding point (0,0)" << endl;
		c.add(Point(0,0));
		convInfo(c);
		cout<<  "Adding point (0,1)" << endl;
		c.add(Point(0,1));
		convInfo(c);		
		cout<<  "Adding point (0,2)" << endl;
		c.add(Point(0,2));
		convInfo(c);
		cout<< "Adding point (1,0)" << endl;
		c.add(Point(1,0));
		convInfo(c);
		cout<< c << endl;
		cout<< "Deleting convex " << endl;
	}

	{
		cout<< "Creating convex" << endl;
		Convex c;
		convInfo(c);
		cout<< "Adding point (0,0)" << endl;
		c.add(Point(0,0));
		convInfo(c);
		cout<< "Adding point (1,1)" << endl;
		c.add(Point(1,1));
		convInfo(c);
		cout<< "Adding point (2,2)" << endl;
		c.add(Point(2,2));
		convInfo(c);		
		cout<< "Deleting convex " << endl;
	}

	system("pause");
	return 0;
};

void convInfo(const Convex& c)
{
	cout<< "Info about convex:\n";
	cout<< "\tUttermost points: " << c << endl;
	cout<< "\tPerimeter: " << c.perimeter() << endl;
	cout<< "\tArea: " << c.area() << endl;
}