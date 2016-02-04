#include "Project.h"

#include "Union.h"
#include "Intersection.h"
#include "ConvexPolygon.h"
#include "Rectangle.h"
#include "Segment.h"
#include "AddFct.h"
#include "DeleteFct.h"
#include "MoveFct.h"

void Project::AddSegment(const string & name, const Point & begin, const Point & end)
{
	AddFct add(new Segment(name, begin, end));
	GenericFct * reverse = add(*this);
	topToUndo(reverse);
}

void Project::AddRectangle(const string & name, const Point & leftUp, const Point & rightBottom)
{
	AddFct add(new Rectangle(name, leftUp, rightBottom));
	GenericFct * reverse = add(*this);
}

void Project::AddConvexPolygon(const string & name, const Point * listPoint, int length)
{
	AddFct add(new ConvexPolygon(name, listPoint, length));
	GenericFct * reverse = add(*this);
	topToUndo(reverse);
}

void Project::Unit(const string & name, const string * forms, int length)
{
	Union *tps = new Union(name);
	for(int i(0); i<length; i++)
	{
		*tps += figure[forms[i]];
	}
	AddFct add(tps);
	GenericFct * reverse = add(*this);
	topToUndo(reverse);

}

void Project::intersect(const string & name, const string * forms, int length)
{
	Intersection *tps = new Intersection(name);
	for(int i(0); i<length; i++)
	{
		*tps += figure[forms[i]];
	}
	AddFct add(tps);
	GenericFct * reverse = add(*this);
	topToUndo(reverse);

}

bool Project::Hit(const string & name, const Point & testPoint) const
{
	return figure.at(name)->Hit(testPoint);
}

void Project::Move(const string & name, const Offset & delta)
{
	MoveFct move(name, delta);
	GenericFct * reverse = move(*this);
	topToUndo(reverse);
}

void Project::Delete(const string & name)
{
	DeleteFct del(figure[name]);
	GenericFct * reverse = del(*this);
	topToUndo(reverse);
}

string Project::toString() const
{
	string display;
	for(map<string, Form*>::const_iterator it(figure.begin()); it != figure.end(); it++)
	{
		display += it->second->toString();
		display += "\n";
	}

	display.erase(display.size()-1);
}

void Project::Undo()
{
	GenericFct * action(undoHisto.back());
	topToRedo((*action)(*this));
}

void Project::Redo()
{
	GenericFct * action(redoHisto.back());
	topToUndo((*action)(*this), true);
}

Project::Project() : figure(), undoHisto(), redoHisto() 
{
#ifdef MAP
	cout << "Call to <Project> constructor" << endl;
#endif
}

Project::~Project() 
{
#ifdef MAP
	cout << "Call to <Project> destructor" << endl;
#endif

	for(map<string, Form*>::iterator it(figure.begin()); it != figure.end(); it++)
	{
		delete it->second;
	}
}

void Project::topToUndo(GenericFct * fct, bool fromRedo)
{
	if(undoHisto.size() >= 20)
	{
		delete undoHisto.front();
		undoHisto.pop_front();
	}
	undoHisto.push_back(fct);

	if(!fromRedo)
	{
		for(int i(0); i<redoHisto.size(); i++)
		{
			delete redoHisto[i];
		}
		redoHisto.clear();
	}
}

void Project::topToRedo(GenericFct * fct)
{
	if(redoHisto.size() >= 20)
	{
		delete redoHisto.front();
		redoHisto.pop_front();
	}
	redoHisto.push_back(fct);
}

