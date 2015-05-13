#ifndef _CITYMAP_
#define _CITYMAP_

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Random.h"
#include "PatientQueue.h"
using namespace std;

class CityMap {
private:
	std::map<std::string, Patient*> pMap;
	vector<string> names;
	double arrivalRate;
	Random rand;
	PatientQueue * myPatientQueue;
public:
	CityMap(PatientQueue * pQueue) {
		myPatientQueue = pQueue;
	}

	void readFile(int clock) {

		string line;
		fstream citizens("C:\\Users\\marnold17\\Documents\\GitHub\\HospitalSimulator\\HospitalSimulation\\residents_273ville.txt");
		//fstream citizens("C:\\Users\\Michael\\Documents\\GitHub\\HospitalSimulator\\HospitalSimulation\\residents_273ville.txt");
		//fstream citizens("C:\\Users\\Patrick\\Documents\\residents_273ville.txt");
		if (!citizens) {
			cout << "Can't open file!" << endl;
		}
		else {
			while (citizens >> line) {
				//check for duplicates
				if (pMap.count(line) == 0) {
					pMap.insert(make_pair(line, new Patient(clock, line)));
					names.push_back(line);
				}
			}
		}

	}

	void setArrivalRate(double newArrivalRate) {
		arrivalRate = newArrivalRate;
	}

	void Update(int clock) {
		if (rand.next_double() <= arrivalRate && names.size() != 0) {
			TransferRandomPersonToQueue(clock);
		}
	}

	void TransferRandomPersonToQueue(int clock) {
		int randomInt = rand.next_int(names.size()-1);
		string randomName = names[randomInt];
		map<string, Patient*>::iterator it = pMap.find(randomName);
		if (it == pMap.end()) {
			cout << "Something went horribly wrong." << endl;
		}
		myPatientQueue->insertPatient(it->second, clock);
		pMap.erase(it);
		names.erase(names.begin() + randomInt);
	}

	map<std::string, Patient*> getMap() {
		return pMap;
	}

	void ReturnPatient(Patient * patient) {
		pMap.insert(make_pair(patient->getName(), patient));
		names.push_back(patient->getName());
	}
};

#endif _CITYMAP_