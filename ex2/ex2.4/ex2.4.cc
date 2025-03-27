#include <iostream>
#include "min.hh"
#include "max.hh"
using namespace std;

/*
f) What happens if we define our own int min(int, int)?
   → It causes ambiguity if we also bring mylib::min into global scope.
   → Solution: Don't 'using namespace mylib'; call mylib::min() explicitly.

h) We now use both the local min() and the library one by keeping their namespaces distinct.
*/

int min(int a, int b) {
    return a + b; // Dummy version to test override
}

int main() {
    int a = 3, b = 7;
    cout << "mylib::min(a, b): " << mylib::min(a, b) << endl;
    cout << "mylib::max(a, b): " << mylib::max(a, b) << endl;
    cout << "local min (a + b): " << min(a, b) << endl;
    return 0;
}
