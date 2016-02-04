#ifndef GENERIC_FCT_H
#define GENERIC_FCT_H

#include <string>

using namespace std;

class Project;

class GenericFct
{
	public :

	virtual GenericFct * operator()(Project & project) = 0;

	GenericFct();
	virtual ~GenericFct();

};

#endif // GENERIC_FCT_H
