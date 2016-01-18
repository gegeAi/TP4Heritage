#include "Segment.h"
#include "Rectangle.h"
#include "ConvexPolygon.h"
#include <vector> 

using namespace std;

int main()
{
	vector<Form *> tab;
	tab.push_back(new Segment("firstSeg", Point(3,4), Point(8,9)));

	cout << *tab[0] << endl;

	Point * list = new Point[4];
	list[0] = Point(0, 0);
	list[1] = Point(0, 4);
	list[2] = Point(4,4);
	list[3] = Point(1,3);

	try
	{
		tab.push_back(new ConvexPolygon("Poly", list, 4));
	}
	catch(string & e)
	{
		cout << e << endl;
	}
	
	tab[0]->Move(Offset(-3,-4));

	cout << *tab[0] << endl;

	if(tab[0]->Hit(Point(0, 1)))
	{
		cout << "HIT !" << endl;
	}

	tab.push_back(new Rectangle("Rect", Point(0,0), Point(10,10)));

	cout << *tab[1] << endl;

	tab[1]->Move(Offset(-2,2));
	if(tab[1]->Hit(Point(-4, -4)))
	{
		cout << "HIT !" << endl;
		cout << *tab[1] << endl;
	}

	if(tab.size() > 2)
	{
		cout << *tab[2] << endl;
		cout << "t1" << endl;
		tab[2]->Move(Offset(0, 0));
		cout << "t2" << endl;
		if(tab[2]->Hit(Point(25, 25)))
		{
			cout << "HIT !" << endl;
			cout << *tab[2] << endl;
		}
		delete tab[2];
	}

	delete tab[0];
	delete[] list;
	delete tab[1];
}
