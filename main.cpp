object-programming.cpp
#include "people.h"
#include <fstream>
#include <conio.h>
#include <stdlib.h>

static int persons = -1;
people personDB[20];

void forceEnter();
void addPerson();
void addSingleToFile();
void saveDBtoFile();
void loadDBfromFile();
void showFileDB();
void lookForDB();
void removeFromDBarr();

int main()
{
	

	char choice;
	do 
	{
		cout << "----------Database simple menu v1.0----------" << endl;
		cout << "| 1. Add person to DB array                  |" << endl;
		cout << "| 2. Print DB array                          |" << endl;
		cout << "| 3. Save single person to file DB.          |" << endl;
		cout << "| 4. Load persons from file DB to  array DB. |" << endl;
		cout << "| 5. Save persons from array DB to  file DB. |" << endl;
		cout << "| 6. Show persons from file DB.              |" << endl;
		cout << "| 7. Search in DB array.                     |" << endl;
		cout << "| 8. Remove person from DB array.            |" << endl; 
		cout << "-------------press esc to exit--------------" << endl;
		choice = _getch();
		switch(choice)
		{
		case '1':
			system("cls");
			addPerson();
			system("cls");
			cout << "Person succesfully added to DB..." << endl << endl;
			break;
		case '2':
			system("cls");
			if (persons == -1)
				cout << "Database is empty!";
			else
			{
				for (int i = 0; i <= persons; i++)
					cout << i << " " << personDB[i].returnPerson();
			}

			cout << endl << endl;
			break;
		case '3':
			system("cls");
			addSingleToFile();
			system("cls");
			break;
		case '4':
			system("cls");
			loadDBfromFile();
			cout << "DB from file loaded successfully..." << endl << endl;
			break;
		case '5':
			system("cls");
			if(persons==-1)
			{
				cout << " No persons to be saved in the file..." << endl << endl;
			}
			else
			{
				saveDBtoFile();
				cout << "DB saved to file..." << endl << endl;
			}
			break;
		case '6':
			system("cls");
			showFileDB();
			cout << endl << endl;
			break;
		case '7':
			system("cls");
			lookForDB();
			break;
		case '8':
			system("cls");
			removeFromDBarr();
			break;
		case 27:
			break;
		default:
			forceEnter();
			system("cls");
			break;
		}
	}while (choice != 27);

}

void forceEnter()
{
	cout << "I don't get it, try again. Press enter to contiune." << endl;
	while (_getch() != 13);
}

void addPerson()
{
	persons++;
	cout << "Add single person to array start..." << endl;
	string name;
	string surname;
	string mail;
	int age;
	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Mail: ";
	cin >> mail;
	cout << "Age: ";
	cin >> age;
	people person(name, surname, mail, age);
	personDB[persons] = person;
}

void addSingleToFile() 
{
	cout << "Add single person to file start..." << endl;
	string name;
	string surname;
	string mail;
	int age;
	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Mail: ";
	cin >> mail;
	cout << "Age: ";
	cin >> age;
	people person(name, surname, mail, age);
	fstream file;
	file.open("personDB.txt", ios::app);
	if (file.is_open())
	{
		file << person.returnPerson();
	}
	else
		cout << "File wasn't opened correctly...";
}

void saveDBtoFile()
{
	fstream file;
	file.open("personDB.txt", ios::app);
	if (file.is_open())
	{
		for (int i = 0; i <= persons; i++)
				file << personDB[i].returnPerson();
	
		file.close();
	}
	else
		cout << "File wasn't opened correctly..." << endl;
}
void loadDBfromFile()
{
	fstream file;
	file.open("personDB.txt", ios::in);
	if (file.is_open())
	{
		char buffer[100];
		while (file.getline(buffer, 100))
		{

			string wholePersonStr = buffer;

			int valueStart = 0;
			int valueEnd;
			int spaceCounter = 0;

			string tmpName;
			string tmpSurname;
			string tmpEmail;
			int tmpAge;

			for (int i = 0; i < wholePersonStr.length() - 1; i++)
			{

				if (wholePersonStr[i] == ' ')
				{
					spaceCounter++;
					valueEnd = i;

					if (spaceCounter == 1)
					{
						persons++;
						tmpName = wholePersonStr.substr(valueStart, valueEnd); //substr takes part of other str (start,how_much_chars)
						personDB[persons].setName(tmpName);
						valueStart = i + 1;
					}
					if (spaceCounter == 2)
					{ 
						tmpSurname = wholePersonStr.substr(valueStart, (valueEnd - tmpName.length()-1));
						personDB[persons].setSurname(tmpSurname);
						valueStart = i + 1;
					}
					if (spaceCounter == 3)
					{
						tmpEmail = wholePersonStr.substr(valueStart, (valueEnd - tmpName.length() - tmpSurname.length()-2));
						personDB[persons].setEmail(tmpEmail);
						valueStart = i + 1;

						tmpAge = stoi(wholePersonStr.substr(valueStart, (valueEnd - tmpName.length() - tmpSurname.length() - tmpEmail.length()))); //stoi converts numeric str to int
						personDB[persons].setAge(tmpAge);
					}
				}

			}
			
		}
		file.close();
	}
	else
		cout << "File wasn't opened correctly..." << endl;
}

void showFileDB()
{
	fstream file;
	file.open("personDB.txt", ios::in);
	if (file.is_open())
	{
		file.seekg(0, ios::end);
		if (file.tellg() == 0)
			cout << "No persons to be loaded from file..." << endl << endl;
		else
		{
			file.seekg(0, ios::beg);
			char buffer[100] = {0};
			while(file.getline(buffer, 100))
			{	
				cout << buffer << endl;
			}
		}
		file.close();
	}
	else
		cout << "File wasn't opened correctly..." << endl;
}

void lookForDB() 
{
	string name;
	cout << "Provide a name of a person you are looking for: " << endl;
	cin >> name;
	if (persons != -1)
	{
		for (int i = 0; i <= persons; i++)
		{
			if (personDB[i].getName() == name)
				cout << personDB[i].returnPerson();
		}
	}
	else
		cout << "Database array is empty right now..." << endl;
}

void removeFromDBarr()
{
	if (persons != -1)
	{
		int id;
		cout << "Which person would you like to delete?: ";
		cin >> id;
		for (int i = id; i < persons; i++)
		{
			personDB[i] = personDB[i+1];	
		}
		persons--;
		
	}
	else
		cout << "There are no persons in DB array, nothing to remove..." << endl;

}
