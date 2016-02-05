#include "DeleteFct.h"

#include "AddFct.h"
#include "Project.h"

GenericFct * DeleteFct::operator()(Project & project)
{
	//Form * formToSave = toDelete;
	//delete project.figure[toDelete->getName()];
	project.figure.erase(toDelete->getName());
	save = false;
	return new AddFct(toDelete, true);
}

DeleteFct::DeleteFct(Form * argToDelete, bool argSave) : GenericFct(), toDelete(argToDelete), save(argSave)
{
#ifdef MAP
	cout << "Call to <DeleteFct> constructor" << endl;
#endif
}

DeleteFct::~DeleteFct()
{
#ifdef MAP
	cout << "Call to <DeleteFct> destructor" << endl;
#endif

	if(save)
	{
		delete toDelete;
	}
}
