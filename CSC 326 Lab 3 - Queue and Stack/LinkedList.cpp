#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Iterate to a given position (0-based index)
Node* LinkedList::iterate(int position) {
    if (position < 0) return nullptr;
    Node* current = head;
    int index = 0;
    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }
    return current; // nullptr if not found
}
// Insert at position
void LinkedList::insertAt(int position, int value) {
    Node* newNode = new Node(value);
    if (position <= 0 || head == nullptr) { // Insert at beginning
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* prev = iterate(position - 1);
    if (prev == nullptr) { // Position too big, append at end
        append(value);
        delete newNode; // already appended, avoid memory leak
        return;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}
// Prepend (beginning)
void LinkedList::prepend(int value) {
    insertAt(0, value);
}
// Append (end)
void LinkedList::append(int value) {
    if (head == nullptr) {
        head = new Node(value);
        return;
    }
    Node* last = iterate(size() - 1);
    last->next = new Node(value);
}
// Find node by value
Node* LinkedList::find(int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
// Contains (true/false)
bool LinkedList::contains(int value) {
    return find(value) != nullptr;
}
// Remove by value
bool LinkedList::remove(int value) {
    if (head == nullptr) return false;
    // Special case: head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    // Find previous node of the target
    int index = 0;
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node* target = current->next;
            current->next = target->next;
            delete target;
            return true;
        }
        current = current->next;
        index++;
    }
    return false; // Not found
}
// Remove from position
bool LinkedList::removeAtPos(int value) {
    //check that the linked list size isn't 0 (head = nullptr or that the value is greater
    //than the size of the linked list. if either is true, return false
    if (head == nullptr || value < 0 || value >= size()) {
        return false;
    }
    
    //quicker process of deleting the last value if only one element in linked list
    if (value == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    //previous node will iterate to the value right before the target position value
    //assigning current to previous->next should make it so that current iterates too without
    //having to call iterate twice (I assume in the case of a bigger scale project this would be more efficient
    Node* previous = iterate(value - 1);

    Node* current = previous->next;
    previous->next = current->next;
    delete current;

    return true;

}
// Remove from position
bool LinkedList::removeFirst() {
    return removeAtPos(0);
}
// Remove from position
bool LinkedList::removeLast() {
    if (size() == 0) {
        return false;
    }
    return removeAtPos(size() - 1);
}
// Get size
int LinkedList::size() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
// Display
void LinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
