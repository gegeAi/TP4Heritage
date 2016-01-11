#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

class ConvexPolygon : public Form
{
	public :

		ConvexPolygon(const Point * pointList);
		ConvexPolygon(const int * xList, const int * yList);
		virtual ~ConvexPolygon();

	private :

		Point * pointList;

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // CONVEX_POLYGON_H
