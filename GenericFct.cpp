#include "GenericFct.h"

GenericFct::GenericFct()
{
#ifdef MAP
	cout << "Call to <GenericFct> constructor" << endl;
#endif
}

GenericFct::~GenericFct()
{
#ifdef MAP
	cout << "Call to <GenericFct> destructor" << endl;
#endif
}
