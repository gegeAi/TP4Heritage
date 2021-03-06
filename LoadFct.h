//---------------------------LOAD_FCT-------------------------------------

#ifndef LOAD_FCT_H
#define LOAD_FCT_H

//------------------------------------------------------- includes personnels

#include "GenericFct.h"
#include "Point.h"

using namespace std;

class LoadFct : public GenericFct
{
	public :

//------------------------------------------------------- surcharge d'operateurs herites

	virtual GenericFct * operator()(Project & project);

//------------------------------------------------------- constructeurs/destructeur

	LoadFct(const string & argFileName, bool deleteOnDeath = false); 
	// Mode d'emploi 
	// argFileName : nom du fichier
	// deleteOnDeath : suppression du fichier lu a la destruction de l'objet
	// (cas de lecture sauvegarde auto)
	virtual ~LoadFct();

	private :

//------------------------------------------------------- attributs prives

	const string fileName;	
	bool del;
	
};

#endif // LOAD_FCT_H
