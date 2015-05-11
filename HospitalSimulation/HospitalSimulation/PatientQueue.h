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

	Patient* getPatientDoctor() {
		if (!highPriority.empty()) {
			Patient* processing = NULL;
			processing = highPriority.top();
			highPriority.pop();
			return processing;
		}
		else if (!lowPriority.empty()) {
			Patient* processing = lowPriority.top();
			lowPriority.pop();
			return processing;
		}
		else
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

















	void Update(int clock) {

		Doctor->Work();
		Nurse->Work();

		bool newPatient;

		while (newPatient = true) {
			if (/*Nurse is available && Patient.getPriority > 0 && Patient.getPriority <= 10*/) {
				//Assign patient to Nurse
				//Restart WHILE loop
			}
			else if (/*Doctor is available && Patient.getPriority >= 11 && patient.getPriority <= 20*/) {
				//Assign patient to Doctor
				//Restart WHILE loop
			}
			else if (/*Doctor is available && Patient.getPriority >= 1 && patient.getPriority <= 10 */) {
				//Assign patient to Doctor
				//Restart WHILE loop
			}
			else
				newPatient = false;
		}
		
	}

};
#endif _PATIENTQUEUE_