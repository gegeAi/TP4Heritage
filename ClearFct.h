//---------------------------CLEAR_FCT-------------------------------------

#ifndef CLEAR_FCT_H
#define CLEAR_FCT_H

//------------------------------------------------------- includes personnels

#include "GenericFct.h"
#include "Point.h"

using namespace std;

class ClearFct : public GenericFct
{
	public :

//------------------------------------------------------- classes amies

	friend class LoadFct;

//------------------------------------------------------- surcharge d'operateurs herites

	virtual GenericFct * operator()(Project & project);

	ClearFct(); 
	virtual ~ClearFct();

	private :

//------------------------------------------------------- attributs prives statiques

	static unsigned char numberCleared;
	// utilise pour le nom de la sauvegarde auto
	// incremente a chaque clear
	// decremente a chaque load
};

#endif // CLEAR_FCT_H
