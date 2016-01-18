#include "Form.h"

Form::Form(const string & name) : this->name(name)
{
#ifdef MAP
	cout << "Call to <Form> constructor" << endl;
#endif
}

virtual Form::~Form() : ~Serializable()
{
#ifdef MAP
	cout << "Call to <Form> constructor" << endl;
#endif
}
