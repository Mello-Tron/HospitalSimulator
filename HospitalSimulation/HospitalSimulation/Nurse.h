#ifndef _NURSE_
#define _NURSE_

#include "Caregiver.h"
#include "PatientQueue.h"

class Nurse : public Caregiver {
private:

public:
	Nurse(CityMap * citymap) {
		city = citymap;
	}

	bool getPatient(int clock, PatientQueue patientQueue) {
		currentPatient = patientQueue.getPatientNurse();
		if (currentPatient == NULL)
			return false;

		timeWhenNextDone = clock + rand.next_int(10) + 1;
		available = false;

		return true;
	}

};

#endif _NURSE_