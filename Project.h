#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <string>
#include <deque>

#include "Form.h"
#include "AddFct.h"
#include "DeleteFct.h"
#include "MoveFct.h"

using namespace std;

class GenericFct;

class Project
{
	public :

		friend class GenericFct;
		friend class AddFct;
		friend class DeleteFct;
		friend class MoveFct;		

		void AddSegment(const string & name, const Point & begin, const Point & end);
		void AddRectangle(const string & name, const Point & leftUp, const Point & rightBottom);
		void AddConvexPolygon(const string & name, const Point * listPoint, int length);

		void Unit(const string & name, const string * forms, int length);
		void intersect(const string & name, const string * forms, int length);

		bool Hit(const string & name, const Point & testPoint) const;

		void Move(const string & name, const Offset & delta);

		void Delete(const string & name);

		string toString() const;

		void Undo();
		void Redo();		

		Project();
		virtual ~Project();

	private :

		map<string, Form*> figure;
		deque<GenericFct *> undoHisto;
		deque<GenericFct *> redoHisto;

		void topToUndo(GenericFct * fct, bool fromRedo = false);
		void topToRedo(GenericFct * fct);
	
};

#endif // PROJECT_H
