#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------CLASSES-----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------PERSON----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Person
{
	friend class FileHandling;
protected:
	string firstName, lastName, email, contactNumber;
	int ID;
public:
	virtual void Set();
};



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------SUPER_ADMIN-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class SuperAdmin : public Person
{
	friend class FileHandling;
public:
	void Set();
	void CRUD_Menu();
};



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------ADMIN----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Admin : public Person
{
	friend class FileHandling;
public:
	void Set();
};






//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------SUPPLIER--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Supplier : public Person
{
	friend class FileHandling;
public:
	void Set();
};



//--------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------MANUFACTURER-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Manufacturer : public Person
{
	friend class FileHandling;
public:
	void Set();
};



//--------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------VENDOR--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Vendor : public Person
{
	friend class FileHandling;
public:
	void Set();
};



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------CITIZEN---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Citizen : public Person
{
	friend class FileHandling;
protected:
	int systolic_Pressure, dystolic_Pressure, o_Level, g_Level, allergy, age;
	string bloodType, city, state, address, dob, CNIC;
	char pass[100];
	bool eligibilityCheck;
	int numberofDosesTaken;
public:
	void SignUp_Citizen();
};



//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MD_DOCTOR---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class MD_Doctor : public Person, virtual public Citizen
{
	friend class FileHandling;
public:
	void Set();
	void SetData();

};



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------VACCINES--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Vaccines : public Supplier
{
	friend class FileHandling;
protected:
	string vacType, vacName;
	int vacID, NumberOfDoses, price, BatchID, BatchVacID;
	int quantity;
public:
	void setVacData();
};



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------WAREHOUSES------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Warehouses : public Supplier
{
	friend class FileHandling;
protected:
	string name;
	float longi, latti;
	char Lon, Lat;
	int capacity;
	int SupplierID;
	Vaccines* VacType;
	int* Vac;
	int num, Total;
public:
	void WareSet();
};



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------VACCINATION_CENTRES---------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class VaccinationCentres : public Vaccines, public Warehouses
{
	friend class FileHandling;
protected:
	int VaccineID;
	int day, month, year;
	string Company, City;
	int amount, quantity, population, numberOfcenters;
public:
	void setBatchData();
};



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------GOVERNMENT_OFFICIAL--------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class GovernmentOfficial : public VaccinationCentres, virtual public Warehouses
{
	friend class FileHandling;
public:
	float PercentageTotalvaccinated;
	float PerPartiallyVaccinated, PerFullyVaccinated, PerBoosterVaccinated;
	int AmountSpentTotal;
	int vacUsed_perType[6];


	void DisplayGraph();
	void CalculateData();
};



//--------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------FDO-----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class FDO : public MD_Doctor
{
	friend class FileHandling;
protected:
	int* Counters;
public:
	void Set();
	bool check_Eligibility();
};



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------DOCTOR---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class Doctor : public Person
{
	friend class FileHandling;
protected:
	int Duty_days;
public:
	void Set();
};



//--------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------FILE_HANDLING----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



class FileHandling
{
	friend class Doctor;
	friend class MD_doctor;
	friend class Vaccines;
	friend class SuperAdmin;
	friend class Admin;
	friend class Manufacturer;
	friend class Supplier;
	friend class Vendor;
	friend class Citizen;
	friend class Warehouses;
	friend class VaccinationCenters;
	friend class GovernmentOfficial;
	friend class FDO;
protected:
	fstream admin, s_Admin, manuFacturer, supplier, vendor, doctor, md_doctor, fDOs, citizen, vaccinesTypes, vaccinationCenteres, govtOfficial, w_houses, vacData;
public:
	FileHandling();
	~FileHandling();
	void StoreDoctor(Doctor&);
	void StoreMD_Doctor(MD_Doctor&);
	void StoreFDO(FDO&);
	void StoreSuperAdmin(SuperAdmin&);
	void StoreAdmin(Admin&);
	void StoreManufacturer(Manufacturer&);
	void StoreVendor(Vendor&);
	void StoreSupplier(Supplier&);
	void StoreCitizen(Citizen&);
	void StoreVaccineData(Vaccines&);
	void StoreVaccinationCentres(VaccinationCentres&);
	void StoreWarehouses(Warehouses&);
	void StoreGovernmentOfficial(GovernmentOfficial&);
};





