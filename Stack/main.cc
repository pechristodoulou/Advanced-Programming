#include <iostream>
#include "Stack.h"
using namespace std;

/*
Why are we doing this?
→ To structure Stack as a proper class.
→ We're testing pushing, popping, and inspecting with a fixed buffer size.
*/

int main() {
    Stack s;

    for (int i = 0; i < 10; ++i)
        s.push(i * i);

    s.inspect();

    return 0;
}
