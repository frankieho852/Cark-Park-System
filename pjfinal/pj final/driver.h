#ifndef DRIVER_H
#define DRIVER_H
#include "carpark.h"
#include "carParkSlot.h" 
#include <string>
#include <iostream>

class driver:public user{
private:
	string vtype;
	string pnumber;
	double acbalance;
	double Mfee;
	double Pfee;
	double Lfee;
	string bookingTime[31][24];		//the data to store the name and the slotID which is booked
									//the day and time will be show like this bookingTime[day][oclock]

public:
	//the default constarter
	driver::driver();
	
	//the function to declear all the data in this class type data
	void createDriver(string nName, string nUserName, int &numOfDriver,int numOfStaff, string nVtype, string nPNumber);
	
	
	//function to check the account balance
	void accoutbalance();

	//the functions about the time
	bool leapYear(int year);
	int daysInMonth(int month, int * monthDays, int year);

	//to show the account balance
	void showAccoutBalance();

	//the function to 
	void reserve(carPark* &carParts, int numOfCarPart, int &day, int &month, int &year, int date[12], driver* &dStore, int numOfDriver);
	
	//those get function
	void refresh();
	float getAcbalance();
	string getBookingData(int day,int time);
	string getVtype();
	string getPnumber();
	
	//those set function
	void setVtype(string w);
	void setPnumber(string w);
	void setAcbalance(double a);
};
#endif



