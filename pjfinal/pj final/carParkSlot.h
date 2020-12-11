#ifndef CARPARKSLOT_H
#define CARPARKSLOT_H
#include <string>
#include<iostream>
using namespace std;

class carParkSlot {
private:
	int slotID;
	string carpark;				//which car park it is belong to 
	string vehicleType;			//which type of car it will be offer to
	string slotStatus[31][24];	//will store the state of the car park slot
								//the day and time will be show like this bookingTime[day][oclock]
public:
	//the default constarter
	carParkSlot();
	//the 
	void createCarParkSlot(string nCarpark, string nVehicleType);

	//the function to refresh the time slot (the data slotStatus)
	void refresh();

	//those set function
	void setStatus(int input, int bookingDay, int bookingTime);
	void setSlotID(int nSloptID);
	
	//those get function
	string getStatus(int day, int time);
	int getSlotID();
};
#endif