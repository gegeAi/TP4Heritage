//---------------------------SEGMENT-------------------------------------

#ifndef SEGMENT_H
#define SEGMENT_H

//------------------------------------------------------- includes personnels

#include "Form.h"

//------------------------------------------------------- classe

using namespace std;

class Segment : public Form
{
	public :

//------------------------------------------------------- methodes heritees de Form

		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);

		virtual string ToString() const;
		// Mode d'emploi
		// renvoie l'image de l'objet sous la forme
		// SEGMENT name (begin.x;begin.y) (end.x;end.y)
		
		virtual string ToSerialString() const;

		virtual Form* Clone() const;

//------------------------------------------------------- constructeurs/destructeur

		Segment(const string & name, const Point & argBegin, const Point & argEnd);
		virtual ~Segment();

	private :

//------------------------------------------------------- attributs prives

		Point begin;
		Point end;
};

#endif // SEGMENT_H
