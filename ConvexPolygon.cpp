#include "ConvexPolygon.h"
#include <sstream>

using namespace std;

bool ConvexPolygon::Hit(const Point & testPoint) const
{
	for(int i(0); i<size; i++)
	{
		if(!testForLine(pointList[i], pointList[(i+1)%size], testPoint))
		{
			return false;
		}
	}

	return true;
}
void ConvexPolygon::Move(const Offset & delta)	
{
	for(int i(0); i<size; i++)
	{
		pointList[i] += delta;
	}
}

string ConvexPolygon::toString() const 	
{
	ostringstream stream;
	stream << "CONVEXPOLYGON " << name;

	for(int i(0); i<size; i++)
	{
		stream << " (" << pointList[i].x << ";" << pointList[i].y << ")";
	}

	return stream.str();
}

bool ConvexPolygon::isConvex() const
{
	Vect start1(pointList[size-1]);
	start1 -= pointList[0];

	Vect start2(pointList[1]);
	start2 -= pointList[0];
	
	double firstProd = start1.x*start2.y - start1.y*start2.x;

	for(int i(1); i<size; i++)
	{
		Vect vect1(pointList[i-1]);
		vect1 -= pointList[i];

		Vect vect2(pointList[i+1]);
		vect2 -= pointList[i];

		double prod = vect1.x*vect2.y - vect1.y*vect2.x;

		if(prod*firstProd < 0)
		{
			return false;
		}
	}

	return true;
}
		
ConvexPolygon::ConvexPolygon(const string & argName, const Point * argPointList, int argSize) : 
Form(argName), size(argSize)
{
#ifdef MAP
	cout << "Call to <ConvexPolygon> constructor" << endl;
#endif
	pointList = new Point[size];
	for(int i(0); i<size; i++)
	{
		pointList[i] = argPointList[i];
	}
	
	Point tpsPoint;
	tpsPoint = pointList[0] + pointList[2];
	insidePointX = tpsPoint.x / 2.f;
	insidePointY = tpsPoint.y / 2.f;
}

ConvexPolygon::ConvexPolygon(const ConvexPolygon & second) : Form(second), size(second.size),
insidePointX(second.insidePointX), insidePointY(second.insidePointY)
{
#ifdef MAP
	cout << "Call to <ConvexPolygon> copy constructor" << endl;
#endif

	pointList = new Point[size];
	for(int i(0); i<size; i++)
	{
		pointList[i] = second.pointList[i];
	}

	if(!isConvex())
	{
		string e = "ERR";
		e += "\r\n";
		e += "#Non convex Polygon";
		throw e;
	}

}

ConvexPolygon::~ConvexPolygon()
{
#ifdef MAP
	cout << "Call to <ConvexPolygon> destructor" << endl;
#endif

	delete[] pointList;
}

bool ConvexPolygon::testForLine(const Point & p1,const Point & p2, const Point & testPoint) const
{
	double coef = (p2.y-p1.y) / (p2.x - p1.x);
	double constant = p1.y - coef*p1.x;

	double referenceResult = coef*insidePointX - insidePointY + constant;
	double testResult = coef*testPoint.x - testPoint.y + constant;

	return testResult*referenceResult > 0;
}
