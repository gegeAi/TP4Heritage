//---------------------------DELETE_FCT-------------------------------------

#ifndef DELETE_FCT_H
#define DELETE_FCT_H

//------------------------------------------------------- includes personnels

#include "GenericFct.h"
#include "Form.h"

using namespace std;

class DeleteFct : public GenericFct
{
	public :

//------------------------------------------------------- surcharge d'operateurs herites

	virtual GenericFct * operator()(Project & project);

//------------------------------------------------------- constructeurs/destructeur

	DeleteFct(Form * argToDelete, bool argSave = false);
	virtual ~DeleteFct();

	private :

//------------------------------------------------------- attributs prives

	Form * toDelete; // forme a supprimer	
	bool save;
	// booleen de propriete. Si a true la fonction est proprietaire 
	// de la Form et devra la supprimer (utile dans le cas ou un inverse n'est jamais rappele dans 
	// l'historique)
	
};

#endif // DELETE_FCT_H