//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------IMPLEMENTATION-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------PERSON----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Person::Set()
{
	cout << "Enter First Name : ";
	cin >> firstName;
	cout << "Enter last Name : ";
	cin >> lastName;
	cout << "Enter Email id : ";// (without @gmail.com)";
	cin >> email;
	//email += "@gmail.com";
	cout << "Enter Contact Number : ";
	cin >> contactNumber;
	srand(time(NULL));
	ID = rand() % 9000 + 1000;
	cout << "Randmly generated 4 digit ID : " << ID;
}



//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MD_DOCTOR---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void MD_Doctor::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreMD_Doctor(*this);
}



void MD_Doctor::SetData()
{
	cout << "Enter Personal details for MD Doctor : \n";
	cout << "Now, checking the citizen : \n";
	cout << "Check the blood Pressure\n";
	cout << "Systolic Pressure: ";
	cin >> systolic_Pressure;
	cout << "Dystolic pressure: ";
	cin >> dystolic_Pressure;
	cout << "Glucose level: ";
	cin >> g_Level;
	cout << "O_Level: ";
	cin >> o_Level;
}



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------DOCTOR---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Doctor::Set()
{
	cout << "Enter information of Doctor : \n";
	Person::Set();
	cout << "Enter number of duty Days : ";
	cin >> Duty_days;
	FileHandling obj;
	obj.StoreDoctor(*this);
	SuperAdmin S_A;
	S_A.CRUD_Menu();
}



//--------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------FDO-----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void FDO::Set()
{
	cout << "Enter information of FDO : ";
	Person::Set();
	FileHandling obj;
	obj.StoreFDO(*this);
	int num, CounterNum = 1;
	cout << "Enter the number of counters : ";
	cin >> num;
	Counters = new int[num];
	cout << "Enter number of poeple on all counters : ";
	for (int i = 0; i < num; ++i)
	{
		cout << "For counter " << i + 1 << " : \n";
		cin >> Counters[i];
		while (Counters[i] < 0)
		{
			cout << "Invalid number : \nEnter again : ";
			cin >> Counters[i];
		}
	}
	int smallest = Counters[0];
	for (int i = 1; i < num; i++)
	{
		if (Counters[i] < smallest)
		{
			smallest = Counters[i];
			CounterNum = i + 1;
		}
	}
	cout << "Patient please go to the counter number : " << CounterNum << " ,because it has least number of people i.e : " << smallest << " \n";
	SuperAdmin S_A;
	S_A.CRUD_Menu();
}



bool FDO::check_Eligibility()
{
	int check_Eligibility = 0;
	MD_Doctor::Set();
	MD_Doctor::SetData();
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
	if (MD_Doctor::o_Level > 75 && MD_Doctor::o_Level < 100)
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



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------ADMIN----------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Admin::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreAdmin(*this);
	//process
	SuperAdmin S_A;
	S_A.CRUD_Menu();
}



//--------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------MANUFACTURER-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Manufacturer::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreManufacturer(*this);
}



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------SUPPLIER--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Supplier::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreSupplier(*this);
}



//--------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------VENDOR--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Vendor::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreVendor(*this);
}



