#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Stack {
private:
	LinkedList stack;

public:
	Stack();	// constructor
	~Stack();	// destructor

	void push(int value);
	void pop();
	int peek();
	bool isEmpty();
	int size();
	void display();
};

#endif