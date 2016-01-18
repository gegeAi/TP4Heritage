#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public SimpleForm
{
	public :
		
		
		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);
		
		Rectangle(const Point & upLeft, const Point & bottomRight);
		virtual ~Rectangle();

	private :

		Point upLeft;
		Point bottomRight;

};

#endif // RECTANGLE_H
