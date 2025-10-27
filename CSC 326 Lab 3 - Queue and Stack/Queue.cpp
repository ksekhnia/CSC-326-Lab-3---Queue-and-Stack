#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {}
Queue::~Queue() {}

//add an item to the rear of the queue. append can be used for this
//reinforces the "first in" part of FIFO
void Queue::enqueue(int value) {
	queue.append(value);
}

//removes first element in the queue. removeFirst from linked list methods can be used to
//reinforce the idea of first in first out (FIFO)
void Queue::dequeue() {
	//don't need to check if queue is empty as removeAtPos does this automatically
	queue.removeFirst();
}

//functionally the same as the stack version of the peek code, but instead viewing the front (first element)
//instead of the top (last element)
int Queue::peek() {
    //if statement to check if stack is empty and return an error if so
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    Node* node = queue.iterate(0);
    return node->data;
}

//same as stack code
bool Queue::isEmpty() {
    //conditional to check if stack size is 0 to determine whether stack is empty or not
    if (queue.size() == 0) {
        return true;
    }
    return false;
}

//same as stack code
int Queue::size() {
    return queue.size();
}

//same as stack code
void Queue::display() {
    queue.display();
}