//---------------------------PROJECT-------------------------------------

// General
// On parlera ici indifferement de pile undo/redo,
// de undo/redo ou d'historique (pour le undo), malgre le
// fait qu'il s'agisse de deque.
// L'acces au bas de la structure n'est la que pour eviter un overflow avec une pile infinie
// et ces structures se comportent ici comme des piles.
// Undo/Redo fait en revanche reference aux methodes publiques de meme nom

#ifndef PROJECT_H
#define PROJECT_H

//------------------------------------------------------- includes systemes

#include <map>
#include <string>
#include <deque>
#include <stack>

//------------------------------------------------------- includes personnels

#include "Form.h"
#include "GenericFct.h"

//------------------------------------------------------- classe

using namespace std;

class GenericFct;

class Project
{
	public :

//------------------------------------------------------- classes amies

		friend class GenericFct;
		friend class AddFct;
		friend class DeleteFct;
		friend class MoveFct;		
		friend class ClearFct;
		friend class LoadFct;
		// Foncteurs effectuant les actions de Project a sa place
		// auto-inverseur et pouvant etre stockes directement dans les historique
		// sans edition

//------------------------------------------------------- methodes publiques

		void AddSegment(const string & name, const Point & begin, const Point & end);
		void AddRectangle(const string & name, const Point & leftUp, const Point & rightBottom);
		void AddConvexPolygon(const string & name, const Point * listPoint, int length);
		void Unit(const string & name, const string * forms, int length);
		void Intersect(const string & name, const string * forms, int length);
		// Mode d'emploi 
		// ajoute la forme demandee a la figure
		// et met a jour l'historique avec l'inverse de l'action effectuee (DeleteFct)

		bool Hit(const string & name, const Point & testPoint) const;
		// Mode d'emploi 
		// Appelle la methode Hit de la Form demandee et renvoie le resultat
		
		string ToString() const;
		// Mode d'emploi 
		// renvoie une chaine decrivant l'ensemble des Form
		
		void Save(const char * fileName) const;
		// Mode d'emploi
		// cree un fichier fileName et sauvegarde 
		// la figure dedans
		
		void Move(const string & name, const Offset & delta);
		// Mode d'emploi 
		// deplace la forme demandee
		// et met a jour l'historique avec l'inverse de l'action effectuee (Move(name, -delta))

		void Delete(const string * name, int length);
		// Mode d'emploi
		// supprime la forme demandee
		// et met a jour l'historique avec l'inverse de l'action effectuee (AddFct(formesupprimee))
		// Attention : affiche "OK" si l'action a ete effectuee ou "ERR" sinon
		
		void Undo();
		// Mode d'emploi
		// effectue l'inverse de la derniere action effectuee
		// et place l'action de base (l'inverse de l'inverse) dans
		// la pile redo
		
		void Redo();	
		// Mode d'emploi 
		// annule la derniere action undo

		
		void Load(const char * fileName);
		// Mode d'emploi Load
		// charge une figure depuis fileName
		// n'efface pas les Form deja presentes avant de charger les nouvelles
		// et met a jour l'historique avec l'inverse de l'action effectuee (ClearFct)
		
		void Clear();	
		// Mode d'emploi 
		// efface completement la figure
		// et met a jour l'historique avec l'inverse de l'action effectuee (LoadFct(sauvegardeAutomatique))

//------------------------------------------------------- constructeurs/destructeurs

		Project();
		virtual ~Project();

	private :

//------------------------------------------------------- attributs prives

		map<string, Form*> figure;
		deque< stack<GenericFct *> > undoHisto;
		deque< stack<GenericFct *> > redoHisto;
		
		bool bypassHisto;
		// booleen accessible depuis les classes amies pour effectuer des actions
		// irreversibles (sans possibilite de undo)

//------------------------------------------------------- methodes privees

		void topToUndo(GenericFct * fct, bool fromRedo = false, bool add = false);
		// Mode d'emploi 
		// ajoute une fonction a la pile undo,
		// sur un nouvel etage(add = false)
		// ou en parallele si les actions sont "simultanees"
		// efface totalement la pile rredo sauf si cette methode est appelee depuis Redo()
		
		void topToRedo(GenericFct * fct, bool add = false);
		// Mode d'emploi 
		// ajoute une fonction a la pile redo,
		// sur un nouvel etage(add = false)
		// ou en parallele si les actions sont "simultanees"
	
};

#endif // PROJECT_H
