#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
static int fileCount = 0, citizenCount = 0;


//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------CLASSES---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------


// ------------------------------------------FILE HAND-----------------


class FileHand
{
	friend class Person;
public:
	void WritingPerson(string Fname, string Lname, string email, string Cnum, int ID);
	void WritingCitizen(string Fname, string Lname, string Cnum, string email, char pass[100], string cnic, string bloodType, string city, string state, string address, string dob, int age, bool eligibilityCheck);

};


// ------------------------------------------PERSON-----------------------------------------


class Person
{
protected:
	string firstName, lastName, email, contactNumber;
	int ID;
	void Setter_Person();
public:
	Person();
};


//-------------------------------------------SUPER ADMIN-------------------------------------


class SuperAdmin : public Person
{
public:
	void CRUD_Menu();
};


//------------------------------------------------ADMIN------------------------------------


class Admin : public Person
{

};


//-------------------------------------------Government Official-------------------------------


class GovernmentOfficial : public VaccinationCentres, public Warehouses
{
public:
	float PercentageTotalvaccinated;
	float PerPartiallyVaccinated, PerFullyVaccinated, PerBoosterVaccinated;
	int AmountSpentTotal;
	int vacUsed_perType[6];
	//Member Functions
	void DisplayGraph();
	void CalculateData();
};


//-------------------------------------------MANUFACTURER-----------------------------------


class Manufacturer : public Person
{

};


//----------------------------------------------SUPPLIER---------------------------------


class Supplier : public Person
{

};


//-------------------------------------------VENDOR------------------------------------


class Vendor : public Person
{

};


//-------------------------------------------CITIZEN---------------------------------


class Citizen : public Person
{
protected:
	int systolic_Pressure, dystolic_Pressure, o_Level, g_Level, allergy, age;
	string fName, lName, number, cnic, eMail, bloodType, city, state, address, dob;
	char pass[100];
	bool eligibilityCheck;
public:
	void SignUp_Citizen();
};


//-------------------------------------------MD Doctor---------------------------------


class MD_Doctor :public Person, public Citizen
{
public:

	MD_Doctor();
	void Setter_MDdoctor();
	void Getter_MDdoctor();

};


// ------------------------------------------Vaccines------------------------------------


class Vaccines : public Supplier
{
protected:
	string vacType, vacName;
	int vacID, NumberOfDoses, price, BatchID, BatchVacID;
public:
	void setVacData();
};


// ------------------------------------------Warehouse Centres----------------------------


class Warehouses : public Vaccines
{
protected:
	string name;
	float longi, latti;
	int capacity;
public:
	void WareSet();
};


// ------------------------------------------Vaccination Centres----------------------------


class VaccinationCentres : public Vaccines , public Warehouses
{
protected:
	int VaccineID, SupplierID;
	int day, month, year;
	string Company, City;
	int amount, quantity, population, numberOfcenters;
public:
	void setBatchData();
};


//------------------------------------------------FDO-------------------------------------


class FDO : public Person, public Citizen, public MD_Doctor
{
protected:
	int *Counters;
public:
	void Setter_FDO();
	bool check_Eligibility();
};


//------------------------------------------DOCTOR--------------------------------------------------


class Doctor : public Citizen, public Person
{
protected:
	int Duty_days;
public:
	void Setter_doctor();
};


//------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------IMPLEMENTATIONS-------------------------------------------------
//------------------------------------------------------------------------------------------------------------------



//------------------------------------------FILE HAND-------------------------------------


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


//------------------------------------------------------PERSON------------------------------------------------


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


//------------------------------------------------------MD Doctor--------------------------------------------------


MD_Doctor::MD_Doctor()
{
	Person::Setter_Person();
}


void MD_Doctor::Setter_MDdoctor()
{
	cout << "Check the blood Pressure\n";
	cout << "1st tell the systolic Pressure: ";
	cin >> systolic_Pressure;
	cout << "And tell the dystolic pressure: ";
	cin >> dystolic_Pressure;
	cout << "Check the Glucose level: ";
	cin >> g_Level;
	cout << "Check the o_Level: ";
	cin >> o_Level;
}


