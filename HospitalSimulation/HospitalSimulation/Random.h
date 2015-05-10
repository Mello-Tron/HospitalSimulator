#ifndef _RANDOM_
#define _RANDOM_

#include <cstdlib>
#include <ctime>

class Random {
public:

	Random() {
		srand((unsigned int)std::time(0));
	}

	Random(int seed) {
		srand(seed);
	}

	// Returns a random integer in the range 0 � n
	int next_int(int n) {
		return int(next_double() * n);
	}

	// Return a random double in the range 0 � 1
	double next_double() {
		return double(rand()) / RAND_MAX;
	}
};
#endif _RANDOM_