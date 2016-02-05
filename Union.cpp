#include "Union.h"

bool Union::Hit(const Point & testPoint) const
// Algorithme
// Pour chaque Form de group faire :
// Si testPoint est dans la forme 
// retourner true
// fin pour
// retourner false
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

string Union::ToString() const
{
	return "UNION " + ComplexForm::ToString();
}



string Union::ToSerialString() const
// Algorithme
// renvoie une chaque de la forme
// "creation composante 1"
// ..
// "creation composante n"
// OR name [nom des composantes]"
// DELETE [nom des composantes]
{
	string toSave(ComplexForm::ToSerialString());
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

Form* Union::Clone() const
{
	return new Union(*this);
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
