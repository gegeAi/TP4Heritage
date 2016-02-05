//---------------------------ADD_FCT-------------------------------------

#ifndef ADD_FCT_H
#define ADD_FCT_H

//------------------------------------------------------- includes personnels

#include "GenericFct.h"
#include "Form.h"

using namespace std;

class AddFct : public GenericFct
{
	public :
	
//------------------------------------------------------- surcharge d'operateurs herites
	
	virtual GenericFct * operator()(Project & project);

//------------------------------------------------------- constructeurs/destructeur

	AddFct(Form * argToAdd, bool argSave = false);
	virtual ~AddFct();

	private :

//------------------------------------------------------- attributs prives

	Form * toAdd; // forme a ajouter	
	bool save; 
	// booleen de propriete. Si a true la fonction est proprietaire 
	// de la Form et devra la supprimer (utile dans le cas ou un inverse n'est jamais rappele dans 
	// l'historique)
};

#endif // ADD_FCT_H
