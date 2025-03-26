#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack();                // Constructor
    ~Stack();               // Destructor

    void push(double c);
    double pop();
    int nitems() const;
    bool full() const;
    bool empty() const;
    void inspect() const;

private:
    static const int LEN = 80;
    double s[LEN];
    int count;
};

#endif
