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
	
};
class Admin
{

};
class Doctor
{

};
class FDO
{

};
class GovernmentOfficial
{

};
class Citizen
{

};
int main()
{
	
}