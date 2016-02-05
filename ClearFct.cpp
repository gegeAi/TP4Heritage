#include "ClearFct.h"

//------------------------------------------------------- includes systemes

#include <fstream>
#include <sstream>

//------------------------------------------------------- includes personnels

#include "Project.h"
#include "LoadFct.h"

unsigned char ClearFct::numberCleared = 0;

GenericFct * ClearFct::operator()(Project & project)
// Algorithme
// generation du nom de la sauvegarde auto
// sauvegarde dans le fichier en cas de Undo
// purge de la figure
// renvoie de l'inverse parametre avec le chemin de la sauvegarde
{
	ostringstream name;
	name << "created_by_clear_" << (int)numberCleared << ".auto";
	project.Save(name.str().c_str());
	for(map<string, Form*>::iterator it(project.figure.begin()); it != project.figure.end(); it++)
	{
		delete it->second;
	}
	project.figure.erase(project.figure.begin(), project.figure.end());
	return new LoadFct(name.str().c_str());
}

ClearFct::ClearFct() : GenericFct()
{
#ifdef MAP
	cout << "Call to <ClearFct> constructor" << endl;
#endif

	numberCleared++;
}

ClearFct::~ClearFct()
{
#ifdef MAP
	cout << "Call to <ClearFct> destructor" << endl;
#endif
}
