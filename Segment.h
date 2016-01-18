#ifndef SEGMENT_H
#define SEGMENT_H

#include "Form.h"

class Segment : public Form
{
	public :

		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);

		Segment(const string & name, const Point & begin, const Point & end);
		virtual ~Segment();

	protected :

		Point begin;
		Point end;
};

#endif // SEGMENT_H
