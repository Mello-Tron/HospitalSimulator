#ifndef _PATIENT_
#define _PATIENT_
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Patient {
private:
	vector<int> arrivalTimes;
	vector<int> departureTimes;
	vector<int> waitTimes;
	vector<int> priority;
	string name;
public:

	Patient(int clock, string myName) {
		name = myName;
	}

	int getMostRecentPriority() {
		return priority[priority.size()-1];
	}

	int getMostRecentArrivalTime() {
		return arrivalTimes[arrivalTimes.size() - 1];
	}

	void setPriority(int newPriority) {
		priority.push_back(newPriority);
	}

	void setArrivalTime(int newArrivalTime) {
		arrivalTimes.push_back(newArrivalTime);
	}

	void setWaitTime(int clock) {
		waitTimes.push_back(clock - arrivalTimes[arrivalTimes.size() - 1]);
	}

	int getAverageWaitTime() {
		int sum = 0;
		int i = 0;
		for (i = 0; i < waitTimes.size(); i++) {
			sum += waitTimes[i];
		}

		int average = sum / i;

		return average;
	}

	int getTotalVisits() {
		return waitTimes.size();
	}

	string getName() {
		return name;
	}
};

#endif _PATIENT_