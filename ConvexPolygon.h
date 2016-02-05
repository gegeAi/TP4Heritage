//---------------------------CONVEX_POLYGON-------------------------------------

#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

//------------------------------------------------------- includes personnels

#include "Form.h"

//------------------------------------------------------- classe

using namespace std;

class ConvexPolygon : public Form
{
	public :

//------------------------------------------------------- methodes heritees de Form
	
		virtual bool Hit(const Point & testPoint) const;
		virtual void Move(const Offset & delta);	

		virtual string ToString() const; 
		// Mode d'emploi
		// renvoie l'image de l'objet sous la forme
		// CONVEXPOLYGON name (pointList[0].x;pointList[0].y) .. (pointList[n].x;pointList[n].y)
		
		virtual string ToSerialString() const;	

		virtual Form* Clone() const;
	
//------------------------------------------------------- constructeurs/destructeur
		
		ConvexPolygon(const string & argName, const Point * argPointList, int argSize);
		ConvexPolygon(const ConvexPolygon & second); 
		virtual ~ConvexPolygon();

	private :

//------------------------------------------------------- attributs prives

		Point * pointList;
		int size;

//------------------------------------------------------- methodes privees
		
		int testForLine(const Point & p1,const Point & p2, const Point & testPoint) const; 
		// Mode d'emploi 
		// renvoie une valeur dont le signe change de le cote
		// duquel testPoint se trouve de la droite
		// representee par (p1, p2)
		
		bool isConvex() const;
		// Mode d'emploi 
		// Verifier si le polygone est convexe
		
		void copyPoint(const Point * argPointList);
		// Mode d'emploi :
		// copie argPointList dans pointList
		

};

#endif // CONVEX_POLYGON_H
