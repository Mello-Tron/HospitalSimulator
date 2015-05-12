#ifndef _COMPARE_
#define _COMPARE_

#include <iostream>
#include "Patient.h"
using namespace std;


// This class will compare patients priority and sort them into the priority queue allowing for greatest priority to be poped from top


class Compare {
public:
	bool operator()(Patient* patient1, Patient* patient2) {
		if (patient1->getPriority() < patient2->getPriority()) {
			return true;
		}
		if (patient1->getPriority() > patient2->getPriority()) {
			return false;
		}
		if (patient1->getPriority() == patient2->getPriority()) {
			if (patient1->getarrivalTime() < patient2->getarrivalTime()) {
				return true;
			}
			else
				return false;
		}

	}
};














#endif 