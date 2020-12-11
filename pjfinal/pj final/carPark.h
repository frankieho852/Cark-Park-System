#ifndef CARPARK_H
#define CARPARK_H
#include <iostream>
#include "user.h"
#include "carParkSlot.h"
#include<string>
using namespace std;
class carPark
{
protected:
	int carParkID;
	string name;
	string location;
	int totalNumberOfSlots;
	double accountBalance;
	int motorCyclesParkingFees;
	int privateCarsParkingFees;
	int lightGoodsVehiclesParkingFees;
	int numOfMotorCycles;
	int numOfPrivateCars;
	int numOfLightGoodsVehicles;
	carParkSlot* motorCycles;
	carParkSlot* privateCars;
	carParkSlot* lightGoodsVehicles;
public:

	carPark::carPark() {
	};

	carPark::~carPark() {
		if (motorCycles != NULL) {
			delete[] motorCycles;
		}
		if (privateCars != NULL) {
			delete[] privateCars;
		}
		if (lightGoodsVehicles != NULL) {
			delete[] lightGoodsVehicles;
		}
	}

	void createCarPark(
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
		int &numOfCarpark);

	//those set function
	void setCarParkID(int x);
	void setName(string x);
	void setLocation(string  x);
	void setTotalNumberOfSlots(int x);
	void setAccountBalance(double x);
	void setMotorCyclesParkingFees(int x);
	void setPrivateCarsParkingFees(int x);
	void setLightGoodsVehiclesParkingFees(int x);
	void setNumOfMotorCycles(int x);
	void setNumOfPrivateCars(int x);
	void setNumOfLightGoodsVehicles(int x);

	//those get function
	int getCarParkID();
	string getName();
	string getLocation();
	int getTotalNumberOfSlots();
	double getAccountBalance();
	int getMotorCyclesParkingFees();
	int getPrivateCarsParkingFees();
	int getLightGoodsVehiclesParkingFees();
	int getNumOfMotorCycles();
	int getNumOfPrivateCars();
	int getNumOfLightGoodsVehicles();
	void getMotorCycles(carParkSlot *& get);
	void getPrivateCars(carParkSlot *& get);
	void getLightGoodsVehicles(carParkSlot *& get);

	//the function to show all the slot ID
	void outputTheSlots();
	
	//the function to increase the balance of car park
	void changeTheBalance(double change);

	//to refresh the data
	void refresh();

	//set the slot ID
	void inputSlotID(int numOfMotorCycles, int numOfPrivateCars, int numOfLightGoodsVehicles, int nTotalNumberOfSlots);

	//show the cae park information
	void outputInfromation();

};
#endif
