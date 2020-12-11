#include <iostream>
#include"driver.h"
#include "staff.h"
#include "carPark.h"
#include <sstream>
#include<string>
#include <stdio.h>
#include "user.h"
using namespace std;

//the function to declear all the data in this class type data
void staff::createStaff(string nName, string nUserName, int &numOfStaff) {
	numOfStaff++;
	inputUser(nName, nUserName, numOfStaff, "staff");
}

//the function to create new car park
void staff::newCarPark(carPark* cStore,int& numOfCarpark) {
	cout << "Please input the infromation of new car park"<< endl;

	//get the information of the new car park
	cout << "Car Park Name : ";
	string nName;
	cin >> nName;

	cout << "Car Park Location : ";
	string nLocation;
	cin >> nLocation;

	cout << "Total number of slots in car park : ";
	int nTotalNumberOfSlots;
	cin >> nTotalNumberOfSlots;

	cout << "Car Park fees of motor cycles : ";
	int nMotorCyclesParkingfees;
	cin >> nMotorCyclesParkingfees;

	cout << "Car Park fees of private cars : ";
	int nPrivateCarsParkingfees;
	cin >> nPrivateCarsParkingfees;

	cout << "Car Park fees of light goods vehicles : ";
	int nLightGoodsVehiclesParkingfees;
	cin >> nLightGoodsVehiclesParkingfees;

	cout << "Number of Motor Cycles's slot in car park : ";
	int numOfMotorCycles;
	cin >> numOfMotorCycles;

	cout << "Number of Private Cars's slot in car park : ";
	int numOfPrivateCars;
	cin >> numOfPrivateCars;

	cout << "Number of Light Goods Vehicle's slot in car park : ";
	int numOfLightGoodsVehicles;
	cin >> numOfLightGoodsVehicles;

	//call the function to input the data
	cStore[numOfCarpark].createCarPark(
		nName,
		nLocation,
		nTotalNumberOfSlots,
		0,
		nMotorCyclesParkingfees,
		nPrivateCarsParkingfees,
		nLightGoodsVehiclesParkingfees,
		numOfMotorCycles,
		numOfPrivateCars,
		numOfLightGoodsVehicles,
		numOfCarpark);

}

//the function to modify the information of car park
void staff::editCarParkInformation(carPark &carPark)
{
	bool control;
	cout << "Edit Car Park Information" << endl;
	carPark.outputInfromation();
	string input1;
	do {
		cout << "Please input your chose : ";
		int choose;
		cin >> choose;
		cout << "The new data is : ";
		int input;

		string sInput;
		switch (choose) {
		case 1:
			cin >> sInput;
			carPark.setName(sInput);
			break;
		case 2:
			cin >> sInput;
			carPark.setLocation(sInput);
			break;

		case 3:
			cin >> input;
			carPark.setTotalNumberOfSlots(input);
			break;

		case 4:
			cin >> input;
			carPark.setAccountBalance(input);
			break;

		case 5:
			cin >> input;
			carPark.setMotorCyclesParkingFees(input);
			break;

		case 6:
			cin >> input;
			carPark.setPrivateCarsParkingFees(input);
			break;

		case 7:
			cin >> input;
			carPark.setLightGoodsVehiclesParkingFees(input);
			break;

		case 8:
			cin >> input;
			carPark.setNumOfMotorCycles(input);
			break;

		case 9:
			cin >> input;
			carPark.setNumOfPrivateCars(input);
			break;

		case 10:
			cin >> input;
			carPark.setNumOfLightGoodsVehicles(input);
			break;
		}
		system("cls");
		cout << "The new infromation will be : " << endl;		//to show out the new data
		cout << endl;
		carPark.outputInfromation();

		cout << "Do you want to edit other information in this car part ? (Yes / No)" << endl;

		cin >> input1;
	} while (input1 == "Yes");
}

//the function to help user to select a car park
int staff::selectcarPark(carPark* carParks, int numOfcarPark) {
	cout << "Please select one car part : " << endl;
	for (int i = 0; i<numOfcarPark; i++) {
		cout << i + 1 << " " << carParks[i].getName() << endl; //show all the carpark for user to select
	}
	cout << "The select car part's number : " << endl;
	int selectOne;
	cin >> selectOne;
	return (selectOne - 1); //return number will input to the carPark[(here)] to call the other function
}

//the function to remove the car park
void staff::remoCarpark(int selectOne, carPark* &carParks, int &numOfcarPark) {
	for (int i = 0; i<numOfcarPark; i++) {
		if (carParks[i].getCarParkID() > selectOne + 1) {
			carParks[i].setCarParkID(carParks[i].getCarParkID() - 1);
			carParks[i - 1] = carParks[i];
		}
	}
	carPark a;
	carParks[numOfcarPark - 1] = a;
	numOfcarPark--;		//ipdata the number of staff
}

//function to create the account of staff and driver
void staff::newUserAccount(driver* &dSlore, staff* &sStore, int &numOfStaff, int &numOfDriver) {
	cout << "Please input the information of the new account" << endl;
	cout << "Please choose the role of the new account(staff / driver)";
	string nRole;
	string nUsername;
	string nName;
	cin >> nRole;
	cout << "Username : ";
	cin >> nUsername;
	cout << "Name : ";
	cin.ignore();
	getline(cin, nName);
	for (int i = 0; i < numOfDriver; i++)//to checking is the new username repeat 
	{
		if ((nUsername == dSlore[i].getUserName()) == true) {
			cout << "The user Name is repeat" << endl;
			return;
		}
	}
	for (int i = 0; i < numOfStaff; i++)
	{
		if ((nUsername == sStore[i].getUserName()) == true) {
			cout << "The user Name is repeat" << endl;
			return;
		}
	}

	//the data noly driver need
	if (nRole == "driver") {
		string nVehicleType;
		string nPlateNumber;
		cout << "Vehicle Type : ";
		cin.ignore();
		getline(cin, nVehicleType);
		cout << "Plate Number : ";
		cin >> nPlateNumber;
		dSlore[numOfDriver].createDriver(nName, nUsername, numOfDriver, numOfStaff, nVehicleType, nPlateNumber);
	}

	//to call the function to create staff
	if (nRole == "staff") {
		sStore[numOfStaff].createStaff(nName, nUsername, numOfStaff);
	}
}

