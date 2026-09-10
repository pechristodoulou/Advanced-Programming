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

Stack::Stack(const Stack& other) {
    init(other.size);
    count = other.count;
    for (int i = 0; i < count; ++i)
        s[i] = other.s[i];
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
        grow(10);
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

void Stack::grow(int delta) {
    int newSize = size + delta;
    double* newBuf = new double[newSize];
    for (int i = 0; i < count; ++i)
        newBuf[i] = s[i];
    delete[] s;
    s = newBuf;
    size = newSize;
}
