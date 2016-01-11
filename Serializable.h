#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>
#include <fstream>

class Serializable
{
	public :
		
		void Save(const string & fileName) const;

		void Load(const string & fileName);

	private :

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // SERIALIZABLE_H
