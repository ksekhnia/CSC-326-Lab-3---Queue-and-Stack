#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    Node* iterate(int position);
    void insertAt(int position, int value);
    void prepend(int value);
    void append(int value);
    Node* find(int value);
    bool contains(int value);
    bool remove(int value);
    bool removeAtPos(int value);
    bool removeFirst();
    bool removeLast();
    int size();
    void display();

};

#endif