//the functoin to modify the information in a staff or driver
void staff::editDriverInformation(driver &user) {
	cout << "Please select the information to edit : " << endl;
	cout << "1 User Name \n" << "2 Name \n";
	cout << "3 Vehicle Type\n" << "4 Plate Number\n";
	cout << "Input:";
	int choose;
	cin >> choose;
	string input;
	cout << "The new data :";
	switch (choose) {
	case 1:
		cin >> input;
		user.setUserName(input);
		break;
	case 2:
		cin >> input;
		user.setName(input);
		break;
	case 3:
		cin >> input;
		user.setVtype(input);
		break;
	case 4:
		cin >> input;
		user.setPnumber(input);
		break;
	}
	cout << "1 User Name " << user.getUserName() << endl;
	cout << "2 Name " << user.getName() << endl;
	cout << "3 Vehicle Type" << user.getVtype() << endl;
	cout << "4 Plate Number" << user.getPnumber() << endl;
}
void staff::editStaffInformation(staff &user) {
	cout << "Please select the information to edit : " << endl;
	cout << "1 User Name \n" << "2 Name \n";
	cout << "Input:";
	int choose;
	string input;
	cin >> choose;
	switch (choose) {

	case 1:
		cout << "The new data :";
		cin >> input;
		user.setUserName(input);
		break;
	case 2:
		cout << "The new data :";
		cin >> input;
		user.setName(input);
		break;
	}

	system("cls");
	cout << "The updata data";
	cout << "1 User Name " << user.getUserName() << endl;
	cout << "2 Name " << user.getName() << endl;
}

//the function to remove the account in the staff.h

//the function to help user to select a account
int staff::selectaccount(staff* staffs, driver* drivers, int numOfDriver, int numOfStaff,string &role) {
	cout << "Select account" << endl;
	cout << "Please input the username : ";
	string input;
	cin>> input;
	for (int i = 0; i<numOfStaff; i++) {
		if (staffs[i].getUserName() == input) {
			role = "staff";
			return i;
		}
	}
	for (int i = 0; i<numOfDriver; i++) {
		if (drivers[i].getUserName() == input) {
			role = "driver";
			return i;
		}
	}
	return -1;		//maening no this account
}

//the function to check the state of a carpark slot
void staff::checkCarParkingSlot(carPark* carParks, int numOfcarPark,int day,int month,int year) {
	int select = selectcarPark(carParks, numOfcarPark);
	carParks[select].outputTheSlots();
	cout << "Please input the slot's ID or Show All to selcet : ";
	string input;
	cin.ignore();
	getline(cin, input);

	int checkDay, time;
	//to show the day of today;
	cout << "Today is :" << day << "/" << month << "/" << year << endl;
	cout << "Please input the day you want to check (in this month): ";
	cin >> checkDay;
	cout << "Please input the time you want to check (1-24): ";
	cin >> time;
	if (input != "Show All") {
		//showing the selected car park slot status
		carParkSlot* get;
		int ID = stol(input);
		string status;
		if (ID<carParks[select].getNumOfMotorCycles()) {
			carParks[select].getMotorCycles(get);
			status = get[ID - 1].getStatus(checkDay, time);
		}

		else if (ID<carParks[select].getNumOfPrivateCars() + carParks[select].getNumOfMotorCycles()) {
			carParks[select].getMotorCycles(get);
			status = get[ID - 1 - carParks[select].getNumOfMotorCycles()].getStatus(checkDay, time);
		}

		else {
			ID -= (carParks[select].getNumOfMotorCycles() + carParks[select].getNumOfPrivateCars());
			carParks[select].getMotorCycles(get);
			status = get[ID - 1].getStatus(checkDay, time);
		}
		cout << "the status of ID " << ID << "slot is " << status << endl;
	}
	//showing all the status of all the car park slot
	else {
		carParkSlot* get;
		cout << "Motor Cycle's Slots\n";
		carParks[select].getMotorCycles(get);
		for (int i = 0; i<carParks[select].getNumOfMotorCycles(); i++) {
			cout << get[i].getSlotID() << " " << get[i].getStatus(day, time) << endl;
		}

		cout << "Private Car's Slots\n";
		carParks[select].getPrivateCars(get);
		for (int i = 0; i<carParks[select].getNumOfPrivateCars(); i++) {
			cout << get[i].getSlotID() << " " << get[i].getStatus(day, time) << endl;
		}

		cout << "Light Goods Vehicle's Slots\n";
		carParks[select].getPrivateCars(get);
		for (int i = 0; i<carParks[select].getNumOfLightGoodsVehicles(); i++) {
			cout << get[i].getSlotID() << " " << get[i].getStatus(day, time) << endl;
		}
	}
}

//the function to check the car park balance
void staff::CheckCarParkBalance(carPark* carParks, int numOfcarPark) {
	int select = selectcarPark(carParks, numOfcarPark);
	cout << "The balance of this car park : ";
	printf("%.1lf",carParks[select].getAccountBalance() ); 
	cout << endl;
}

