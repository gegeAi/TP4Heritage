#include "ComplexForm.h"

void ComplexForm::Move(const Offset & delta)
{
	for(int i(0); i<group.size(); i++)
	{
		group[i]->Move(delta);
	}
}

string ComplexForm::toString() const
{
	string display(name + " : ");
	for(int i(0); i<group.size()-1; i++)
	{
		display += group[i]->name;
		display += " | ";
	}

	display += group[group.size()-1]->name;

	return display;
}

ComplexForm::ComplexForm(const string & name) : Form(name)
{
#ifdef MAP
	cout << "Call to <ComplexForm> constructor" << endl;
#endif
}

ComplexForm::~ComplexForm()
{
#ifdef MAP
	cout << "Call to <ComplexForm> destructor" << endl;
#endif

	for(int i(0); i<group.size(); i++)
	{
		delete group[i];
	}
}


void ComplexForm::operator+=(Form * anotherForm)
{
	group.push_back(anotherForm);
}
