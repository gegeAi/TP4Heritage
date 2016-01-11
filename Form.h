#ifndef FORM_H
#define FORM_H

class Form : public Serializable
{
	public :

		virtual bool Hit() const;
		virtual void Move();

		Form();
		virtual ~Form();

		ComplexForm operator+(const Form & second) const;
		Form operator*(const Form & second) const;

	private :

		virtual string ToSerializableString() const;
		virtual void LoadOperation(const ifstream & file);
};

#endif // FORM_H
