#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
    count = 0;
}

Stack::~Stack() {
    // No dynamic memory used in 3.1, so nothing to free
}

int Stack::nitems() const {
    return count;
}

bool Stack::full() const {
    return (count == LEN);
}

bool Stack::empty() const {
    return (count == 0);
}

void Stack::push(double c) {
    if (full()) {
        cout << "Stack::push() Error: stack is full" << endl;
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
    for (int i = count - 1; i >= 0; --i) {
        cout << " [" << i << "]: " << s[i] << endl;
    }
}
