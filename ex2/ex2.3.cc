#include <iostream>
using namespace std;

/*
a) Which print() functions are called?
   → In sub1(), it calls White::print due to the local 'using' declaration.
   → The recursive function is the global print().

b) Is 'using Black::print;' legal?
   → It is legal, but here it causes a name clash with our own global print(int),
     making calls to print(k) ambiguous. We avoid this by not using that line.
*/

namespace Black {
    void print(int k) { cout << "Black: " << k << endl; }
}

namespace White {
    void print(int k) { cout << "White: " << k << endl; }
}

// Removed: using Black::print;

void sub1() {
    using White::print; // This one is fine and local
    print(5); // calls White::print
}

void print(int k) {
    if (k > 0) {
        print(k - 1); // calls the global print() recursively
        cout << "Global: " << k << endl;
    }
}

int main() {
    sub1();

    cout << "Calling global recursive print:" << endl;
    print(3);

    cout << "Calling Black::print directly:" << endl;
    Black::print(42);

    return 0;
}
