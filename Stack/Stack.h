#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack(int initialSize = 10);  // Allow optional initial size
    ~Stack();

    void push(double c);
    double pop();
    int nitems() const;
    bool full() const;
    bool empty() const;
    void inspect() const;

private:
    void grow(int delta);         // Expands buffer by delta

    double* s;                    // Dynamic array
    int count;                    // Number of items
    int size;                     // Current allocated size
};

#endif
