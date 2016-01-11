#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <memory>
#include <string>

class Project : public Serializable
{
	public :
		
		void AddSegment(const string & name, const Point & begin, const Point & end);
		void AddRectangle(const string & name, const Point & leftUp, const Point & rightBottom);
		void AddConvexPolygon(const string & name, const Point * listPoint);

		void Unit(const string & name, const string * forms);
		void intersect(const string & name, const string * forms);

		bool Hit(const string & name, const Point & testPoint) const;

		void Move(const string & name, const Offset & delta);

		void Delete(const string & name);

		string toString() const;

		void Undo();
		void Redo();		

		Project();
		virtual ~Project();

	private :

		map<string, shared_ptr<Form> > actualFigure;
		map<string, shared_ptr<Form> > ** historic;

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
		
}

#endif // PROJECT_H