//--------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------GOVERNMENT_OFFICIAL--------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



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



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------VACCINES--------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



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
	cout << "\t\tFor vaccine Name\nPress 1 for Pfizer\n2 For Moderna\n3 for PakVac\n4 for Sinopharm\n5 for CanSio Bio\n6 for Astrazeneca : \n(NOTE : All vacines have two doses)\n;";
	cin >> x;
	while (x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != '6')
	{
		cout << "Wrong input !,Input again : ";
		cin >> x;
	}
	if (x == '1')
	{
		vacName = "Pfizer-BioNTech";
		NumberOfDoses = 2;
	}
	else if (x == '2')
	{
		vacName = "Moderna";
		NumberOfDoses = 2;
	}
	else if (x == '3')
	{
		vacName = "PakVac";
		NumberOfDoses = 1;
	}
	else if (x == '4')
	{
		vacName = "Sinopharm";
		NumberOfDoses = 2;
	}
	else if (x == '5')
	{
		vacName = "CanSio Bio";
		NumberOfDoses = 1;
	}
	else if (x == '6')
	{
		vacName = "Astrazeneca";
		NumberOfDoses = 2;
	}
	srand(time(NULL));
	vacID = rand() % 9000 + 1000;
	cout << "A four digit vacID is randomly generated\n";
	cout << "Enter its price : ";
	cin >> price;
	srand(time(NULL));
	BatchID = rand() % 9000 + 1000;
	cout << "A four digit BatchID is randomly generated\n";
	FileHandling obj;
	obj.StoreVaccineData(*this);
}



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------VACCINATION_CENTRES---------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void VaccinationCentres::setBatchData()
{
	srand(time(NULL));
	VaccineID = rand() % 9000 + 1000;
	cout << "A four digit VaccineID is randomly generated\n";
	cout << "Enter Supplier ID : (4-Digit ID)";
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



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------WAREHOUSES------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Warehouses::WareSet()
{
	int count;
	cout << "Enter name of Warehouse : ";
	cin >> name;
	cout << "Enter location : \t";
	cout << "lattitude : ";
	cin >> latti;
	cout << "Enter direction : (N,S)";
	cin >> Lat;
	while (Lat != 'N' && Lat != 'S')
	{
		cout << "Invalid Input!\nEnter Again : ";
		cin >> Lat;
	}
	cout << "longitude : ";
	cin >> longi;
	cout << "Enter direction : (E,W)";
	cin >> Lon;
	while (Lon != 'E' && Lon != 'W')
	{
		cout << "Invalid Input!\nEnter Again : ";
		cin >> Lon;
	}
	cout << "Enter capacity of warehouse : ";
	cin >> capacity;
	cout << "Enter the information of Supplier : ";
	Supplier::Set();
	SupplierID = Supplier::ID;
	cout << "How many Vaccines are supplied : \n";
	cin >> num;
	VacType = new Vaccines[num];
	Vac = new int[num];
	cout << "Entering info of all " << num << " vaccines : \n";
	for (int i = 0; i < num; ++i)
	{
		count = i;
		cout << "For Vaccine " << i + 1 << " : \n";
		VacType[i].setVacData();
		cout << "Enter Number of Vaccines of this type : ";
		cin >> Vac[i];
		Total += Vac[i];
		if (Total > capacity)
		{
			cout << "Exceeded the Entered Capacity of WareHouse : \n";
			cout << "The remaining types(if any are set to zero)\n";
			int Temp = Total - capacity;
			Total = Total - Vac[i];
			Vac[i] = Vac[i] - Temp;
			Total = Total + Vac[i];
			if (i != num - 1)
			{
				for (int i = count; i < num; ++i)
				{
					Vac[i] = 0;
				}
			}
			break;
		}
	}
	cout << "Total of " << Total << " vaccines are Supplied To WareHouse\n";

}



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------CITIZEN---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void Citizen::SignUp_Citizen()
{
	cout << "\t\t\tSIGNUP\n";
	cout << "Enter First Name : ";
	cin >> firstName;
	cout << "Enter last Name : ";
	cin >> lastName;
	cout << "Enter your age : ";
	cin >> age;
	cout << "Enter Contact Number : ";
	cin >> contactNumber;
	cout << "Enter Email id : (without @gmail.com)";
	cin >> email;
	email += "@gmail.com";
	cout << "Enter Password : ";
	cin >> pass;
	cout << "Enter Cnic Number: ";
	cin >> CNIC;
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
	cout << "If you are not allergic to to any of vaccine components, press 1 else press 0";
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

	FileHandling obj;
	obj.StoreCitizen(*this);

	cout << "You have successfully signed up";
	if (eligibilityCheck == false)
	{
		cout << "\nBut you are not eligible for vaccination";
	}

}



//--------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------SUPER_ADMIN-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



void SuperAdmin::Set()
{
	Person::Set();
	FileHandling obj;
	obj.StoreSuperAdmin(*this);
}



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
		cout << "Press 1 to add Admin : \nPress 2 to add Doctor : \nPress 3 to add Front Desk Officer : \nPress 4 to add Citizen : \n";
		cin >> choice;
		while (choice > 4 || choice < 1)
		{
			cout << "Invalid Input!\nEnter again : ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1: // Admin
		{
			Admin obj;
			obj.Set();
			break;
		}
		case 2: // Doctor
		{
			Doctor obj;
			obj.Set();
			break;
		}
		case 3: // FDO
		{
			FDO obj;
			obj.Set();
			break;
		}
		case 4: // Citizen
		{
			Citizen obj;
			obj.SignUp_Citizen();
			break;
		}
		}
		break;
	}
	/*	case 2: // Retrieve
		{
			cout << "Press 1 for Admin : \nPress 2 for Doctor : \nPress 3 for Front Desk Officer : \nPress 4 for Citizen : \n";
			cin >> choice;
			while (choice > 4 || choice < 1)
			{
				cout << "Invalid Input!\nEnter again : ";
				cin >> choice;
			}
			switch (choice)
			{
			case 1: // Admin
			{
				Admin obj;
				obj.Set();
				break;
			}
			case 2: // Doctor
			{
				Doctor obj;
				obj.Set();
				break;
			}
			case 3: // FDO
			{
				FDO obj;
				obj.Set();
				break;
			}
			case 4: // Citizen
			{
				Citizen obj;
				obj.Set();
				break;
			}
			break;
		}
		case 3: // Update
		{
			break;
		}
		case 4: // Delete
		{
			break;
		}*/
	}
}



