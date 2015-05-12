#ifndef _PATIENTQUEUE_
#define _PATIENTQUEUE_
#include <iostream>
#include <queue>
#include "Patient.h"

using namespace std;
class PatientQueue {

private:

	//priority_queue<Patient> patientPriorityQueue;
	priority_queue<Patient*> lowPriority;
	priority_queue<Patient*> highPriority;

public:
	void insertPatient(Patient * newPatient) {
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