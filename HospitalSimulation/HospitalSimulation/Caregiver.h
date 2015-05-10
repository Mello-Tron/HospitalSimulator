#ifndef _CAREGIVER_
#define _CAREGIVER_

#include "Patient.h"

class Caregiver {
private:
	CityMap * done;
	bool available;
	Patient * currentPatient;
public:
	void Discharge(Patient* patient) {
		done->Discharge(patient);
	}
	bool IsAvailable() {
		return available;
	}

	void Work(int clock) {

	}

	Caregiver() {}
};

#endif _CAREGIVER_
