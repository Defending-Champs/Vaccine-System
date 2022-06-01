#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
static int fileCount;

// ------------------------------------------FILE HAND-----------------
class FileHand
{
	friend class Person;
public:
	void WritingPerson(string Fname, string Lname, string email, string Cnum, int ID);

};

// ------------------------------------------PERSON-----------------
class Person
{
protected:
	string firstName, lastName, email, contactNumber;
	int ID;
	void Setter_Person();
public:
	Person();
};

// ------------------------------------------ADMIN-----------------
class Admin : public Person
{

};

// ------------------------------------------DOCTOR-----------------
class Doctor : public Person
{

};

// ------------------------------------------FDO-----------------
class FDO : public Person
{

};

// ------------------------------------------Government Official-----------------
class GovernmentOfficial : public Person
{

};

// ------------------------------------------CITIZEN-----------------
class Citizen : public Person
{

};

//------------------------------------------FILE HAND-----------------
void FileHand::WritingPerson(string Fname, string Lname, string email, string Cnum, int ID)
{
	fstream MyFile("Person_info.txt");
	fileCount++;

	MyFile << "\n\nRecord # " << fileCount << "\nName : " << Fname << " " << Lname << "\nEmail id : " << email << "\nContact Number : " << Cnum << "ID : " << ID;

	MyFile.close();
}


// ------------------------------------------PERSON-----------------
Person::Person()
{
	ID = NULL;
}
void Person::Setter_Person()
{
	cout << "Enter First Name : ";
	cin >> firstName;
	cout << "Enter last Name : ";
	cin >> lastName;
	cout << "Enter Email id : ";
	cin >> email;
	cout << "Enter Contact Number : ";
	cin >> contactNumber;
	srand(time(NULL));
	ID = rand() % 9000 + 1000;
	FileHand obj;
	obj.WritingPerson(firstName, lastName, email, contactNumber, ID);
}


// ------------------------------------------SUPER ADMIN-----------------
class SuperAdmin : public Person
{
public:
	void CRUD_Menu();
};

void SuperAdmin::CRUD_Menu()
{
	int choice;
	cout << "\t\tCRUD MENU\nPress 1 to create : \nPress 2 to retrieve : \nPress 3 to update : \nPress 4 to Delete : \n";
	cin >> choice;
	switch (choice)
	{
		case 1: // Create
		{
			system("cls");
			cout << "Press 1 to add Admin : \nPress 2 to add Doctor : \nPress 3 to add Front Desk Officer : \nPress 4 to add Government Official : \nPress 5 to add Citizen : \n";
			cin >> choice;
			switch (choice)
			{
				case 1: // Admin
				{
					//is ma kuch is tarhan ka krna hy ky  WritingPerson() ky function sy hi Admin ki aledha file banay 
					break;
				}
				case 2: // Doctor
				{
					// aisy hi bakio ka
					break;
				}
				case 3: // FDO
				{
					break;
				}
				case 4: // Government official
				{
					break;
				}
				case 5: // Citizen
				{
					break;
				}
				default:
				{
					cout << "Wrong INPUT"; // Change the sentence if you want to, @AffanBukhari--
					break;
				}
			}
			break;
		}
		case 2: // Retrieve
		{
			break;
		}
		case 3: // Update
		{
			break;
		}
		case 4: // Delete
		{
			break;
		}
		default: 
		{
			cout << "Wrong INPUT"; // Change the sentence if you want to, @AffanBukhari--
		}
	}
}


// ------------------------------------------NEXT-----------------

int main()
{
	
}
