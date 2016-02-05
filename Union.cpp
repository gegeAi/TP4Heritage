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

Form* Union::clone() const
{
	return new Union(*this);
}

string Union::toSerialString() const
{
	string toSave(ComplexForm::toSerialString());
	toSave += "OR ";
	toSave += name;
	string tpsToDelete("DELETE");;
	for(int i(0); i<group.size(); i++)
	{
		tpsToDelete += " ";
		tpsToDelete += group[i]->getName();
		toSave += " ";
		toSave += group[i]->getName();
	}

	toSave += "\n";
	toSave += tpsToDelete;

	return toSave;
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
