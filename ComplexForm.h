#ifndef COMPLEX_FORM_H
#define COMPLEX_FORM_H

#include <vector>

#include "Form.h"

class ComplexForm : public Form
{
	public :

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const string & line);

		virtual void Move(const Offset & delta);

		ComplexForm(const string & name);
		virtual ~ComplexForm();

		void operator+=(const Form & anotherForm);

	private :

		vector<Form> group;
};

#endif // COMPLEX_FORM_H
