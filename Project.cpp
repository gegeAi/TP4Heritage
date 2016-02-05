#include "Project.h"

#include <fstream>

#include "Union.h"
#include "Intersection.h"
#include "ConvexPolygon.h"
#include "Rectangle.h"
#include "Segment.h"
#include "AddFct.h"
#include "DeleteFct.h"
#include "MoveFct.h"
#include "LoadFct.h"
#include "ClearFct.h"

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

void Project::Intersect(const string & name, const string * forms, int length)
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

void Project::Delete(const string * name, int length)
{
	for(int i(0); i<length; i++)
	{
		if(figure.find(name[i]) == figure.end())
		{
			cout << "ERR" << endl;
			return;		
		}
	}
	DeleteFct del(figure[name[0]]);
	GenericFct * reverse = del(*this);
	topToUndo(reverse);
	for(int i(1); i<length; i++)
	{
		DeleteFct del(figure[name[i]]);
		GenericFct * reverse = del(*this);
		topToUndo(reverse, false, true);
	}
	cout << "OK" << endl;
}

string Project::ToString() const
{
	string display;
	for(map<string, Form*>::const_iterator it(figure.begin()); it != figure.end(); it++)
	{
		display += it->second->toString();
		display += "\r\n";
	}

	return display;
}

void Project::Undo()
{
	GenericFct * action(undoHisto.back().top());
	undoHisto.back().pop();
	topToRedo((*action)(*this));
	delete action;
	while(!undoHisto.back().empty())
	{
		GenericFct * action(undoHisto.back().top());
		undoHisto.back().pop();
		topToRedo((*action)(*this), true);
		delete action;
	}
}

void Project::Redo()
{
	GenericFct * action(redoHisto.back().top());
	redoHisto.back().pop();
	topToRedo((*action)(*this));
	delete action;
	while(!redoHisto.back().empty())
	{
		GenericFct * action(redoHisto.back().top());
		redoHisto.back().pop();
		topToUndo((*action)(*this), false, true);
		delete action;
	}
}

void Project::Save(const char * fileName) const
{
	ofstream file(fileName);
	if(file)
	{
		for(map<string, Form*>::const_iterator it(figure.begin()); it != figure.end(); it++)
		{
			file << it->second->toSerialString() << endl;
		}
	}
	file.close();
}

void Project::Load(const char * fileName)
{
	LoadFct load(fileName);
	topToUndo(load(*this));
}

void Project::Clear()
{
	ClearFct clear;
	topToUndo(clear(*this));
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

void Project::topToUndo(GenericFct * fct, bool fromRedo, bool add)
{
	if(undoHisto.size() >= 20)
	{
		while(!undoHisto.front().empty())
		{
			delete undoHisto.front().top();
			undoHisto.front().pop();
		}
		undoHisto.pop_front();
	}
	if(add)
	{
		undoHisto.front().push(fct);
	}
	else
	{
		stack<GenericFct *> tps;
		tps.push(fct);
		undoHisto.push_back(tps);
	}

	if(!fromRedo)
	{
		for(int i(0); i<redoHisto.size(); i++)
		{
			while(!redoHisto[i].empty())
			{
				delete redoHisto[i].top();
				redoHisto[i].pop();
			}
		}
		redoHisto.clear();
	}
}

void Project::topToRedo(GenericFct * fct, bool add)
{
	if(redoHisto.size() >= 20)
	{
		while(!redoHisto.front().empty())
		{
			delete redoHisto.front().top();
			redoHisto.front().pop();
		}
		redoHisto.pop_front();
	}
	if(add)
	{
		redoHisto.front().push(fct);
	}
	else
	{
		stack<GenericFct *> tps;
		tps.push(fct);
		redoHisto.push_back(tps);
	}
}

