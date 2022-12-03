#include "people.h"

people::people()
{
	this->name = "John";
	this->surname = "Doe";
	this->email = "john@doe.com";
	this->age = 0;
}

people::people(string name, string surname, string email, int age) 
{
	cout << "Creating person with details..." << endl;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->age = age;
	personID++;
}

people::~people()
{

}

string people::returnPerson()
{
	string tmp;
	tmp = this->name + " " + this->surname + " " + this->email + " " + to_string(this->age) + '\n';
	return tmp;
}

string people::getName()
{
	string name = this->name;
	return name;
}

void people::setName(string name)
{
	this->name = name;
}

void people::setSurname(string surname)
{
	this->surname = surname;
}

void people::setEmail(string email)
{
	this->email = email;
}

void people::setAge(int age)
{
	this->age = age;
}
