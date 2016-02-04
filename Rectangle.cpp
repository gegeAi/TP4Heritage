#include "Rectangle.h"
#include <sstream>

bool Rectangle::Hit(const Point & testPoint) const
{
	double scalarProduct1 = (testPoint.x-upLeft.x)*(bottomRight.x-upLeft.x);
	double scalarProduct2 = (bottomRight.x-upLeft.x)*(bottomRight.x-upLeft.x);
	
	double scalarProduct3 = (testPoint.y-upLeft.y)*(bottomRight.y-upLeft.y);
	double scalarProduct4 = (bottomRight.y-upLeft.y)*(bottomRight.y-upLeft.y);
	
	if(scalarProduct2 > scalarProduct1 && scalarProduct1 > 0)
	{
		if(scalarProduct4 > scalarProduct3 && scalarProduct3 > 0)
		{
			return true;
		}
	}
	
	return false;

}

void Rectangle::Move(const Offset & delta)
{
	upLeft.x += delta.x;
	bottomRight.x += delta.x;
	upLeft.y += delta.y;
	bottomRight.y += delta.y;
}

string Rectangle::toString() const
{
	ostringstream stream;
	stream << "RECTANGLE " << name << " (" << upLeft.x << ";" << upLeft.y << ") (" << bottomRight.x << ";" << bottomRight.y << ")";
	return stream.str();
}

Form* Rectangle::clone() const
{
	return new Rectangle(*this);
}

Rectangle::Rectangle(const string & argName, const Point & argUpLeft, const Point & argBottomRight) : Form(argName), 
upLeft(argUpLeft), bottomRight(argBottomRight)
{
#ifdef MAP
	cout << "Call to <Rectangle> constructor" << endl;
#endif
}

Rectangle::~Rectangle()
{
#ifdef MAP
	cout << "Call to <Rectangle> constructor" << endl;
#endif
}

