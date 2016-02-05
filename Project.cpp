#include "Project.h"

//------------------------------------------------------- includes systemes

#include <fstream>

//------------------------------------------------------- includes personnels

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

//------------------------------------------------------- Fonctions de creation

// Algorithme
// creation de l'objet desire
// creation du foncteur AddFct add correspondant
// Appel a add(*this) pour effectuer effectivement l'ajout
// recuperation de l'inverse (DeleteFct) et stockage dans l'historique 

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
	topToUndo(reverse);
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

//------------------------------------------------------- Fonctions de passives (sans modifications)

bool Project::Hit(const string & name, const Point & testPoint) const
{
	return figure.at(name)->Hit(testPoint);
}

string Project::ToString() const
{
	string display;
	for(map<string, Form*>::const_iterator it(figure.begin()); it != figure.end(); it++)
	{
		display += it->second->ToString();
		display += "\r\n";
	}

	return display;
}

void Project::Save(const char * fileName) const
{
	ofstream file(fileName, ios::trunc);
	if(file)
	{
		for(map<string, Form*>::const_iterator it(figure.begin()); it != figure.end(); it++)
		{
			file << it->second->ToSerialString() << endl;
		}
	}
	file.close();
}

//------------------------------------------------------- Deplacement

void Project::Move(const string & name, const Offset & delta)
{
	MoveFct move(name, delta);
	GenericFct * reverse = move(*this);
	topToUndo(reverse);
}

//------------------------------------------------------- Suppression

void Project::Delete(const string * name, int length)
// Algorithme
// si une forme n'existe pas
// return
// sinon
// cree une DeleteFct par Form a supprimer
// et les supprime une a une
// Ajoute des inverses (AddFct) en parrallele a l'historique
{
	for(int i(0); i<length; i++)
	{
		if(figure.find(name[i]) == figure.end())
		{
			cout << "ERR" << endl;
			return;		
		} // if find name
	} // for
	DeleteFct del(figure[name[0]]);
	GenericFct * reverse = del(*this);
	topToUndo(reverse);
	for(int i(1); i<length; i++)
	{
		DeleteFct del(figure[name[i]]);
		GenericFct * reverse = del(*this);
		topToUndo(reverse, false, true);
	} // for
	cout << "OK" << endl;
}

//------------------------------------------------------- Undo/Redo

// Algorithme
// sort chaque action parrallele du sommet la pile associee
// et les effectue une a une
// remet ensuite leurs inverses dans la l'autre pile en parrallele 
// supprime le sommet de la pile associee

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

//----------------------------------------------------------------

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

Project::Project() : figure(), undoHisto(), redoHisto(), bypassHisto(false)
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
// Algorithme
// Si l'historique est plein
// on supprime l'element le plus ancien
// Si l'ajout est en parrallele, on ajoute au meme etage
// sinon on cree un nouvel etage et on l'ajoute au nouveau
// Si l'appel ne vient pas de Redo, on vide la pile redo
{
	if(!bypassHisto)
	{
		if(undoHisto.size() >= 20)
		{
			while(!undoHisto.front().empty())
			{
				delete undoHisto.front().top();
				undoHisto.front().pop();
			} // while
			undoHisto.pop_front();
		} // if >= 20
		if(add)
		{
			undoHisto.front().push(fct);
		}
		else
		{
			stack<GenericFct *> tps;
			tps.push(fct);
			undoHisto.push_back(tps);
		} // if add

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
		} // if fromRedo
	} // if bypass
}

void Project::topToRedo(GenericFct * fct, bool add)
// Algorithme
// Si redo est plein
// on supprime l'element le plus ancien
// Si l'ajout est en parrallele, on ajoute au meme etage
// sinon on cree un nouvel etage et on l'ajoute au nouveau
{
	if(!bypassHisto)
	{
		if(redoHisto.size() >= 20)
		{
			while(!redoHisto.front().empty())
			{
				delete redoHisto.front().top();
				redoHisto.front().pop();
			} // while
			redoHisto.pop_front();
		} // if >= 20
		if(add)
		{
			redoHisto.front().push(fct);
		}
		else
		{
			stack<GenericFct *> tps;
			tps.push(fct);
			redoHisto.push_back(tps);
		} // if add
	} // if bypass
}

