#include "ComplexForm.h"

virtual string ToSerializableString() const
{
	string serialStr = "<";

	for(int i(0); i<group.size(); i++)
	{
		serialStr += group[i].toSerializableString();
		serialStr += "|";
	}
	serialStr += ">";
	return serialStr;
}

virtual void LoadOperation(const string & line)
{
	
}

virtual void Move(const Offset & delta)
{
	for(int i(0); i<group.size(); i++)
	{
		group[i].move(delta);
	}
}

ComplexForm(const string & name) : Form(name)
{
#ifdef MAP
	cout << "Call to <ComplexForm> constructor" << endl;
#endif
}

virtual ~ComplexForm()
{
#ifdef MAP
	cout << "Call to <ComplexForm> destructor" << endl;
#endif
}


void operator+=(const Form & anotherForm)
{
	group.push_back(anotherForm);
}
