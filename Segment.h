#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"

class Segment : public Form
{
	public :

		Segment(const Point & begin, const Point & end);
		Segment(int xBegin, int yBegin, int xEnd, int yEnd);
		virtual ~Segment();

	private :

		Point begin;
		Point end;

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // SEGMENT_H
