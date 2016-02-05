#ifndef SEGMENT_H
#define SEGMENT_H

#include "Form.h"

using namespace std;

class Segment : public Form
{
	public :

		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);

		virtual string toString() const;
		virtual string toSerialString() const;

		virtual Form* clone() const;

		Segment(const string & name, const Point & argBegin, const Point & argEnd);
		virtual ~Segment();

	protected :

		Point begin;
		Point end;
};

#endif // SEGMENT_H
