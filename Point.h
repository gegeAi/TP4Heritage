#ifndef POINT_H
#define POINT_H

typedef struct Point Point;
typedef struct Point Offset;
typedef struct Point Vect;
struct Point
{
	Point operator+(const Point & p2) const;
	void operator+=(const Point & p2);
	void operator-=(const Point & p2);

	Point(int x, int y);
	Point();
	virtual ~Point();
	
	int x;
	int y;
};

#endif // POINT_H
