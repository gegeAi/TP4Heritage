//---------------------------INTERSECTION-------------------------------------

#ifndef INTERSECTION_H
#define INTERSECTION_H

//------------------------------------------------------- includes personnels

#include "ComplexForm.h"

using namespace std;

class Intersection : public ComplexForm
{
	public :

//------------------------------------------------------- methodes heritees de Form
		
		virtual bool Hit(const Point & testPoint) const;

		virtual string ToString() const;
		// Mode d'emploi
		// renvoie l'image de l'objet sous la forme
		// INTERSECTION name : group[0].name | .. | group[n].name
		
		virtual string ToSerialString() const;
	
		virtual Form* Clone() const;		

//------------------------------------------------------- constructeurs/destructeur

		Intersection(const string & argName);
		virtual ~Intersection();

};

#endif // INTERSECTION_H
