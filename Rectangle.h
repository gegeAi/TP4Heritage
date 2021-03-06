//---------------------------RECTANGLE-------------------------------------

#ifndef RECTANGLE_H
#define RECTANGLE_H

//------------------------------------------------------- includes personnels

#include "Form.h"

//------------------------------------------------------- classe

using namespace std;

class Rectangle : public Form
{
	public :
		
//------------------------------------------------------- methodes heritees de Form
		
		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);

		virtual string ToString() const;
		// Mode d'emploi :
		// renvoie l'image de l'objet sous la forme
		// RECTANGLE name (upLeft.x;upLeft.y) (bottomRight.x;bottomRight.y)
		
		virtual string ToSerialString() const;

		virtual Form* Clone() const;
	
//------------------------------------------------------- constructeurs/destructeurs
		
		Rectangle(const string & argName, const Point & argUpLeft, const Point & argBottomRight);
		virtual ~Rectangle();

	private :

//------------------------------------------------------- attributs prives

		Point upLeft;
		Point bottomRight;

};

#endif // RECTANGLE_H
