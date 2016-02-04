#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include "ComplexForm.h"

using namespace std;

class Intersection : public ComplexForm
{
	public :
		
		virtual bool Hit(const Point & testPoint) const;

		virtual string toString() const;		

		Intersection(const string & argName);
		virtual ~Intersection();

};

#endif // INTERSECTION_H
