#ifndef COMPLEX_FORM_H
#define COMPLEX_FORM_H

#include <vector>

#include "Form.h"

using namespace std;

class ComplexForm : public Form
{
	public :
		
		virtual bool Hit(const Point & testPoint) const = 0 ;
		virtual void Move(const Offset & delta);

		virtual string toString() const;

		ComplexForm(const string & name);
		virtual ~ComplexForm();

		void operator+=(Form * anotherForm);

	protected :

		vector<Form *> group;
};

#endif // COMPLEX_FORM_H
