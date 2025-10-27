#include<iostream>
#include "CallCenter.h"
using namespace std;
int main() {
	
	//Queue fits waiting customers as queues are FIFO (first in, first out), which is how queues in
	//customer service often tend to work. Stack fits missed calls since people will usually reach out to
	//the person who had a missed call last, making it appropriate to use stacks, which are LIFO
	//(last in, first out).
	
	CallCenter callCenter;
	callCenter.loadFile("calls.txt");
	callCenter.runSimulation();

	return 0;
}