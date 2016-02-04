#ifndef ADD_FCT_H
#define ADD_FCT_H

#include "GenericFct.h"
#include "Form.h"

using namespace std;

class AddFct : public GenericFct
{
	public :
	
	virtual GenericFct * operator()(Project & project);

	void changeState();

	AddFct(Form * argToAdd, bool argSave = false);
	virtual ~AddFct();

	private :

	Form * toAdd;	
	bool save;
	
};

#endif // ADD_FCT_H