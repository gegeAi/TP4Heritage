#include "Intersection.h"

bool Intersection::Hit(const Point & testPoint) const
{
	for(int i(0); i<group.size(); i++)
	{
		if(!group[i]->Hit(testPoint))
		{
			return false;
		}
	}

	return true;
}

string Intersection::toString() const
{
	return "INTERSECTION " + ComplexForm::toString();
}

Form* Intersection::clone() const
{
	return new Intersection(*this);
}

Intersection::Intersection(const string & argName):ComplexForm(argName)
{
#ifdef MAP
	cout << "Call to <Intersection> constructor" << endl;
#endif
}

Intersection::~Intersection()
{
#ifdef MAP
	cout << "Call to <Intersection> constructor" << endl;
#endif
}
