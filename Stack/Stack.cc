#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::init(int sz) {
    size = sz;
    s = new double[size];
    count = 0;
}

Stack::Stack(int initialSize) {
    init(initialSize);
}

Stack::~Stack() {
    delete[] s;
}

int Stack::nitems() const {
    return count;
}

bool Stack::full() const {
    return (count == size);
}

bool Stack::empty() const {
    return (count == 0);
}

void Stack::push(double c) {
    if (full()) {
        cout << "Stack is full. Cannot push." << endl;
        return;
    }
    s[count++] = c;
}

double Stack::pop() {
    if (empty()) {
        cout << "Stack::pop() Error: stack is empty" << endl;
        return 0;
    }
    return s[--count];
}

void Stack::inspect() const {
    cout << "Stack contents (top to bottom):" << endl;
    for (int i = count - 1; i >= 0; --i)
        cout << " [" << i << "]: " << s[i] << endl;
}
