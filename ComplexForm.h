//---------------------------COMPLEX_FORM-------------------------------------

#ifndef COMPLEX_FORM_H
#define COMPLEX_FORM_H

//------------------------------------------------------- includes systemes

#include <vector>

//------------------------------------------------------- includes personnels

#include "Form.h"

//------------------------------------------------------- classe

using namespace std;

class ComplexForm : public Form
{
	public :
		
//------------------------------------------------------- methodes heritees de Form

		virtual bool Hit(const Point & testPoint) const = 0 ;
		virtual void Move(const Offset & delta);

		virtual string ToString() const;
		virtual string ToSerialString() const;
		// Mode d'emploi 
		// partie commune des methodes ToSerialString heritees de ComplexForm

		virtual Form* Clone() const = 0;

//------------------------------------------------------- constructeurs/destructeur

		ComplexForm(const string & name);
		ComplexForm(const ComplexForm & copy);
		virtual ~ComplexForm();

//------------------------------------------------------- surcharge d'operateurs

		void operator+=(Form * anotherForm);
		// Mode d'emploi :
		// ajoute une nouvelle forme a group,
		// et la renomme eventuellement si elle n'a pas le format souhaite
		// format : anotherForm->name_this->name

	protected :

//------------------------------------------------------- attributs protected

		vector<Form *> group;
};

#endif // COMPLEX_FORM_H
