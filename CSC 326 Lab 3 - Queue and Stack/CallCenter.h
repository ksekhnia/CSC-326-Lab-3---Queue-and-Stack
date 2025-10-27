#ifndef CALLCENTER_H
#define CALLCENTER_H

#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Customer {
	string name;
	string state;
	int serviceTime;
};

class CallCenter {
private:
	Queue waitingCustomers; // the queue for customers waiting to receive a call
	Stack missedCalls; // the stack for those who have missed calls
	vector<Customer> customers; // customer data
	int totalTime; // keeping track of time

public:
	CallCenter();

	void loadFile(const string& filename); // const string is because filename never changes
	void runSimulation(); // the call center simulation that will be run

};

#endif