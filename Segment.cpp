#include "Segment.h"

virtual bool Segment::Hit(const Point & testPoint) const
{
	double coef = (end.y-begin.y) / (end.x - begin.x);
	double constant = begin.y - coef*begin.x;

	return (coef*testPoint.x + constant) == testPoint.y;
}

virtual void Segment::Move(const Offset & delta)
{
	begin.x += delta.x;
	end.x += delta.x;
	begin.y += delta.y;
	end.y += delta.y;
}

Segment::Segment(const string & name, const Point & begin, const Point & end) : Form(name), 
this->begin(begin), this->end(end)
{
#ifdef MAP
	cout << "Call to <Segment> constructor" << endl;
#endif
}

// todo check si il faut mettre : ~Form()

virtual Segment::~Segment()
{
#ifdef MAP
	cout << "Call to <Segment> constructor" << endl;
#endif
}

