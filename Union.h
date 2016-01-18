#ifndef UNION_H
#define UNION_H

#include <vector>

class Union : public Form
{
	public :

		Union();
		virtual ~Union();

	private :

		vector<Form> objects;

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // UNION_H
