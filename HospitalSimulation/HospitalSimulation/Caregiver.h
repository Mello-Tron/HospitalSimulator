#ifndef _CAREGIVER_
#define _CAREGIVER_

#include "Random.h"
#include "Patient.h"

class Caregiver {
protected:
	CityMap * city;
	PatientQueue * patientQueue;
	bool available;
	Patient * currentPatient;
	int timeWhenNextDone;
	Random rand;
public:

	virtual bool getPatient(int clock, PatientQueue * patientQueue) {
		return false;
	}

	void Discharge(Patient* patient) {
		city->ReturnPatient(patient);
		currentPatient = NULL;
	}

	bool IsAvailable() {
		return available;
	}

	void Work(int clock) {
		if (clock >= timeWhenNextDone && !available) {
			Discharge(currentPatient);
			available = true;
		}
		else if (available) {
			getPatient(clock, patientQueue);
		}
	}

	Caregiver(CityMap * citymap, PatientQueue * pQueue) {
		city = citymap;
		patientQueue = pQueue;
	}

	Caregiver() {}
};

#endif _CAREGIVER_