//--------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------FILE_HANDLING----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------




FileHandling::FileHandling()
{
	admin.open("Admins.txt", ios::app);
	s_Admin.open("Super Admin.txt", ios::app);
	manuFacturer.open("Manufacturers.txt", ios::app);
	supplier.open("Suppliers.txt", ios::app);
	vendor.open("Vendors.txt", ios::app);
	doctor.open("Doctor.txt", ios::app);
	md_doctor.open("MD Doctors.txt", ios::app);
	fDOs.open("FDO.txt", ios::app);
	citizen.open("Citizens.txt", ios::app);
	vaccinesTypes.open("Vaccines Types.txt", ios::app);
	vaccinationCenteres.open("Vaccination Centres.txt", ios::app);
	govtOfficial.open("Government Officials.txt", ios::app);
	w_houses.open("WareHouses.txt", ios::app);
	vacData.open("VAccines Data.txt", ios::app);
}



void FileHandling::StoreAdmin(Admin& obj)
{
	static int count = 1;
	admin << "Sr # " << count++ << endl;
	admin << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << endl;
}



void FileHandling::StoreSuperAdmin(SuperAdmin& obj)
{
	static int count = 1;
	s_Admin << "Sr # " << count++ << endl;
	s_Admin << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << endl;
}



void FileHandling::StoreManufacturer(Manufacturer& obj)
{
	static int count = 1;
	manuFacturer << "Sr # " << count++ << endl;
	manuFacturer << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << endl;
}



void FileHandling::StoreVendor(Vendor& obj)
{
	static int count = 1;
	vendor << "Sr # " << count++ << endl;
	vendor << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << endl;
}



void FileHandling::StoreSupplier(Supplier& obj)
{
	static int count = 1;
	supplier << "Sr # " << count++ << endl;
	supplier << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << endl;
}



void FileHandling::StoreDoctor(Doctor& obj)
{
	static int count = 1;
	doctor << "Sr # " << count++ << endl;
	doctor << "First Name : " << obj.firstName << "\nlast Name : " << obj.lastName << "\nEmail id : " << obj.email << "\nContact Number : " << obj.contactNumber << "\nID : " << obj.ID << "Duty Days : " << obj.Duty_days << endl;
}



void FileHandling::StoreFDO(FDO& obj)
{
	static int count = 1;
	fDOs << "Sr # " << count++ << endl;
	fDOs << "First Name : " << obj.Person::firstName << "\nlast Name : " << obj.Person::lastName << "\nEmail id : " << obj.Person::email << "\nContact Number : " << obj.Person::contactNumber << "\nID : " << obj.Person::ID << endl;
}



void FileHandling::StoreMD_Doctor(MD_Doctor& obj)
{
	static int count = 1;
	md_doctor << "Sr # " << count++ << endl;
	md_doctor << "First Name : " << obj.Person::firstName << "\nlast Name : " << obj.Person::lastName << "\nEmail id : " << obj.Person::email << "\nContact Number : " << obj.Person::contactNumber << "\nID : " << obj.Person::ID << endl;
}



