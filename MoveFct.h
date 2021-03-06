#ifndef MOVE_FCT_H
#define MOVE_FCT_H

#include "GenericFct.h"
#include "Point.h"

using namespace std;

class MoveFct : public GenericFct
{
	public :
	
	virtual GenericFct * operator()(Project & project);

	MoveFct(const string & argNname, const Offset & argDelta); 
	virtual ~MoveFct();

	private :

	Offset delta;
	string subjectName;	
	
};

#endif // MOVE_FCT_H
