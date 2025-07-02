#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack(int initialSize = 10);
    ~Stack();

    void push(double c);
    double pop();
    int nitems() const;
    bool full() const;
    bool empty() const;
    void inspect() const;

private:
    void grow(int delta);
    void init(int size);

    double* s;
    int count;
    int size;
};

#endif
