#include "Segment.h"
#include <vector>

using namespace std;

int main()
{
	vector<Form *> tab;
	tab.push_back(new Segment("firstSeg", Point(3,4), Point(8,9)));

	cout << *tab[0] << endl;
	
	tab[0]->Move(Offset(-3,-4));

	cout << *tab[0] << endl;

	if(tab[0]->Hit(Point(0,0)))
	{
		cout << "HIT !" << endl;
	}
	delete tab[0];
}
