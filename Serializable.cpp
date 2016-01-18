#include <fstream>

#include "Serializable.h"

static Form * Serializable::createFromStr(const string & type)
{
	Form *temp;
	switch(type)
	{
		case "UN":
			temp = new Union();
			break;
		case "IN":
			temp = new Intersection();
			break;
		case "SE":
			temp = new Segment();
			break;
		case "RE":
			temp = new Rectangle();
			break;
		case "PO":
			temp = new ConvexPolygon();
			break;
	}

	return temp;
}

void Serializable::Save(const string & fileName) const
{
	ostream file(fileName, ios::trunc);
	
	if(file)
	{
		file << ToSerializableString();
		file.close();
	}
	else
	{
		cout << "ERR" << endl;
		cout << "#Impossible to open file <" << fileName << ">" << endl;
	}
}

static Form * Serializable::Load(const string & fileName)
{
	istream file(fileName);
	
	if(file)
	{
		string line;
		while(getline(file, line))
		{ 
			LoadOperation();
		}

		file.close();
	}
	else
	{
		cout << "ERR" << endl;
		cout << "#Impossible to open file <" << fileName << ">" << endl;
	}
}

Serializable::Serializable()
{
#ifdef MAP
	cout << "Call to <Serializable> constructor" << endl;
#endif
}

virtual Serializable::~Serializable()
{
#ifdef MAP
	cout << "Call to <Serializable> destructor" << endl;
#endif
}
