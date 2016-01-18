#include "Point.h"

Point Point::operator+(const Point & p2) const
{
	Point p3(x + p2.x, y + p2.y);
	return p3;
}
void Point::operator+=(const Point & p2)
{
	x += p2.x;
	y += p2.y;
}

void Point::operator-=(const Point & p2)
{
	x -= p2.x;
	y -= p2.y;
}

Point::Point(int x, int y)
{
#ifdef MAP
	cout << "Call to <Point> constructor" << endl;
#endif
	this->x = x; 
	this->y = y;
}

Point::Point() : x(0), y(0)
{

}

Point::~Point()
{
#ifdef MAP
	cout << "Call to <Point> destructor" << endl;
#endif
}
