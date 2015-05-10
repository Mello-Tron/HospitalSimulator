#ifndef _CITYMAP_
#define _CITYMAP_

#include <map>
#include <vector>
#include <string>
#include "Patient.h"

class CityMap {
private:
	std::queue<Patient*> done;  // might not be necessary, but putting it in just for right now
	std::map<std::string, Patient> pMap;
	std::vector<std::string> names;
public:
	void Update(int clock) {

	}

	void Disharge(Patient * patient) {
		done.push(patient);
	}
};

#endif _CITYMAP_