#ifndef _DOCTOR_
#define _DOCTOR_

#include "Caregiver.h"
#include "PatientQueue.h"

class Doctor : public Caregiver {
private:

public:
	Doctor(CityMap * citymap) {
		city = citymap;
	}

	bool getPatient(int clock, PatientQueue patientQueue) {
		currentPatient = patientQueue.getPatientDoctor();
		if (currentPatient == NULL)
			return false;

		timeWhenNextDone = clock + rand.next_int(20) + 1;
		available = false;

		return true;
	}

};
#endif  _DOCTOR_