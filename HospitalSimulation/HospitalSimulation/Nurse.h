#ifndef _NURSE_
#define _NURSE_

#include "Caregiver.h"
#include "PatientQueue.h"

class Nurse : public Caregiver {
private:


public:
	Nurse() {}

	virtual bool getPatient() {
		// gert patient from patientqueue based on priority 
		//citymap -> getPatientNurse
		if (patient)
			return true;
		else
			return false;
	}

};

#endif _NURSE_