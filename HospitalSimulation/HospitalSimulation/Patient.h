#ifndef _PATIENT_
#define _PATIENT_
#include <string>
#include <iostream>
using namespace std;

class Patient {
private:
	int arrivalTime;
	int treatmentTime;
	int departureTime;
	int averageWaitTime;
	int priority;
	int totalVisits;
	string name;
public:
	Patient(int clock, string myName) {
		name = myName;
	}

	int getPriority() {
		return priority;
	}

	int getTotalTime() {
		return averageWaitTime;
	}

	string getName() {
		return name;
	}
};

#endif _PATIENT_