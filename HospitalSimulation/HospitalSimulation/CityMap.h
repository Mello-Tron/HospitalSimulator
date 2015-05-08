#ifndef _CITYMAP_
#define _CITYMAP_

#include <map>
#include <vector>
#include <string>
#include "Patient.h"

class CityMap {
private:
	std::map<std::string, Patient> pMap;
	std::vector<std::string> names;
public:
	void Update(int clock) {

	}
};

#endif _CITYMAP_