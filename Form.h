#ifndef FORM_H
#define FORM_H

#include "Point.h

class Form
{
	public :

		virtual bool Hit(const Point & testPoint) = 0 const;
		virtual void Move(const Offset & delta) = 0;

		Form(const string & name);
		virtual ~Form();

	protected :

		string name;
};

#endif // FORM_H
