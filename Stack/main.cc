#include <iostream>
#include "Stack.h"
using namespace std;

/*
Why are we doing this?
→ We want the Stack to automatically grow when full.
→ This makes the Stack more flexible and removes artificial limits.
*/

int main() {
    Stack s;

    // Push more than 10 elements to test auto-growing
    for (int i = 0; i < 20; ++i)
        s.push(i);

    s.inspect();

    return 0;
}
