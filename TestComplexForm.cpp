#include "Intersection.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main()
{
	Intersection test("Test");

	test += new Rectangle("r", Point(0,0), Point(4,4));
	test += new Rectangle("r2", Point(-4,-4), Point(2,2));

	cout << test << endl;

	if(test.Hit(Point(1,1)))
	{
		cout << "HIT !" << endl;
	}

	return 0;
}
