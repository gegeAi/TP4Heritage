#ifndef UNION_H
#define UNION_H

#include <vector>
#include "ComplexForm.h"

using namespace std;

class Union : public ComplexForm
{
	public :
		
		virtual bool Hit(const Point & testPoint) const;

		virtual string toString() const;
		virtual string toSerialString() const;	

		virtual Form* clone() const;	

		Union(const string & argName);
		virtual ~Union();

};

#endif // UNION_H
