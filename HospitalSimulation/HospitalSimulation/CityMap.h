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
	std::queue<Patient*> done;  // might not be necessary, but putting it in just for right now
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
				pMap.insert(make_pair(line, new Patient(clock)));
				names.push_back(line);
			}
		}

	}

	void Update(int clock) {

	}

	void Discharge(Patient * patient) {
		done.push(patient);
	}
};

#endif _CITYMAP_