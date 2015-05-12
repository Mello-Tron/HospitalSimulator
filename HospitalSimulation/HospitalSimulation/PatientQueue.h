#ifndef _PATIENTQUEUE_
#define _PATIENTQUEUE_
#include <iostream>
#include <queue>
#include "Patient.h"
#include "Compare.h"
using namespace std;
class PatientQueue {

private:

	//priority_queue<Patient> patientPriorityQueue;
	priority_queue<Patient*, Compare> lowPriority;
	priority_queue<Patient*, Compare> highPriority;

public:

	void insertPatient(Patient * newPatient) {
		newPatient->setPriority(0);  // initialize priority to 0
		double priorityNumber = ((double)rand() / RAND_MAX);  // randomly generate priority value based on percentage
		if (priorityNumber <= 0.70) {
			newPatient->setPriority(1 + rand() % 10);
		}
		else if (priorityNumber > 0.70 && priorityNumber <= 0.90) {
			newPatient->setPriority(11 + rand() % 5);
		}
		else if (priorityNumber > 0.90) {
			newPatient->setPriority(16 + rand() % 5);
		}

		if (newPatient->getPriority() > 10)
			highPriority.push(newPatient);
		else
			lowPriority.push(newPatient);
	}

	Patient* getPatientDoctor() {
		if (!highPriority.empty()) {
			Patient* processing = NULL;
			processing = highPriority.top();
			highPriority.pop();
			return processing;
		}
		if (!lowPriority.empty()) {
			Patient* processing = lowPriority.top();
			processing = lowPriority.top();
			lowPriority.pop();
			return processing;
		}
		
		return NULL;
	}

	Patient* getPatientNurse() {
		if (!lowPriority.empty()) {
			Patient* processing = lowPriority.top();
			lowPriority.pop();
			return processing;
		}
		else
			return NULL;
	}

};
#endif _PATIENTQUEUE_