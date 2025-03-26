#include <iostream>
#include "Stack.h"
using namespace std;

/*
Why are we doing this?
→ We're removing the fixed buffer limit by allowing the Stack to grow automatically.
This avoids errors when pushing more items than the initial size.
*/

int main() {
    Stack s(5); // Start small on purpose to test growing

    for (int i = 0; i < 20; ++i) {
        cout << "Pushing " << i*i << " into stack" << endl;
        s.push(i*i);
    }

    cout << "Number of items in stack: " << s.nitems() << endl;

    s.inspect();

    while (!s.empty()) {
        double val = s.pop();
        cout << "Popped value: " << val << endl;
    }

    return 0;
}
