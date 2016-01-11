#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle : public Form
{
	public :

		Rectanle(const Point & begin, const Point & end);
		Rectangle(int xBegin, int yBegin, int xEnd, int yEnd);
		virtual ~Rectangle();

	private :

		Point leftUp;
		Point rightBottom;

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // RECTANGLE_H
