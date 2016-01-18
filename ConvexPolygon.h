#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

class ConvexPolygon : public SimpleForm
{
	public :

		ConvexPolygon(const Point * pointList);
		ConvexPolygon(const int * xList, const int * yList);
		virtual ~ConvexPolygon();

	private :

		Point * pointList;

};

#endif // CONVEX_POLYGON_H
