#include "Rectangle.h"

virtual bool Rectangle::Hit(const Point & testPoint) const
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

virtual void Rectangle::Move(const Offset & delta)
{
	upLeft.x += delta.x;
	bottomRight.x += delta.x;
	upLeft.y += delta.y;
	bottomRight.y += delta.y;
}

string Segment::toString() const
{
	ostringstream stream;
	stream << "RECTANGLE " << name << " (" << upLeft.x << ";" << upLeft.y << ") (" << bottomRight.x << ";" << bottomRight.y << ")";
	return stream.str();
}

Rectangle::Rectangle(const string & name, const Point & upLeft, const Point & bottomRight) : Form(name), 
this->upLeft(upLeft), this->bottomRight(bottomRight)
{
#ifdef MAP
	cout << "Call to <Rectangle> constructor" << endl;
#endif
}

// todo check si il faut mettre : ~Form()

virtual Rectangle::~Rectangle()
{
#ifdef MAP
	cout << "Call to <Rectangle> constructor" << endl;
#endif
}

