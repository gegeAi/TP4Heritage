#include "LoadFct.h"

#include <cstdio>
#include <fstream>

#include "Project.h"
#include "ClearFct.h"

bool readLine(string & line, Project & subject);

GenericFct * LoadFct::operator()(Project & project)
{
	ifstream file(fileName);
	
	char * buff = new char[256];
	while(file.getline(buff, 256))
	{
		string s;
		s += buff;
		readLine(s, project);
	}
	delete buff;
	return new ClearFct();
}

LoadFct::LoadFct(const char * argFileName, bool deleteOnDeath) : GenericFct(), fileName(argFileName), del(deleteOnDeath)
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
		remove(fileName);
		ClearFct::numberCleared--;
	}
}
