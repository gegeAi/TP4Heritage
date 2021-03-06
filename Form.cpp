#include "Form.h"

using namespace std;

string Form::getName() const
{
	return name;
}

void Form::CorrectSameName()
{
	name += ".copy";
}

Form::Form(const string & argName) : name(argName)
{
#ifdef MAP
	cout << "Call to <Form> constructor" << endl;
#endif
}

Form::~Form()
{
#ifdef MAP
	cout << "Call to <Form> constructor" << endl;
#endif
}

ostream & operator<<(ostream & out, const Form & obj)
{
	return out << obj.ToString();
}
