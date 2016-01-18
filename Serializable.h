#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>

class Serializable
{
	public :
		
		void Save(const string & fileName) const;

		static Form * Load(const string & fileName);

		virtual string ToSerializableString() = 0 const;

		virtual void LoadOperation(const string & line)= 0;

		Serializable();
		virtual ~Serializable();

	protected :

		static Form * createFromStr(const string & type);

};

#endif // SERIALIZABLE_H
