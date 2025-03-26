#include <iostream>
#include "Array.hh"
using namespace std;

/*
Why are we doing this?
→ To build a safe, flexible generic container that behaves like a resizable array.
→ We handle memory ourselves and make it usable for any type T.
*/

int main() {
    // Integer test
    Array<int> intArr(3, -1);
    intArr[0] = 10;
    intArr[1] = 20;
    intArr[4] = 40; // triggers auto-resize

    cout << "Integer array: ";
    for (int i = 0; i < intArr.size(); ++i)
        cout << intArr[i] << " ";
    cout << endl;

    // String test
    Array<const char*> strArr(2, "blank");
    strArr[0] = "apple";
    strArr[1] = "banana";
    strArr[3] = "kiwi";

    cout << "String array: ";
    for (int i = 0; i < strArr.size(); ++i)
        cout << strArr[i] << " ";
    cout << endl;

    return 0;
}
