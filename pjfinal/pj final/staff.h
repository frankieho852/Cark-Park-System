#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <stdio.h>
#include "carPark.h"
#include "driver.h"
using namespace std;

class staff : public user
{
public:
	//the default constarter
	staff::staff(){  };

	//the function to declear all the data in this class type data
	void staff::createStaff(string nName, string nUserName, int &numOfStaff);

	//the function to create the new car park
	void newCarPark(carPark* cStore,int &numOfCarpark);

	//the functoin to modify the information in a car park
	void editCarParkInformation(carPark &carPart);

	//the function to help user to select a car park
	int selectcarPark(carPark * carParks, int numOfcarPark);

	//the function to remove the car park
	void remoCarpark(int selectOne, carPark * &carParks, int &lastID);

	//to create the account of staff and driver
	void newUserAccount(driver* &dSlore, staff* &sStore, int &numOfStaff, int &numOfDriver);

	//the functoin to modify the information in a staff or driver
	void staff::editStaffInformation(staff &user);
	void staff::editDriverInformation(driver &user);

	//the function for both staff and driver
	//the function to remove account of driver and staff
	template <typename T>
	void remoUser(T user, T*& users, int &numOfuser,int numOfDriver,driver* drivers) {
        //please note that use (pointer) new keywork in main
		for (int i = 0; i < numOfuser; i++) {
			if (users[i].getUserID()>(user.getUserID())) {
				users[i].setUserID(users[i].getUserID() - 1);
				users[i - 1] = users[i];
			}
		}
		if(user.getRole() =="staff"){
			for (int i = 0; i < numOfDriver; i++) {
				drivers[i].setUserID(drivers[i].getUserID() - 1);
			}
		}
		T a;
		users[numOfuser] = a;
		numOfuser--;

	};

	//the function to help user to select a account
	int selectaccount(staff * staffs, driver * drivers, int numOfDriver, int numOfStaff, string &role);

	//the function to check the state of a carpark slot
	void checkCarParkingSlot(carPark * carParks, int numOfcarPark, int day, int month, int year);

	//the function to check the car park balance
	void CheckCarParkBalance(carPark * carParks, int numOfcarPark);



};
#endif