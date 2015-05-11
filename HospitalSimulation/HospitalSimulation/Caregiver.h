#ifndef _CAREGIVER_
#define _CAREGIVER_

#include "Patient.h"

class Caregiver {
private:
	CityMap * done;
	bool available;
	Patient * currentPatient;
public:
<<<<<<< HEAD

	virtual bool getPatient() = 0;  // - virtual becasue depends on doctor and nurse

=======
	void Discharge(Patient* patient) {
		done->Discharge(patient);
	}
>>>>>>> origin/master
	bool IsAvailable() {
		return available;
	}

	void Work(int clock) {

	}

	Caregiver() {}
};

#endif _CAREGIVER_
