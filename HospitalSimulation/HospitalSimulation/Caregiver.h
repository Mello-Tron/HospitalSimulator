#ifndef _CAREGIVER_
#define _CAREGIVER_

#include "Random.h"
#include "Patient.h"

class Caregiver {
protected:
	CityMap * city;
	bool available;
	Patient * currentPatient;
	int timeWhenNextDone;
	Random rand;
public:

	virtual bool getPatient() {}  // - virtual becasue depends on doctor and nurse

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
			getPatient();
		}
	}

	Caregiver(CityMap * citymap) {
		city = citymap;
	}

	Caregiver() {}
};

#endif _CAREGIVER_
