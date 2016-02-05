#include "Project.h"

#include <sstream>
#include <vector>

using namespace std;

bool readLine(string & line, Project & subject);
void segment(istringstream & line, Project & subject);
void rectangle(istringstream & line, Project & subject);
void pc(istringstream & line, Project & subject);
void unit(istringstream & line, Project & subject);
void intersect(istringstream & line, Project & subject);
void hit(istringstream & line, Project & subject);
void move(istringstream & line, Project & subject);
void del(istringstream & line, Project & subject);
void load(istringstream & line, Project & subject);
void save(istringstream & line, Project & subject);

template<typename T>
void loadParam(istringstream & line, vector<T> & param);

int main()
{
	Project p;
	char * buff = new char[256];
	string s;
	do
	{
		if(!cin.getline(buff, 256))
		{
			delete buff;
			return 1;
		}
		else
		{
			s = buff;
		}
	}while(readLine(s, p));
	
	delete buff;

	return 0;
}

bool readLine(string & line, Project & subject)
{
	string command;
	istringstream input(line);
	input >> command;

	if(command.compare("S") == 0)
	{
		segment(input, subject);
	}
	else if(command.compare("R") == 0)
	{
		rectangle(input, subject);
	}
	else if(command.compare("PC") == 0)
	{
		pc(input, subject);
	}
	else if(command.compare("OR") == 0)
	{
		unit(input, subject);
	}
	else if(command.compare("OI") == 0)
	{
		intersect(input, subject);
	}
	else if(command.compare("HIT") == 0)
	{
		hit(input, subject);
	}
	else if(command.compare("DELETE") == 0)
	{
		del(input, subject);
	}
	else if(command.compare("MOVE") == 0)
	{
		move(input, subject);
	}
	else if(command.compare("LIST") == 0)
	{
		cout << subject.ToString();
	}
	else if(command.compare("UNDO") == 0)
	{
		subject.Undo();
	}
	else if(command.compare("REDO") == 0)
	{
		subject.Redo();
	}
	else if(command.compare("LOAD") == 0)
	{
		load(input, subject);
	}
	else if(command.compare("SAVE") == 0)
	{
		save(input, subject);
	}
	else if(command.compare("CLEAR") == 0)
	{
		subject.Clear();
		cout << "OK" << endl;
	}
	else if(command.compare("EXIT") == 0)
	{
		return false;
	}
	else
	{
		cout << "ERR" << endl;
	}

	return true;
}

void segment(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<int> param;
	loadParam(line, param);
	if(param.size() != 4)
	{
		cout << "ERR" << endl;
		return;
	}
	else
	{
		subject.AddSegment(name, Point(param[0], param[1]), Point(param[2], param[3]));
		cout << "OK" << endl;
	}
}

void rectangle(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<int> param;
	loadParam(line, param);
	if(param.size() != 4)
	{
		cout << "ERR" << endl;
		return;
	}
	else
	{
		subject.AddRectangle(name, Point(param[0], param[1]), Point(param[2], param[3]));
		cout << "OK" << endl;
	}
}

void pc(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<int> param;
	loadParam(line, param);
	if(param.size() % 2 != 0)
	{
		cout << "ERR" << endl;
		return;
	}
	else
	{
		Point points[param.size()/2];
		for(int i(0); i<param.size()/2; i+=2)
		{
			points[i] = Point(param[i], param[i+1]);
		}
		try
		{
			subject.AddConvexPolygon(name, points, param.size()/2);
			cout << "OK" << endl;
		}
		catch(string & e)
		{
			cout << e << endl;
		}
	}
}

void unit(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<string> param;
	loadParam(line, param);
	
	subject.Unit(name, &param[0], param.size());
	cout << "OK" << endl;
	
}

void intersect(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<string> param;
	loadParam(line, param);
	
	subject.Intersect(name, &param[0], param.size());
	cout << "OK" << endl;
	
}

void hit(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<int> param;
	loadParam(line, param);
	if(param.size() != 2)
	{
		cout << "ERR" << endl;
		return;
	}
	else
	{
		if(subject.Hit(name, Point(param[0], param[1])))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

void move(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}

	vector<int> param;
	loadParam(line, param);
	if(param.size() != 2)
	{
		cout << "ERR" << endl;
		return;
	}
	else
	{
		subject.Move(name, Offset(param[0], param[1]));
		cout << "OK" << endl;
	}
}

void del(istringstream & line, Project & subject)
{
	vector<string> param;
	loadParam(line, param);
	
	if(param.size() == 0)
	{
		cout << "ERR" << endl;
		return;
	}
	subject.Delete(&param[0], param.size());
}

void load(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}
	subject.Load(name.c_str());
	cout << "OK" << endl;
}

void save(istringstream & line, Project & subject)
{
	string name;
	if(!line.eof())
	{
		line >> name;
	}
	else
	{	
		cout << "ERR" << endl;
		return;
	}
	subject.Save(name.c_str());
	cout << "OK" << endl;
}

template<typename T>
void loadParam(istringstream & line, vector<T> & param)
{
	while(!line.eof())
	{
		T buffer;
		line >> buffer;
		param.push_back(buffer);
	}
}