void MD_Doctor::Getter_MDdoctor()
{
	cout << "Blood Pressure(Systolic pressure): " << systolic_Pressure << endl;
	cout << "Blood Pressure(Dystolic Pressure): " << dystolic_Pressure << endl;
	cout << "Glucose Level: " << g_Level << endl;
	cout << "Oxygen Level: " << o_Level << endl;
}


//-------------------------------------------------DOCTOR-------------------------------------------------


void Doctor::Setter_doctor() 
{

}


//--------------------------------------------------FDO-----------------------------------------------------


void FDO::Setter_FDO()
{
	Person::Setter_Person();
	int num, CounterNum = 0;
	cout << "Enter the number of counters : ";
	cin >> num;
	Counters = new int[num];
	cout << "Enter number of poeple on all counters : ";
	int smallest = 0;
	for (int i = 0; i < num; ++i)
	{
		cout << "For counter " << i + 1 << " : \n";
		cin >> Counters[i];
		while (Counters[i] < 0)
		{
			cout << "Invalid number : \nEnter again : ";
			cin >> Counters[i];
		}
		if (Counters[i] < smallest)
		{
			smallest = Counters[i];
			CounterNum = i + 1;
		}
	}
	cout << "Patient please go to the counter number : " << CounterNum << " ,because it has least number of people i.e : " << smallest << " \n";
}


bool FDO::check_Eligibility()
{
	int check_Eligibility = 0;
	Getter_MDdoctor();
	cout << "Now check the eligibility for the patient that he or she will be able for vaccine or not\n";
	if (MD_Doctor::systolic_Pressure < 120 && MD_Doctor::dystolic_Pressure < 80)
	{
		cout << "Normal blood pressure\n";
	}
	else
	{
		cout << "Not normal blood pressure\n";
		check_Eligibility = check_Eligibility + 1;
	}
	if (MD_Doctor::g_Level < 140)
	{
		cout << "Normal glucose level\n";
	}
	else
	{
		cout << "Not nornmal glucose level\n";
		check_Eligibility = check_Eligibility + 1;
	}
	if (75 < MD_Doctor::o_Level < 100)
	{
		cout << "Normal oxygen level\n";
	}
	else
	{
		cout << "Not normal oxygen level\n";
		check_Eligibility = check_Eligibility + 1;
	}

	if (check_Eligibility > 0)
	{
		cout << "You are not able for vaccine\n";
		return false;
	}
	else
	{
		cout << "You are able for vaccine\n";
		return true;
	}

}


//-------------------------------------------------Government Officials--------------------------------------------
 


void GovernmentOfficial::CalculateData()
{
	PercentageTotalvaccinated = PerBoosterVaccinated + PerFullyVaccinated + PerPartiallyVaccinated;
	//Aur bhi kuch karna hai is me but idea nhi hai kya karna
}


void GovernmentOfficial::DisplayGraph()
{
	cout << "\n\n\t\tDisplaying graph : \n\n";
	//Ek pyara sa Graph display karna hai is me
}


//-------------------------------------------------Vaccines--------------------------------------------


