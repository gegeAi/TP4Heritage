#ifndef FORM_H
#define FORM_H

#include <iostream>

#include "Point.h"

using namespace std;

class Form
{
	public :

		friend class ComplexForm;

		virtual bool Hit(const Point & testPoint) const = 0 ;
		virtual void Move(const Offset & delta) = 0;
		
		virtual string toString() const = 0; 

		Form(const string & argName);
		virtual ~Form();

	protected :

		string name;
};

ostream & operator<<(ostream & out, const Form & obj);

#endif // FORM_H
