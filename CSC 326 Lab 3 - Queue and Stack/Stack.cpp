#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {}
Stack::~Stack() {}

//add an item to the top of the stack. same functionality as appending
//reinforces the idea of "last in" this way
void Stack::push(int value) {
    stack.append(value);
}
//removes the item at the top of the stack. will be using stack.removeLast() to
//reinforce the idea "LIFO" (last in first out)
void Stack::pop() {
    //if statement to check if stack is empty is not needed as removeAtPos linked list function
    //already takes care of that
    stack.removeLast();
}
int Stack::peek() {
    //if statement to check if stack is empty and return an error if so
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    
    Node* node = stack.iterate(stack.size() - 1);
    return node->data;
}

bool Stack::isEmpty() {
    //conditional to check if stack size is 0 to determine whether stack is empty or not
    if (stack.size() == 0) {
        return true;
    }
    return false;
}

int Stack::size() {
    //same as linked list version of size(), simply return that
    return stack.size();
}

void Stack::display() {
    //same as linked list version of display(), simply execute that
    stack.display();
}