void Vaccines::setVacData()
{
	char x;
	cout << "\t\tFor vaccine type\nPress 1 for WHOLE VIRUS\n2 For PROTEIN SUBUNIT\n3 for VIRAL VECTOR\n4 for NUCLEIC ACID : \n";
	cin >> x;
	while (x != '1' && x != '2' && x != '3' && x != '4')
	{
		cout << "Wrong input !,Input again : ";
		cin >> x;
	}
	if (x == '1')
	{
		vacType = "WHOLE VIRUS";
	}
	else if (x == '2')
	{
		vacType = "PROTEIN SUBUNIT";
	}
	else if (x == '3')
	{
		vacType = "VIRAL VECTOR";
	}
	else if (x == '4')
	{
		vacType = "NUCLEIC ACID";
	}
	cout << "\t\tFor vaccine Name\nPress 1 for Pfizer\n2 For Moderna\n3 for Sinopharm\n4 for Sinovac\n5 for Sputnik\n6 for Astrazeneca : \n(NOTE : All vacines have two doses)\n;";
	cin >> x;
	while (x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != '6')
	{
		cout << "Wrong input !,Input again : ";
		cin >> x;
	}
	if (x == '1')
	{
		vacName = "Pfizer-BioNTech";
	}
	else if (x == '2')
	{
		vacName = "Moderna";
	}
	else if (x == '3')
	{
		vacName = "Sinopharm";
	}
	else if (x == '4')
	{
		vacName = "SinoVac";
	}
	else if (x == '5')
	{
		vacName = "Sputnik";
	}
	else if (x == '6')
	{
		vacName = "Astrazeneca";
	}
	NumberOfDoses = 2;
	srand(time(NULL));
	vacID = rand() % 9000 + 1000;
	cout << "A four digit vacID is randomly generated\n";
	cout << "Enter its price : ";
	cin >> price;
	srand(time(NULL));
	BatchID = rand() % 9000 + 1000;
	cout << "A four digit BatchID is randomly generated\n";
}


//------------------------------------------------Vaccination Centres----------------------------------------


void VaccinationCentres::setBatchData()
{
	srand(time(NULL));
	VaccineID = rand() % 9000 + 1000;
	cout << "A four digit VaccineID is randomly generated\n";
	cout << "Enter Supplier ID : ";
	cin >> SupplierID;
	//Condition
	{
		//yahan id ko file me paray huye suppliers ki ids se compare karen ge
		//aur invalid par dobara input len ge
	}
	cout << "Enter the Expiry date : \n";
	cout << "Day : ";
	cin >> day;
	cout << "Month : ";
	cin >> month;
	cout << "Year : ";
	cin >> year;
	cout << "Enter the company name : ";
	cin >> Company;
	cout << "Enter city name : ";
	cin >> City;
	cout << "Enter amount spent on vaccines : ";
	cin >> amount;
	cout << "Enter the quantity of vaccines : ";
	cin >> quantity;
	cout << "Enter Population of the city : ";
	cin >> population;
	while (population >= 0)
	{
		cout << "Invalid information\nInput Again : ";
		cin >> population;
	}
	int temp = population;
	while (temp > 20000)
	{
		temp -= 20000;
		numberOfcenters++;
	}
	numberOfcenters++;
	cout << "Number of centres is automatically calculated on the base of population within the city\n";
}


//-----------------------------------------------------WAREHOUSES------------------------------------------------


void Warehouses::WareSet()
{
	cout << "Enter name of Warehouse : ";
	cin >> name;
	cout << "Enter location : \t";
	cout << "lattitude : ";
	cin >> latti;
	cout << "longitude : ";
	cin >> longi;
	cout << "Enter capacity of warehouse : ";
	cin >> capacity;
}


//-----------------------------------------------------CITIZEN--------------------------------------------------


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


// ---------------------------------------------SUPER ADMIN------------------------------------------


void SuperAdmin::CRUD_Menu()
{
	int choice;
	cout << "\t\tCRUD MENU\nPress 1 to create : \nPress 2 to retrieve : \nPress 3 to update : \nPress 4 to Delete : \n";
	cin >> choice;
	while (choice > 4 || choice < 1)
	{
		cout << "Invalid Input!\nEnter again : ";
		cin >> choice;
	}
	switch (choice)
	{
	case 1: // Create
	{
		system("cls");
		cout << "Press 1 to add Admin : \nPress 2 to add Doctor : \nPress 3 to add Front Desk Officer : \nPress 4 to add Government Official : \nPress 5 to add Citizen : \n";
		cin >> choice;
		while (choice > 5 || choice < 1)
		{
			cout << "Invalid Input!\nEnter again : ";
			cin >> choice;
		}
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
	}
}



//------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MAIN/DRIVER-----------------------------------------------------
//------------------------------------------------------------------------------------------------------------------



int main()
{
	//Start kese karna hai isko??
}
