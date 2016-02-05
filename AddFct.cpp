#include "AddFct.h"

//------------------------------------------------------- includes personnels

#include "DeleteFct.h"
#include "Project.h"

GenericFct * AddFct::operator()(Project & project)
{
	// Utilisation d'un goto pour eviter la vérification sur toute la boucle en parametre
	// d'un eventuel while
	// --> a chaque modification, il faut recommencer le test, et sans goto, il faudrait
	// separer le test et la modification pour en ressortir un booleen pour un while
	begin :
	for(int i(0); i< project.figure.size(); i++)
	{
		if(project.figure[i]->getName().compare(toAdd.getName) == 0)
		{
			toAdd->correctSameName();
			goto begin;
		}
	}
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
