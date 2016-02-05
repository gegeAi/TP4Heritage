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
		virtual string toSerialString() const;	

		virtual Form* clone() const;
		
		ConvexPolygon(const string & argName, const Point * argPointList, int argSize);
		ConvexPolygon(const ConvexPolygon & second); 
		virtual ~ConvexPolygon();

	protected :

		Point * pointList;
		int size;
		
		int testForLine(const Point & p1,const Point & p2, const Point & testPoint) const; 
		bool isConvex() const;
		void copyPoint(const Point * argPointList);
		

};

#endif // CONVEX_POLYGON_H
