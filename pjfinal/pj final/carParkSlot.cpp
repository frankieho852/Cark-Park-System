#include <string>
#include <iostream>
#include "carParkSlot.h"
using namespace std;
carParkSlot::carParkSlot() {
	slotID = 0;
	carpark = "NULL";
	vehicleType = "NULL";
	for (int i = 0; i < 31; i++) {
		for (int x = 0; x < 24; x++) {
			slotStatus[i][x] = "Free";
		}
	}
}
void carParkSlot::refresh() {
	for (int i = 0; i < 31; i++) {
		for (int x = 0; x < 24; x++) {
			slotStatus[i][x] = "Free";
		}
	}
}
void carParkSlot::createCarParkSlot(string nCarpark, string nVehicleType) {
	slotID = 0;
	carpark = nCarpark;
	vehicleType = nVehicleType;
	for (int i = 0; i < 30; i++) {
		for (int x = 0; x < 24; x++) {
			slotStatus[i][x] = "Free";
		}
	}
}

void carParkSlot::setSlotID(int nSloptID) {
	slotID = nSloptID;
}

void carParkSlot::setStatus(int input, int bookingDay, int bookingTime) {
	switch (input) {
	case 1:
		slotStatus[bookingDay][bookingTime] = "Free";
			break;
	case 2:
		slotStatus[bookingDay][bookingTime] = "Occupied";
			break;
	case 3:
		slotStatus[bookingDay][bookingTime] = "Out of service";
			break;
	}
}

string carParkSlot::getStatus(int day,int time) {
	return slotStatus[day][time];
}
int carParkSlot::getSlotID() {
	return slotID;
}
