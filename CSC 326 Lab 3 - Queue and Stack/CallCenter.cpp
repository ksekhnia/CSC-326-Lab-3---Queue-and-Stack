#include "CallCenter.h"
#include <iostream>
using namespace std;

//totalTime(0) in the constructor as the simulation has not started at this point
CallCenter::CallCenter() : totalTime(0) {}

// Load data from file
void CallCenter::loadFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return;
    }

    string name, state;
    int time;
    int index = 0;

    // while you can still read the name state and time from the file
    while (file >> name >> state >> time) {
        //customer data about one customer
        Customer customer = { name, state, time };
        //vector of customer data
        customers.push_back(customer);

        // index used to tell apart people within the two lists quickly
        if (state == "waiting") {
            waitingCustomers.enqueue(index);
        }
        else if (state == "missed") {
            missedCalls.push(index);
        }
        index++;
    }
    //no more use for the file at this point since the data's stored in the code now, so it can be closed now
    file.close();
}

void CallCenter::runSimulation() {
    cout << "CALL CENTER SIMULATION: START =================" << endl;
    //simulation will run while either the queue or stack are not empty
    //3 people will be called from the queue (using a for loop) first, during which the customer
    //currently being served will be displayed, and the time of the service.
    //after each call, the total time will be updated. current person is then dequeued.
    //after three calls, call back one missed caller while the stack isnt empty. do the same as above except
    //the caller will be popped after.

    while (!waitingCustomers.isEmpty() || !missedCalls.isEmpty()) {

        //queue of waitingcustomers
        for (int i = 0; i < 3 && !waitingCustomers.isEmpty(); i++) {
            //current customer data pulled is the customer at the front of the queue
            //which is grabbed by the peek method
            Customer customer = customers[waitingCustomers.peek()];

            cout << "Currently serving " << customer.name << " with a service time of "
                << customer.serviceTime << " minutes." << endl;
            totalTime += customer.serviceTime;
            cout << "Total service time so far: " << totalTime << " minutes." << endl;
            waitingCustomers.dequeue();
        }

        //stack of missedcalls
        if (!missedCalls.isEmpty()) {
            //current customer data pulled is the customer at the top of the stack
            //which is grabbed by the peek method
            Customer customer = customers[missedCalls.peek()];

            cout << "Currently calling back " << customer.name << " with a service time of "
                << customer.serviceTime << " minutes." << endl;
            totalTime += customer.serviceTime;
            cout << "Total service time so far: " << totalTime << " minutes." << endl;
            missedCalls.pop();
        }

        cout << "============================================" << endl;

    }

    cout << "Simulation complete." << endl << "Total time: " << totalTime << endl;

}