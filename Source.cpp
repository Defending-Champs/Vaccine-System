#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
static int fileCount, citizenCount;

// ------------------------------------------FILE HAND-----------------
class FileHand
{
	friend class Person;
public:
	void WritingPerson(string Fname, string Lname, string email, string Cnum, int ID);
	void WritingCitizen(string Fname, string Lname, string Cnum, string email, char pass[100], string cnic, string bloodType, string city, string state, string address, string dob, int age, bool eligibilityCheck);
	
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

// ------------------------------------------SUPER ADMIN-----------------
class SuperAdmin : public Person
{
public:
	void CRUD_Menu();
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
protected:
	int b_Pressure, o_Level, g_level, age, allergy;
	string fName, lName, number, cnic, eMail, bloodType, city, state, address, dob;
	char pass[100];
	bool eligibilityCheck;
public:
	void SignUp_Citizen();
};

//------------------------------------------FILE HAND-----------------
void FileHand::WritingPerson(string Fname, string Lname, string email, string Cnum, int ID)
{
	fstream MyFile("Person_info.txt");
	fileCount++;

	MyFile << "\n\nRecord # " << fileCount << "\nName : " << Fname << " " << Lname << "\nEmail id : " << email << "\nContact Number : " << Cnum << "\nID : " << ID;

	MyFile.close();
}
void FileHand::WritingCitizen(string Fname, string Lname, string Cnum, string email, char pass[100], string cnic, string bloodType, string city, string state, string address, string dob, int age, bool eligibilityCheck)
{
	fstream MyFile("Citizen_info.txt");
	citizenCount++;
	// encrypting password
	for (int i = 0; (i < 100 && pass[i] != '\0'); i++)
	{
		pass[i] = pass[i] + 2; //the key for encryption is 3 that is added to ASCII value
	}

	// this is how to decrypt it
	//for (int i = 0; (i < 100 && pass[i] != '\0'); i++)
	//{
	//	pass[i] = pass[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
	//}

	MyFile << "\n\nRecord # " << citizenCount << "\nName : " << Fname << " " << Lname << "\nAge : " << age << "\nEmail id : " << email << "\nPassword : " << pass << "\nContact Number : " << Cnum << "\nCnic : " << cnic << "\nBlood Type : " << bloodType << "\nCity : " << city << "\nState : " << state << "\nAddress : " << address << "\nDate of birth : " << dob << "\nEligibility check : " << eligibilityCheck;

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

// ------------------------------------------CITIZEN-----------------
void Citizen::SignUp_Citizen()
{
	cout << "\t\t\tSIGNUP\n";
	cout << "Enter First Name : ";
	cin >> fName;
	cout << "Enter last Name : ";
	cin >> lName;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter Contact Number : ";
	cin >> number;
	cout << "Enter Email id : ";
	cin >> eMail;
	cout << "Enter Password : ";
	cin >> pass;
	cout << "Enter Cnic Number: ";
	cin >> cnic;
	cout << "Enter Blood type : ";
	cin >> bloodType;
	cout << "Enter City : ";
	cin >> city;
	cout << "Enter State : ";
	cin >> state;
	cout << "Enter Address : ";
	cin >> address;
	cout << "Enter Date of Birth : ";
	cin >> dob;
	cout << "These are the components of vaccine if you are not allergic to any of these press 1 else press 0";
	cin >> allergy;
	if (allergy == 1)
	{
		eligibilityCheck = true;
		if (age >= 5)
		{
			eligibilityCheck = true;
		}
		else
		{
			eligibilityCheck = false;
		}
	}
	else
	{
		eligibilityCheck = false;
	}
	
	FileHand obj;
	obj.WritingCitizen(fName, lName, number, eMail, pass, cnic, bloodType, city, state, address, dob, age, eligibilityCheck);

	cout << "You have successfully signed up";
	if (eligibilityCheck == false)
	{
		cout << "\nBut you are not eligible for vaccination";
	}
}


int main()
{
	
}
