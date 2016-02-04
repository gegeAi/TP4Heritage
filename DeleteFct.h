#ifndef DELETE_FCT_H
#define DELETE_FCT_H

#include "GenericFct.h"
#include "Form.h"

using namespace std;

class DeleteFct : public GenericFct
{
	public :
	
	virtual GenericFct * operator()(Project & project);

	DeleteFct(Form * argToDelete, bool argSave = false);
	virtual ~DeleteFct();

	private :

	Form * toDelete;	
	bool save;
	
};

#endif // DELETE_FCT_H
