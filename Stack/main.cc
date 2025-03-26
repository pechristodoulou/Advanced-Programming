#include <iostream>
#include "Stack.h"
using namespace std;

/*
Why are we doing this?
→ To transition from a C-style struct to a proper class with encapsulation and clean modular design.
We also observe what happens when we exceed the internal stack buffer.
*/

int main() {
    Stack s;

    // Push 100 elements — buffer will overflow after 80
    for (int i = 0; i < 100; ++i) {
        cout << "Pushing " << i*i << " into stack" << endl;
        s.push(i*i);
    }

    cout << "Number of items in stack: " << s.nitems() << endl;

    // Inspect current contents
    s.inspect();

    // Pop all elements
    while (!s.empty()) {
        double val = s.pop();
        cout << "Popped value: " << val << endl;
    }

    return 0;
}
