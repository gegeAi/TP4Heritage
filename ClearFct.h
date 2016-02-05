#ifndef CLEAR_FCT_H
#define CLEAR_FCT_H

#include "GenericFct.h"
#include "Point.h"

using namespace std;

class ClearFct : public GenericFct
{
	public :
	
	friend class LoadFct;

	virtual GenericFct * operator()(Project & project);

	ClearFct(); 
	virtual ~ClearFct();

	private :
	
	static unsigned char numberCleared;
};

#endif // CLEAR_FCT_H
