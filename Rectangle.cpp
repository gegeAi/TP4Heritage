#include "Rectangle.h"

//------------------------------------------------------- includes systemes

#include <sstream>

bool Rectangle::Hit(const Point & testPoint) const
// Algorithme
// "deplace" le rectangle pour que upLeft corresponde a l'origine
// par deux demi produits scalaires, verifie que 0 < testPoint.x < bottomRight.x
// et 0 < testPoint.y < bottomRight.y
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
	upLeft += delta;
	bottomRight += delta;
}

string Rectangle::ToString() const
{
	ostringstream stream;
	stream << "RECTANGLE " << name << " (" << upLeft.x << ";" << upLeft.y << ") (" << bottomRight.x << ";" << bottomRight.y << ")";
	return stream.str();
}

string Rectangle::ToSerialString() const
{
	ostringstream toSave;
	toSave << "R " << name << " " << upLeft.x << " " << upLeft.y << " " << bottomRight.x << " " << bottomRight.y;
	return toSave.str();
}

Form* Rectangle::Clone() const
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

