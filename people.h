#include <iostream>
#include <string>

using namespace std;
static int personID = 0;

class people
{
	string name, surname, email;
	int age;

public:
	people();
	people(string name, string surname, string email, int age);
	~people();
	string returnPerson();
	string getName();
	void setName(string);
	void setSurname(string);
	void setEmail(string);
	void setAge(int);
};
