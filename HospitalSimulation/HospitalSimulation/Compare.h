#ifndef _COMPARE_
#define _COMPARE_

#include <iostream>
#include "Patient.h"
using namespace std;


// This class will compare patients priority and sort them into the priority queue allowing for greatest priority to be poped from top


class Compare {
public:
	bool operator()(Patient* patient1, Patient* patient2) {
		if (patient1->getMostRecentPriority() > patient2->getMostRecentPriority()) {
			return true;
		}
		else if (patient1->getMostRecentPriority() < patient2->getMostRecentPriority()) {
			return false;
		}
		else if (patient1->getMostRecentPriority() == patient2->getMostRecentPriority()) {
			if (patient1->getMostRecentArrivalTime() > patient2->getMostRecentArrivalTime()) {
				return true;
			}
			else
				return false;
		}

	}
};














#endif 