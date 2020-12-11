#include "driver.h"
#include "carpark.h"
#include "carParkSlot.h" 
#include <iostream>
#include <string>
#include <cmath>
#include<sstream>
#include <stdio.h>

using namespace std;

driver::driver() {
	for (int i = 0; i < 31; i++) {
		for (int x = 0; x < 24; x++) {
			bookingTime[x][i] = "NULL";
		}
	}
}

void driver::createDriver(string nName, string nUserName, int &numOfDriver,int numOfStaff, string nVtype, string nPNumber) {
	vtype = nVtype;
	pnumber = nPNumber;
	acbalance = 0;
	numOfDriver++;
	inputUser(nName, nUserName, (numOfDriver+ numOfStaff), "driver");
}

void driver::showAccoutBalance() {
	cout << "The account balance : " << "$" ;
		printf("%.1lf",acbalance); 
		cout << endl;
}

void driver::accoutbalance() {
	cout << "Your account balance: " << "$" ;
	printf("%.1lf",acbalance); 
	cout << endl;
	double c;
	cout << "Enter amount to be increased: ";
	cin >> c;
	printf("%.1lf",c); 
	acbalance += c;
	cout << "The new account balance : " << "$" ;
	printf("%.1lf",acbalance); 
	cout << endl;
}

bool driver::leapYear(int year) {
	return  (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0));
}

// function to return number of days in themonth.
int driver::daysInMonth(int month, int* monthDays, int year) {
	if (month != 2)
		return monthDays[month - 1];
	else {
		if (leapYear(year) == true)
			return 29;
		else
			return 28;
	}
}

void driver::reserve(carPark* &carParts, int numOfCarPart, int &day,int &month,int &year,int date[12],driver* &dStore,int numOfDriver) {
	{
		cout << "Select a car park: " << endl;
		int selectone;
		for (int i = 0; i < numOfCarPart; i++) {
			cout << i+1 << " " << carParts[i].getName() << endl;
		}
		cout << "Please select car park's number : " << endl;
		cin >> selectone;
		selectone -= 1;

		int nday;
		int nmonth;
		int nyear;
		cout << "Please input to day date(yyyy mm dd) : ";
		cin >> nyear;
		cin >> nmonth;
		cin >> nday;
		int maxDay = daysInMonth(nmonth, date, nyear);
		if (nday > maxDay || nday < 1) {
			cout << "No this day" << endl;
			return;
		}
		cout << "Today is: " << nyear << "-" << nmonth << "-" <<  nday<< endl;
		int userday, userhour;
		cout << "Please input the booking time(which o'clock): ";
		cin >> userhour;
		cout << endl;

		cout << "Please input the booking day(in this month): ";
		cin >> userday;
		if (userday > maxDay || userday < 1) {
			cout << "No this day" << endl;
			return;
		}
		carParkSlot* get;
		if (year != nyear || month != nmonth) {
			for (int i = 0; i < numOfCarPart; i++) {
				carParts[i].refresh();
			}
			for (int i = 0; i < numOfDriver; i++) {
				dStore[i].refresh();
			}
		}
		day = nday;
		month = nmonth;
		year = nyear;
		Mfee = carParts[selectone].getMotorCyclesParkingFees();
		Pfee = carParts[selectone].getPrivateCarsParkingFees();
		Lfee = carParts[selectone].getLightGoodsVehiclesParkingFees();
		if (vtype == "Motor cycle") {
			carParts[selectone].getMotorCycles(get);
			for (int i = 0; i < carParts[selectone].getNumOfMotorCycles(); i++) {
				if (get[i].getStatus((userday - 1), (userhour - 1)) != "Free") {
					if (getBookingData((userday - 1), (userhour - 1)) != "NULL") {
						string yesOrNo;
						cout << "You have another booking in the other time.";
					}
					if (acbalance >= Mfee) {
						acbalance -= (Mfee);
						cout << "Sucess booking" << endl;
						carParts[selectone].changeTheBalance(Mfee);
						stringstream a;
						a << i + 1;
						bookingTime[userday - 1][userhour - 1] = carParts[selectone].getName() + " Slot ID" + a.str();
						cout << bookingTime[userday - 1][userhour - 1];
						get[i].getStatus((userday - 1), (userhour - 1)) = "Occupied";
						break;
					}
					else {
						cout << "Cannot booking,acount balance not enough";
						carParts[selectone].changeTheBalance(Mfee);
					}
				}
				else {
					cout << "Cannot finish the booking, please select other time slot";
				}
			}
		}
		else if (vtype == "Private car") {
			carParts[selectone].getPrivateCars(get);
			for (int i = 0; i < carParts[selectone].getNumOfPrivateCars(); i++) {
				if (get[i].getStatus((userday - 1), (userhour - 1)) == "Free") {
					if (acbalance >=(Pfee)) {
						acbalance -= (Pfee);
						cout << "Sucess booking" << endl;
						carParts[selectone].changeTheBalance((Pfee));
						stringstream a;
						a << i+1;
						bookingTime[userday - 1][userhour - 1] = carParts[selectone].getName() + " Slot ID" + a.str();
						cout << bookingTime[userday - 1][userhour - 1] << endl;
						get[i].getStatus((userday - 1), (userhour - 1)) = "Occupied";
						break;
					}
					else {
						cout << "Cannot booking,account balance not enough";
					}
				}
				else {
					cout << "Cannot finish the booking, please select other time slot";
				}
			}
		}
		else {
			carParts[selectone].getLightGoodsVehicles(get);
			for (int i = 0; i < carParts[selectone].getNumOfLightGoodsVehicles(); i++) {
				if (get[i].getStatus((userday - 1), (userhour - 1)) == "Free") {
					if (acbalance >=(Lfee)) {
						acbalance -= (Lfee);
						cout << "Sucess booking " ;
						carParts[selectone].changeTheBalance((Lfee));
						stringstream a;
						a << i+1;
						bookingTime[userday - 1][userhour - 1] = carParts[selectone].getName() + " Slot ID" + a.str();
						cout << bookingTime[userday - 1][userhour - 1];
						get[i].getStatus((userday - 1), (userhour - 1)) = "Occupied";
						break;
					}
					else {
						cout << "Cannot booking,account balance not enough";
					}
				}
				else {
					cout << "Cannot finish the booking, please select other time slot";
				}
			}
		}
	}

}


void driver::refresh()
{
	for (int i = 0; i < 31; i++) {
		for (int x = 0; x < 24; x++) {
			bookingTime[i][x] = "Free";
		}
	}
}

//those get function
float driver::getAcbalance() {
	return acbalance;
}

string driver::getBookingData(int day, int time)
{
	return bookingTime[day][time];
}

string driver::getVtype() { //string type in vehicleType in carParkSlot
	return vtype;
}

string driver::getPnumber() {
	return pnumber;
}

//those set function 
void driver::setVtype(string w) {
	vtype = w;
}

void driver::setPnumber(string w) {
	pnumber = w;
}

void driver::setAcbalance(double a) {
	acbalance = a;
}