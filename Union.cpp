#include "Union.h"

bool Union::Hit(const Point & testPoint) const
{
	for(int i(0); i<group.size(); i++)
	{
		if(group[i]->Hit(testPoint))
		{
			return true;
		}
	}

	return false;
}

string Union::toString() const
{
	return "UNION " + ComplexForm::toString();
}

Union::Union(const string & argName):ComplexForm(argName)
{
#ifdef MAP
	cout << "Call to <Union> constructor" << endl;
#endif
}

Union::~Union()
{
#ifdef MAP
	cout << "Call to <Union> constructor" << endl;
#endif
}
