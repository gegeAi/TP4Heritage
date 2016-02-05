#include "LoadFct.h"

//------------------------------------------------------- includes systemes

#include <cstdio>
#include <fstream>

//------------------------------------------------------- includes personnels

#include "Project.h"
#include "ClearFct.h"

bool readLine(string & line, Project & subject);

GenericFct * LoadFct::operator()(Project & project)
// Algorithme
// lecture du fichier :
// pour chaque ligne :
// bypass historique
// bypass sortie standard
// interpretation de la ligne
// fin bypass
{
	ifstream file(fileName.c_str());
	
	char * buff = new char[256];
	while(file.getline(buff, 256))
	{
		string s;
		s += buff;
		streambuf *backup = cout.rdbuf(NULL);
		project.bypassHisto = true;
		readLine(s, project);
		project.bypassHisto = false;
		cout.rdbuf(backup);
	}
	file.close();
	delete buff;
	return new ClearFct();
}

LoadFct::LoadFct(const string & argFileName, bool deleteOnDeath) : GenericFct(), fileName(argFileName), del(deleteOnDeath)
{
#ifdef MAP
	cout << "Call to <LoadFct> constructor" << endl;
#endif
}

LoadFct::~LoadFct()
{
#ifdef MAP
	cout << "Call to <LoadFct> destructor" << endl;
#endif

	if(del)
	{
		remove(fileName.c_str());
		ClearFct::numberCleared--;
	}
}
