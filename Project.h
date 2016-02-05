#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <string>
#include <deque>
#include <stack>

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
		friend class ClearFct;

		void AddSegment(const string & name, const Point & begin, const Point & end);
		void AddRectangle(const string & name, const Point & leftUp, const Point & rightBottom);
		void AddConvexPolygon(const string & name, const Point * listPoint, int length);

		void Unit(const string & name, const string * forms, int length);
		void Intersect(const string & name, const string * forms, int length);

		bool Hit(const string & name, const Point & testPoint) const;

		void Move(const string & name, const Offset & delta);

		void Delete(const string * name, int length);

		string ToString() const;

		void Undo();
		void Redo();	

		void Save(const char * fileName) const;
		void Load(const char * fileName);
		void Clear();	

		Project();
		virtual ~Project();

	private :

		map<string, Form*> figure;
		deque< stack<GenericFct *> > undoHisto;
		deque< stack<GenericFct *> > redoHisto;

		void topToUndo(GenericFct * fct, bool fromRedo = false, bool add = false);
		void topToRedo(GenericFct * fct, bool add = false);
	
};

#endif // PROJECT_H
