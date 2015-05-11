#ifndef _CAREGIVER_
#define _CAREGIVER_

#include "Patient.h"

class Caregiver {
private:
	bool available;
	Patient * currentPatient;
public:

	virtual bool getPatient() = 0;  // - virtual becasue depends on doctor and nurse

	bool IsAvailable() {

	}

	void Work(int clock) {

	}
};

#endif _CAREGIVER_
