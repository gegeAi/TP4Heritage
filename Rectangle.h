#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public SimpleForm
{
	public :
s
		Rectangle(const Point & begin, const Point & end);
		Rectangle(int xBegin, int yBegin, int xEnd, int yEnd);
		virtual ~Rectangle();

	private :

		Point leftUp;
		Point rightBottom;

};

#endif // RECTANGLE_H
