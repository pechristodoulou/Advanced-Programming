#include <iostream>
#include "Stack.h"
using namespace std;

/*
Why are we doing this?
→ To make sure copying a Stack makes a real, independent copy with its own memory.
→ Without a proper copy constructor, two Stacks would share the same buffer (bad!).
*/

int main() {
    Stack s;

    for (int i = 0; i < 10; ++i)
        s.push(i * i);

    cout << "Original stack (s):" << endl;
    s.inspect();

    Stack sclone = s;  // Copy

    cout << "\nCopied stack (sclone):" << endl;
    sclone.inspect();

    cout << "\nPopping all items from original (s):" << endl;
    while (!s.empty()) {
        cout << "Popped from s: " << s.pop() << endl;
    }

    cout << "\nAfter emptying s, sclone should still be intact:" << endl;
    sclone.inspect();

    cout << "\nRefilling s with 5 new elements (100 * i):" << endl;
    for (int i = 0; i < 5; ++i)
        s.push(100 * i);

    cout << "\nNew contents of s:" << endl;
    s.inspect();

    cout << "\nsclone still holds the original copy:" << endl;
    sclone.inspect();

    return 0;
}
