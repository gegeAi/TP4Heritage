#include "DeleteFct.h"

//------------------------------------------------------- includes personnels

#include "AddFct.h"
#include "Project.h"

GenericFct * DeleteFct::operator()(Project & project)
// Algorithme
// copie de la Form a supprimer
// suppression de l'original
// creation d'un inverse avec la copie a reajouter
{
	Form * formToSave = toDelete->Clone();
	delete project.figure[toDelete->getName()];
	project.figure.erase(toDelete->getName());
	save = false;
	return new AddFct(formToSave, true);
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
