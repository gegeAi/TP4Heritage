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

string ComplexForm::toSerialString() const
{
	string toSave;
	for(int i(0); i<group.size(); i++)
	{
		toSave += group[i]->toSerialString();
		toSave += "\n";
	}

	return toSave;
}

ComplexForm::ComplexForm(const string & name) : Form(name)
{
#ifdef MAP
	cout << "Call to <ComplexForm> constructor" << endl;
#endif
}

ComplexForm::ComplexForm(const ComplexForm & copy) : Form(copy)
{
	for(int i(0); i<copy.group.size(); i++)
	{
		group.push_back(copy.group[i]->clone());
	}
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
	group.push_back(anotherForm->clone());
	if(group.back()->name.find("_"+name) == string::npos)
	{
		group.back()->name += ("_" + name);
	}
}
