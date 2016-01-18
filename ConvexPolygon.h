#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

#include "Form.h"

using namespace std;

class ConvexPolygon : public Form
{
	public :
		
		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);	

		virtual string toString() const; 	
		
		ConvexPolygon(const string & argName, const Point * argPointList, int argSize);
		ConvexPolygon(const ConvexPolygon & second); 
		virtual ~ConvexPolygon();

	protected :

		Point * pointList;
		int size;

		int insidePointX;
		int insidePointY;
		
		bool testForLine(const Point & p1,const Point & p2, const Point & testPoint) const; 
		bool isConvex() const;
		

};

#endif // CONVEX_POLYGON_H
