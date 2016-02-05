#include "AddFct.h"

//------------------------------------------------------- includes personnels

#include "DeleteFct.h"
#include "Project.h"

GenericFct * AddFct::operator()(Project & project)
{
	project.figure[toAdd->getName()] = toAdd;
	save = false;
	return new DeleteFct(toAdd, true);
}

AddFct::AddFct(Form * argToAdd, bool argSave) : GenericFct(), toAdd(argToAdd), save(argSave)
{
#ifdef MAP
	cout << "Call to <AddFct> constructor" << endl;
#endif
}

AddFct::~AddFct()
{
#ifdef MAP
	cout << "Call to <AddFct> destructor" << endl;
#endif

	if(save)
	{
		delete toAdd;
	}
}
