#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

class Queue {
private:
    LinkedList queue;

public:
    Queue();                //constructor
    ~Queue();               //destructor

    void enqueue(int value); 
    void dequeue();          
    int peek();             
    bool isEmpty();          
    int size();              
    void display();          
};

#endif