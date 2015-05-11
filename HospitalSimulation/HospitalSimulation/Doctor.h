#ifndef _DOCTOR_
#define _DOCTOR_

#include "Caregiver.h"
#include "PatientQueue.h"

class Doctor : public Caregiver {
private:


public:
	Doctor() {}

	virtual bool getPatient() {
		// gert patient from patientqueue based on priority --
		//citymap -> getPatientDoctor
		
		if (patient)
			return true;
		else
			return false;
	}

};
#endif  _DOCTOR_