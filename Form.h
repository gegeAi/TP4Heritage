//---------------------------FORM-------------------------------------

#ifndef FORM_H
#define FORM_H

//------------------------------------------------------- includes systemes

#include <iostream>

//------------------------------------------------------- includes personnels

#include "Point.h"

//------------------------------------------------------- classe

using namespace std;

class Form
{
	public :

//------------------------------------------------------- classes amies

		friend class ComplexForm;

//------------------------------------------------------- methodes publiques

		virtual bool Hit(const Point & testPoint) const = 0 ;
		// Mode d'emploi :
		// teste si testPoint appartient a la forme
		// entree :
		// 	- testPoint le point a tester
		// sortie :
		// 	- true si testPoint appartient a la forme, false sinon
		
		virtual void Move(const Offset & delta) = 0;
		// Mode d'emploi :
		// deplace la forme de l'offset souhaite
		// entree :
		//	- delta la distance de deplacement souhaitee
		
		virtual string ToString() const = 0; 
		
		virtual string ToSerialString() const = 0;
		// Mode d'emploi :
		// genere la ou les commandes permettant de recreer la forme
		// sortie :
		//	- une suite de commande sous forme de string

		virtual Form* Clone() const = 0;
		// Mode d'emploi :
		// renvoie une copie de l'objet, necessaire 
		// pour copier par polymorphisme

		string getName() const;
		void correctSameName();

//------------------------------------------------------- constructeurs/destructeur

		Form(const string & argName);
		virtual ~Form();

	protected :

//------------------------------------------------------- attributs protected

		string name;
};

//------------------------------------------------------- surcharge d'operateurs

ostream & operator<<(ostream & out, const Form & obj);

#endif // FORM_H
