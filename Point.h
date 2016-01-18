#ifndef POINT_H
#define POINT_H

typedef struct Point Point;
typedef struct Point Offset;
struct Point
{
	Point(int x, int y) {this->x = x; this->y = y;}
	
	int x;
	int y;
};

#endif // POINT_H
