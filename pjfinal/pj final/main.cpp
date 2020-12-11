#include <iostream>
#include <string>
#include <sstream>
#include "carPark.h"
#include "carParkSlot.h"
#include "driver.h"
#include "staff.h"
#include "user.h"
using namespace std;
template <typename T>
void add(T* &datas,int numOfData,int &maxOfData) {
	T* ndatas = datas;
	datas = new T[maxOfData + 5];
	for (int i = 0; i < numOfData;i++) {
		datas[i] = ndatas[i];
	}
	maxOfData += 5;
	delete[]ndatas;
}

template <typename T>
bool login(T* storeUserName, string nName, int &storePlace, int numOfAccount)
{
	for (int i = 0; i<numOfAccount; i++)
	{

		if ((nName==storeUserName[i].getUserName())==true) {
			
			storePlace = i;
			return true;
		}
		
	}return false;
}

template <typename T>
int loginPage(T* storeUserName, int &numOfDriver, int &numOfStaff, string role)
{
	string input;
	int storePlace = 0;
	cout << "User Name : ";
	cin >> input;

	if (role == "staff") {
		if (login(storeUserName, input, storePlace, numOfStaff) == true) {
			system("pause");
			return storePlace;
		}
	}
	else
	{
		if (login(storeUserName, input, storePlace, numOfDriver) == true) {
			system("pause");
			return storePlace;
		}
	}
	cout << "No this username." << endl;
	system("pause");
	return -1;
}

int Begining() {
	system("cls");
	int choice;
	do {
		cout << "Car Parking System" << endl;
		cout << "1. For Staff." << endl;
		cout << "2. For Driver." << endl;
		cout << "3. Exit" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice>3);
	return choice;
}

int ForStaff() {
	system("cls");
	int choice;
	do {
		cout << "Car Parking System" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Create a new car park." << endl;
		cout << "2. Edit car park information" << endl;
		cout << "3. Remove a car park" << endl;
		cout << "4. Create a new user account." << endl;
		cout << "5. Edit user account information." << endl;
		cout << "6. Remove a user account." << endl;
		cout << "7. Check car parking slot status." << endl;
		cout << "8. Check car park balance." << endl;
		cout << "9. Logout" << endl << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 9);
	return choice;
}
int ForDriver() {
	system("cls");
	int choice;
	do {
		cout << "Welcome to Car Parking System" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "1. Reserve a parking slot." << endl;
		cout << "2. Check account balance." << endl;
		cout << "3. Increase account balance." << endl;
		cout << "4. Logout" << endl << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 4);
	return choice;
}
bool ExecuteStaffMenu(int choice, int user, driver *&dStore, staff *&sStore, carPark *&cStore, int &numOfCarPark, int &numOfDriver, int &numOfStaff, int day, int month, int year,int &maxOfStaff,int &maxOfCarpark,int &maxOfDriver) {
	string role;
	switch (choice) {
		int cUser;
	case 1:
		sStore[user].newCarPark(cStore, numOfCarPark);	// create new car park(+1)
		if (numOfCarPark == maxOfCarpark)
			add(cStore, numOfCarPark, maxOfCarpark);
		system("pause");
		break;
	case 2:
		sStore[user].editCarParkInformation(cStore[sStore[user].selectcarPark(cStore, numOfCarPark)]);	// edit information
		system("pause");
		break;
	case 3:
		sStore[user].remoCarpark(
			sStore[user].selectcarPark(cStore, numOfCarPark),
			cStore,
			numOfCarPark);// remove car park(-1)
		system("pause");
		break;
	case 4:
		sStore[user].newUserAccount(dStore, sStore, numOfStaff, numOfDriver);// create a new user account
		if (numOfStaff == maxOfStaff)
			add(sStore, numOfStaff, maxOfStaff);
		if(numOfDriver == maxOfDriver)
			add(dStore, numOfDriver, maxOfDriver);
		system("pause");
		break;
	case 5:
		
		cUser = sStore[user].selectaccount(sStore, dStore, numOfDriver, numOfStaff,role); 
		if (cUser != -1) {

			if (role == "staff") {
				sStore[user].editStaffInformation(sStore[cUser]);// edit account information
			}
			else if (role == "driver") {
				sStore[user].editDriverInformation(dStore[cUser]);
			}
			else {
				cout << "No this user name" << endl;
			}
		}
		system("pause");
		break;
	case 6:
		cUser = sStore[user].selectaccount(sStore, dStore, numOfDriver, numOfStaff,role);
		if (cUser != -1) {

			if (role == "staff") {
				sStore[user].remoUser(sStore[cUser], sStore, numOfStaff, numOfDriver, dStore);
			}
			else if (role == "driver") {
				sStore[user].remoUser(dStore[cUser], dStore, numOfDriver, numOfDriver, dStore);
			}
			else {
				cout << "No this user name" << endl;
			}
		}
		system("pause");
		// remove a user account
		break;
	case 7:
		sStore[user].checkCarParkingSlot(cStore, numOfCarPark, day, month, year);// check car parking slot status
		system("pause");
		break;
	case 8:
		sStore[user].CheckCarParkBalance(cStore, numOfCarPark);// check car park balance
		system("pause");
		break;
	case 9:
		return true;
		break;
	}
	return false;

}
bool ExecuteDriverMenu(int choice, int user, int numOfCarPark, driver* dStore, carPark* &cStore, int &day, int &month, int &year, int date[12],int numOfDriver) {
	switch (choice) {
	case 1:
		dStore[user].reserve(cStore, numOfCarPark, day, month, year, date, dStore,numOfDriver);// reserve a parking slot
		system("pause");
		break;
	case 2:
		dStore[user].showAccoutBalance();// check account balance
		system("pause");
		break;
	case 3:
		dStore[user].accoutbalance();// increase account balance
		system("pause");
		break;
	case 4:
		return true;
		break;
	}
	return false;

}
bool ExecuteBegining(int choice, staff* &sStore, driver* &dStore, carPark* &cStore, int &numOfCarPark, int &numOfDriver, int &numOfStaff, int &day,int &month,int &year,int date[12],int &maxOfStaff ,int &maxOfCarpark,int &maxOfDriver) {
	switch (choice) {
		bool staff, driver;
		int user;
		
	case 1:
		user= loginPage(sStore, numOfDriver, numOfStaff, "staff");
		if (user == -1) {
			
		}
		else
			do {
				system("cls");
				staff = ExecuteStaffMenu(ForStaff(), user, dStore, sStore, cStore, numOfCarPark, numOfDriver, numOfStaff, day, month, year, maxOfStaff, maxOfCarpark, maxOfDriver);
			} while (!staff);
		break;
	case 2:
		user = loginPage(dStore, numOfDriver, numOfStaff, "driver");
		if (user == -1) {
			
		}
		else
			do {
				system("cls");
				driver = ExecuteDriverMenu(ForDriver(), user, numOfCarPark, dStore, cStore,day,month,year,date,numOfDriver);
			}while(!driver);
		break;
	case 3:
		return true;
		break;
	}
	return false;
}


