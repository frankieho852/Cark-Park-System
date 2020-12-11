#include "carPark.h"
#include "carParkSlot.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//the function to input information of car park
void carPark::createCarPark(
	string nName,
	string nLocation,
	int nTotalNumberOfSlots,
	double nAccountBalance,
	int nMotorCyclesParkingfees,
	int nPrivateCarsParkingfees,
	int nLightGoodsVehiclesParkingfees,
	int nNumOfMotorCycles,
	int nNumOfPrivateCars,
	int nNumOfLightGoodsVehicles,
	int &numOfCarpark) {
	numOfCarpark++;
	carParkID = numOfCarpark;
	name = nName;
	location = nLocation;
	totalNumberOfSlots = nTotalNumberOfSlots;
	accountBalance = nAccountBalance;
	motorCyclesParkingFees = nMotorCyclesParkingfees;
	privateCarsParkingFees = nPrivateCarsParkingfees;
	lightGoodsVehiclesParkingFees = nLightGoodsVehiclesParkingfees;
	numOfMotorCycles = nNumOfMotorCycles;
	numOfPrivateCars = nNumOfPrivateCars;
	numOfLightGoodsVehicles = nNumOfLightGoodsVehicles;

	motorCycles = new carParkSlot[nNumOfMotorCycles];
	privateCars = new carParkSlot[nNumOfPrivateCars];
	lightGoodsVehicles = new carParkSlot[nNumOfLightGoodsVehicles];
	for (int i = 0; i < nNumOfMotorCycles; i++) {
		motorCycles[i].createCarParkSlot(name, "Motor cycle");
	}
	for (int i = 0; i < nNumOfPrivateCars; i++) {
		privateCars[i].createCarParkSlot(name, "Private car");
	}
	for (int i = 0; i < nNumOfLightGoodsVehicles; i++) {
		lightGoodsVehicles[i].createCarParkSlot(name, "Light goods vehicle");
	}
	inputSlotID(nNumOfMotorCycles, nNumOfPrivateCars, nNumOfLightGoodsVehicles, nTotalNumberOfSlots);
	
}


void carPark::changeTheBalance(double change) {
	accountBalance += change;
}


void carPark::refresh() {
	for (int i = 0; i < totalNumberOfSlots; i++) {
		if (i < numOfMotorCycles)
			motorCycles[i].refresh();
		else if (i < (numOfMotorCycles + numOfPrivateCars))
			privateCars[i - numOfMotorCycles].refresh();
		else
			lightGoodsVehicles[i - numOfMotorCycles - numOfPrivateCars].refresh();
	}
	
}

void carPark::inputSlotID(int numOfMotorCycles, int numOfPrivateCars, int numOfLightGoodsVehicles,int nTotalNumberOfSlots) {
	int ID=1;
	for (int i = 0; i < numOfMotorCycles; i++) {
		motorCycles[i].setSlotID(ID);
		ID++;
	}
	for (int i = 0; i < numOfPrivateCars; i++) {
		privateCars[i].setSlotID(ID);
		ID++;
	}
	for (int i = 0; i < numOfLightGoodsVehicles; i++) {
		lightGoodsVehicles[i].setSlotID(ID);
		ID++;
	}
}

void carPark::outputInfromation() {
	cout << "Car Park ID : " << carParkID << endl;
	cout << "1 Name : " << name << endl;
	cout << "2 Location : " << location << endl;
	cout << "3 Total Number Of Slots : " << totalNumberOfSlots << endl;
	cout << "4 Account Balance : " << accountBalance << endl;
	cout << "5 Motor Cycles Parking Fees : " << motorCyclesParkingFees << endl;
	cout << "6 Private Cars Parking Fees : " << privateCarsParkingFees << endl;
	cout << "7 Light Goods Vehicles Parking Fees : " << lightGoodsVehiclesParkingFees << endl;
	cout << "8 Number Motor Cycles Slot : " << numOfMotorCycles << endl;
	cout << "9 Private Cars Slot : " << numOfPrivateCars << endl;
	cout << "10 Light Goods Vehicles Slot : " << numOfLightGoodsVehicles << endl;
}

