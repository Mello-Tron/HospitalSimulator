#ifndef _CITYMAP_
#define _CITYMAP_

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Patient.h"
using namespace std;

class CityMap {
private:
	std::map<std::string, Patient*> pMap;
	std::vector<std::string> names;
public:

	void readFile(int clock) {

		string line;
		fstream citizens("C:\\Users\marnold17\Documents\GitHub\HospitalSimulator\HospitalSimulation\residents_273ville.txt");
		if (!citizens) {
			cout << "Can't open file!" << endl;
		}
		else {
			while (citizens >> line) {
				pMap.insert(make_pair(line, new Patient(clock, line)));
				names.push_back(line);
			}
		}

	}

	void Update(int clock) {

	}

	void ReturnPatient(Patient * patient) {
		pMap.insert(make_pair(patient->getName(), patient));
	}
};

#endif _CITYMAP_