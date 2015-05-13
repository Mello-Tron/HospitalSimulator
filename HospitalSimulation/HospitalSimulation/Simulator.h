#ifndef _SIMULATOR_
#define _SIMULATOR_

#include "PatientQueue.h"
#include "CityMap.h"
#include "Caregiver.h"
#include "Doctor.h"
#include "Nurse.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Simulator {
private:
	int clock;
	int totalTime;
	PatientQueue * patientQueue;
	CityMap * cityMap;
	std::vector<Caregiver *> caregivers;

	int read_int(const std::string &prompt, int low, int high)
	{
		if (low >= high)
			throw std::invalid_argument("invalid range specified");

		std::cin.exceptions(std::ios_base::failbit);
		int num = 0;
		while (true) {
			try {
				while (true) {
					std::cout << prompt;
					std::cin >> num;
					if (num >= low && num <= high) {
						std::cout << std::endl;
						return num;
					}
				}
			}
			catch (std::ios_base::failure) {
				std::cout << "Bad numeric string -- try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}

public:
	Simulator() {
		clock = 0;
		totalTime = 60;
		patientQueue = new PatientQueue();
		cityMap = new CityMap(patientQueue);
	}

	void EnterData() {
		std::cout << "Welcome to the CS273ville Hospital Simulator.\n\n";

		int rate = read_int("Please enter the hourly patient arrival rate (patients/hour): ", 1, 60);
		double arrival_rate = rate / 60.0;
		cityMap->setArrivalRate(arrival_rate);

		int numberOfDoctors = read_int("Please enter the number of doctors working at the hospital: ", 0, INT_MAX);
		int numberOfNurses = read_int("Please enter the number of nurses working at the hospital: ", 0, INT_MAX);

		totalTime = read_int("Please enter the simulation time (hours): ", 1, INT_MAX);
		totalTime *= 60;

		for (int i = 0; i < numberOfDoctors; i++) {
			caregivers.push_back(new Doctor(cityMap, patientQueue));
		}

		for (int i = 0; i < numberOfNurses; i++) {
			caregivers.push_back(new Nurse(cityMap, patientQueue));
		}

		cityMap->readFile(clock);
	}

	void RunSimulation() {
		for (int clock = 0; clock < totalTime; clock++) {		// 10080 because 60 x 24 x 7
			cityMap->Update(clock);
			for (int i = 0; i < caregivers.size(); i++) {
				caregivers[i]->Work(clock);
			}

			//Just for fun :)
			cout << "\b\b\b\b\b\b\b" << clock;
			if (clock == 1)
				cout << "\b\b\b\b\b\b\b\b" << "Welcome to CS273ville Hospital!!" << endl;
			if (clock == 1000)
				cout << "\b\b\b\b\b\b\b\b" << "Healing the sick is our specialty." << endl;
			if (clock == 3000)
				cout << "\b\b\b\b\b\b\b\b" << "Our hospital ranked #2 in the nation!" << endl;
			if (clock == 6500)
				cout << "\b\b\b\b\b\b\b\b" << "All our patients get free cookies during their stay." << endl;
			if (clock == 9000)
				cout << "\b\b\b\b\b\b\b\b" << "We hope you have enjoyed your visit." << endl;
		}
	}


	void allRecords() {
		for (map<string, Patient*>::iterator it = cityMap->getMap().begin(); it != cityMap->getMap().end(); it++) {
			cout << it->first << endl;
		}
	}

	void patientRecord(string name) {
		// need to implement -- come back to me
	
	}



	void DisplayRecords() {
		double average = 0;
		int sum = 0;
		int tally = 0;

		for (map<string, Patient*>::iterator it = cityMap->getMap().begin(); it != cityMap->getMap().end(); it++) {
			sum += it->second->getTotalTime();
			tally++;
		}

		average = sum / tally;

		cout << "Average wait time was: " << average << " minutes" << endl;


		/////////////////////////////////////////////////////////////////
		// this is the users menu -- but we can move it else where

		bool exit = false;
		while (!exit) {
			cout << "Welcome, what would you like to do?" << endl;
			cout << "1.) View Patient" << endl;
			cout << "2.) Display all Patients treated" << endl;
			cout << "3.) Exit" << endl;

			int input = read_int("Please enter your decision now (1, 2, or 3): ", 1, 3);
			string name;
			switch (input) {
			case 1:
				cout << "Please enter patient's name: ";
				cin >> name;
				patientRecord(name);
				break;
			case 2:
				allRecords();
				break;
			case 3:
				cout << "Goodbye!" << endl;
				exit = true;
				break;
			}


		}


	}
};

#endif _SIMULATOR_