void carPark::setCarParkID(int x) {
	carParkID = x;
}
void carPark::setName(string x) {
	name = x;
}
void carPark::setLocation(string  x) {
	location = x;
}
void carPark::setTotalNumberOfSlots(int x) {
	totalNumberOfSlots = x;
}
void carPark::setAccountBalance(double x) {
	accountBalance = x;
}
void carPark::setMotorCyclesParkingFees(int x) {
	motorCyclesParkingFees = x;
}
void carPark::setPrivateCarsParkingFees(int x) {
	privateCarsParkingFees = x;
}
void carPark::setLightGoodsVehiclesParkingFees(int x) {
	lightGoodsVehiclesParkingFees = x;
}
void carPark::setNumOfMotorCycles(int x) {
	carParkSlot* a = motorCycles;
	motorCycles = new carParkSlot[x];
	for (int i = 0; i < numOfMotorCycles; i++) {
		motorCycles[i] = a[i];
	}
	numOfMotorCycles = x;
	delete[] a;
	inputSlotID(numOfMotorCycles, numOfPrivateCars, numOfLightGoodsVehicles, totalNumberOfSlots);
}
void carPark::setNumOfPrivateCars(int x) {
	carParkSlot* a = privateCars;
	privateCars = new carParkSlot[x];
	for (int i = 0; i < numOfPrivateCars; i++) {
		privateCars[i] = a[i];
	}
	numOfPrivateCars = x;
	delete[] a;
	inputSlotID(numOfMotorCycles, numOfPrivateCars, numOfLightGoodsVehicles, totalNumberOfSlots);
}
void carPark::setNumOfLightGoodsVehicles(int x) {
	carParkSlot* a = lightGoodsVehicles;
	lightGoodsVehicles = new carParkSlot[x];
	for (int i = 0; i < numOfLightGoodsVehicles; i++) {
		lightGoodsVehicles[i] = a[i];
	}
	numOfLightGoodsVehicles = x;
	delete[] a;
	inputSlotID(numOfMotorCycles, numOfPrivateCars,numOfLightGoodsVehicles,totalNumberOfSlots);
}



int carPark::getCarParkID() {
	return  carParkID;
}
string carPark::getName() {
	return name;
}
string carPark::getLocation() {
	return location;
}
int carPark::getTotalNumberOfSlots() {
	return totalNumberOfSlots;
}
double carPark::getAccountBalance() {
	return accountBalance;
}
int carPark::getMotorCyclesParkingFees() {
	return  motorCyclesParkingFees;
}
int carPark::getPrivateCarsParkingFees() {
	return privateCarsParkingFees;
}
int carPark::getLightGoodsVehiclesParkingFees() {
	return lightGoodsVehiclesParkingFees;
}
int carPark::getNumOfMotorCycles() {
	return numOfMotorCycles;
}
int carPark::getNumOfPrivateCars() {
	return numOfPrivateCars;
}
int carPark::getNumOfLightGoodsVehicles() {
	return numOfLightGoodsVehicles;
}

void carPark::getMotorCycles(carParkSlot* &get) {
	get = motorCycles;
}

void carPark::getPrivateCars(carParkSlot* &get) {
	get = privateCars;
}

void carPark::getLightGoodsVehicles(carParkSlot* &get) {
	get = lightGoodsVehicles;
}

void carPark::outputTheSlots() {
	cout << "the ID of those car park slots\n";
	cout << "Motor Cycle's Slots\n";
	carParkSlot* get;
	getMotorCycles(get);
	for (int i = 0; i<getNumOfMotorCycles(); i++) {
		cout << get[i].getSlotID() << endl;
	}

	cout << "Private Car's Slots\n";
	getPrivateCars(get);
	for (int i = 0; i<getNumOfPrivateCars(); i++) {
		cout << get[i].getSlotID() << endl;
	}

	cout << "Light Goods Vehicle's Slots\n";
	getLightGoodsVehicles(get);
	for (int i = 0; i<getNumOfLightGoodsVehicles(); i++) {
		cout << get[i].getSlotID() << endl;
	}

}