void FileHandling::StoreCitizen(Citizen& obj)
{
	static int count = 1;
	citizen << "\n\nSr # " << count++ << "\nName : " << obj.firstName << " " << obj.lastName << "\nAge : " << obj.age << "\nEmail id : " << obj.email << "\nPassword : " << obj.pass << "\nContact Number : " << obj.contactNumber << "\nCnic : " << obj.ID << "\nBlood Type : " << obj.bloodType << "\nCity : " << obj.city << "\nState : " << obj.state << "\nAddress : " << obj.address << "\nDate of birth : " << obj.dob << "\nEligibility check : " << obj.eligibilityCheck;
	citizen << "\nRecord of Stats : \n";
	citizen << "Blood Pressure : " << obj.systolic_Pressure << " / " << obj.dystolic_Pressure << "\nOxygen Level : " << obj.o_Level << "\nGlucose Level : " << obj.g_Level << endl;
	// encrypting password
	for (int i = 0; (i < 100 && obj.pass[i] != '\0'); i++)
	{
		obj.pass[i] = obj.pass[i] + 2; //the key for encryption is 3 that is added to ASCII value
	}
	//this is how to decrypt it
	for (int i = 0; (i < 100 && obj.pass[i] != '\0'); i++)
	{
		obj.pass[i] = obj.pass[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
	}
}



void FileHandling::StoreVaccineData(Vaccines& obj)
{
	static int count = 1;
	vaccinesTypes << "Sr # " << count++ << endl;
	vaccinesTypes << "Vac Type : " << obj.vacType << "\nVac Name : " << obj.vacName << "\nVac id : " << obj.vacID << "\nNumber of Doses : " << obj.NumberOfDoses << "\nPrice : " << obj.price << "\nBatch ID : " << obj.BatchID << "\nVacBatchID : " << obj.BatchVacID << endl;
}



void FileHandling::StoreVaccinationCentres(VaccinationCentres& obj)
{
	static int count = 1;
	vaccinationCenteres << "Sr # " << count++ << endl;

}



void FileHandling::StoreWarehouses(Warehouses& obj)
{
	static int count = 1;
	w_houses << "Sr # " << count++ << endl;
	w_houses << "Name of WareHouse : " << obj.name << "\nLocation : " << obj.latti << " degree " << obj.Lat << "and " << obj.longi << " degree " << obj.Lon << endl;
	w_houses << "Capacity : " << obj.capacity << "\nSupplier ID : " << obj.SupplierID << "\n";
	for (int i = 0; i < obj.num; i++)
	{
		w_houses << "Vaccine " << i + 1 << " : ";
		w_houses << "Vaccine Name : " << obj.VacType[i].vacName << "\nQuantity : " << obj.Vac[i] << endl;
	}
	w_houses << "Total Vaccines in WareHouse : " << obj.Total << endl;
}



void FileHandling::StoreGovernmentOfficial(GovernmentOfficial& obj)
{
	static int count = 1;
	govtOfficial << "Sr # " << count++ << endl;
	govtOfficial << "Percentage of vaccinated people : " << obj.PercentageTotalvaccinated;
	govtOfficial << "\nPercentage of partially vaccinated people : " << obj.PerPartiallyVaccinated;
	govtOfficial << "\nPercentage of fully vaccinated people : " << obj.PerFullyVaccinated;
	govtOfficial << "\nPercentage of vaccinated people with booster dose : " << obj.PerBoosterVaccinated;
	govtOfficial << "\nTotal amount spend till now on vaccines : " << obj.AmountSpentTotal;
	govtOfficial << "Vaccines used per type : " << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << "For type " << i + 1 << " ( ";
		if (i == 0)
		{
			govtOfficial << "Pfizer-BioNTech ) : ";
		}
		else if (i == 1)
		{
			govtOfficial << "Moderna ) : ";
		}
		else if (i == 2)
		{
			govtOfficial << "PakVac ) : ";
		}
		else if (i == 3)
		{
			govtOfficial << "Sinopharm ) : ";
		}
		else if (i == 4)
		{
			govtOfficial << "CanSio Bio ) : ";
		}
		else if (i == 5)
		{
			govtOfficial << "Astrazeneca ) : ";
		}
		govtOfficial << obj.vacUsed_perType[i] << endl;
	}
}



FileHandling::~FileHandling()
{
	admin.close();
	s_Admin.close();
	manuFacturer.close();
	supplier.close();
	vendor.close();
	doctor.close();
	md_doctor.close();
	fDOs.close();
	citizen.close();
	vaccinesTypes.close();
	vaccinationCenteres.close();
	govtOfficial.close();
	w_houses.close();
	vacData.close();
}


//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------MAIN / DRIVER-----------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------



int main()
{
	SuperAdmin S_A;
	cout << "Enter the information of Super Admin : \n";
	S_A.Set();
	cout << "\nDisplaying the CRUD Menu : \n";
	S_A.CRUD_Menu();
	system("pause");
}
