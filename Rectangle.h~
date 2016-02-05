#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Form.h"

using namespace std;

class Rectangle : public Form
{
	public :
		
		
		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);

		virtual string toString() const;

		virtual Form* clone() const;
		
		Rectangle(const string & argName, const Point & argUpLeft, const Point & argBottomRight);
		virtual ~Rectangle();

	private :

		Point upLeft;
		Point bottomRight;

};

#endif // RECTANGLE_H
