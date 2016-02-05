#include "Intersection.h"

bool Intersection::Hit(const Point & testPoint) const
// Algorithme
// Pour chaque Form de group faire :
// Si testPoint n'est pas dans la forme 
// retourner false
// fin pour
// retourner true
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

string Intersection::ToString() const
{
	return "INTERSECTION " + ComplexForm::ToString();
}

string Intersection::ToSerialString() const
// Algorithme
// renvoie une chaque de la forme
// "creation composante 1"
// ..
// "creation composante n"
// OI name [nom des composantes]"
// DELETE [nom des composantes]
{
	string toSave(ComplexForm::ToSerialString());
	toSave += "OI ";
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

Form* Intersection::Clone() const
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
