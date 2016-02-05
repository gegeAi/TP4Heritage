#include "Segment.h"
#include <sstream>

using namespace std;

bool Segment::Hit(const Point & testPoint) const
// Algorithme :
// calcule l'equation de la droite, et verifie si
// le point appartient a la partie de la droite
// correspondant au segment
{
	double coef = (end.y-begin.y) / (end.x - begin.x);
	double constant = begin.y - coef*begin.x;

	return (coef*testPoint.x + constant) == testPoint.y && begin.x <= testPoint.x && end.x >= testPoint.x;
}

void Segment::Move(const Offset & delta)
{
	begin += delta;
	end += delta;
}

string Segment::ToString() const
{
	ostringstream stream;
	stream << "SEGMENT " << name << " (" << begin.x << ";" << begin.y << ") (" << end.x << ";" << end.y << ")";
	return stream.str();
}

string Segment::ToSerialString() const
{
	ostringstream toSave;
	toSave << "S " << name << " " << begin.x << " " << begin.y << " " << end.x + " " << end.y;
	return toSave.str();
}

Form* Segment::Clone() const
{
	return new Segment(*this);
}

Segment::Segment(const string & name, const Point & argBegin, const Point & argEnd) : Form(name), 
begin(argBegin), end(argEnd)
{
#ifdef MAP
	cout << "Call to <Segment> constructor" << endl;
#endif
}

Segment::~Segment()
{
#ifdef MAP
	cout << "Call to <Segment> destructor" << endl;
#endif
}

