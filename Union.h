//---------------------------UNION-------------------------------------

#ifndef UNION_H
#define UNION_H

//------------------------------------------------------- includes personnels

#include "ComplexForm.h"

using namespace std;

class Union : public ComplexForm
{
	public :

//------------------------------------------------------- methodes heritees de Form
		
		virtual bool Hit(const Point & testPoint) const;

		virtual string ToString() const;
		// Mode d'emploi
		// renvoie l'image de l'objet sous la forme
		// UNION name : group[0].name | .. | group[n].name
		
		virtual string ToSerialString() const;
	
		virtual Form* Clone() const;		

//------------------------------------------------------- constructeurs/destructeur

		Union(const string & argName);
		virtual ~Union();

};

#endif // UNION_H
