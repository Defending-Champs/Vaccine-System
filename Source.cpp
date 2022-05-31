#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
static int fileCount;
class FileHand
{
	friend class Person;
public:
	void WritingPerson(string Fname, string Lname, string email, string Cnum, int ID);

};

void FileHand::WritingPerson(string Fname, string Lname, string email, string Cnum, int ID)
{
	fstream MyFile("Person_info.txt");
	fileCount++;

	MyFile << "\n\nRecord # " << fileCount << "\nName : " << Fname << " " << Lname << "\nEmail id : " << email << "\nContact Number : " << Cnum << "ID : " << ID;

	MyFile.close();
}


// -------------------------------next class-----------------------------------------(ignore)
class Person
{
protected:
	string firstName, lastName, email, contactNumber;
	int ID;
	void Setter_Person();
public:
	Person();
};

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


// -------------------------------next class-----------------------------------------(ignore)
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
					//is ma kuch is tarhan ka krna hy ky  WritingPerson() ky function sy hi Admin ki aledha class banay 
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


// -------------------------------next class-----------------------------------------(ignore)
class Admin : public Person
{

};
class Doctor : public Person
{

};
class FDO : public Person
{

};
class GovernmentOfficial : public Person
{

};
class Citizen : public Person
{

};
int main()
{
	// Baraye meharbani project shuru kr lain 
	//aur ma kal test deny nahi ja raha(siraf project ki waja sy) to suba 8 bjy google classroom py project shru krna hy.(pooch nahi raha bata raha hun)
}