int main() {
	int day=1;
	int month = 1;
	int year = 1900;
	int date[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	staff* sStore = new staff[5];
	driver* dStore = new driver[5];
	carPark* cStore = new carPark[5];
	int maxOfStaff=5;
	int maxOfCarpark = 5;
	int maxOfDriver = 5;
	int numOfDriver = 0;
	int numOfStaff = 0;
	int numOfCarPark = 0;
	cStore[0].createCarPark("Happy Parking", "Happy Valley", 56, 0, 25, 28, 28, 6, 30, 20, numOfCarPark);
	cStore[1].createCarPark("Wealthy Parking", "Mong Kok", 9, 0, 30, 36, 32, 1, 5, 3, numOfCarPark);
	cStore[2].createCarPark("Come Parking", "Kowloon Tong", 38, 0, 15, 22, 20, 8, 20, 10, numOfCarPark);
	sStore[0].createStaff("Ken Lee","ken", numOfStaff);
	dStore[0].createDriver("Aaron Chan","aaron", numOfDriver,numOfStaff, "Motor cycle", "AC1234");
	dStore[0].setAcbalance(1580.0);
	dStore[1].createDriver("Ben Wong","ben", numOfDriver , numOfStaff, "Light goods vehicle", "BW88");
	dStore[1].setAcbalance(805.5);
	dStore[2].createDriver("Carman Lam","carman", numOfDriver, numOfStaff, "Private car", "CL660");
	dStore[2].setAcbalance(50.0);

	bool quit;
	do {
		system("cls");
		quit = ExecuteBegining(Begining(), sStore, dStore, cStore, numOfCarPark, numOfDriver, numOfStaff, day, month, year, date, maxOfStaff, maxOfCarpark, maxOfDriver);
	} while (!quit);
	system("pause");
	return 0;
	delete[]sStore;
	delete[]dStore;
}