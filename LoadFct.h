#ifndef LOAD_FCT_H
#define LOAD_FCT_H

#include "GenericFct.h"
#include "Point.h"

using namespace std;

class LoadFct : public GenericFct
{
	public :
	
	virtual GenericFct * operator()(Project & project);

	LoadFct(const char * argFileName, bool deleteOnDeath = false); 
	virtual ~LoadFct();

	private :

	const char * fileName;	
	bool del;
	
};

#endif // LOAD_FCT_H