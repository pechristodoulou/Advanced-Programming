#include <iostream>
#include "min.hh"
#include "max.hh"
using namespace std;

/*
f) What happens if we define our own int min(int, int)?
   → It causes ambiguity if we also bring mylib::min into global scope.
   → Solution: Don't 'using namespace mylib'; call mylib::min() explicitly.

h) We now use both the local min() and the library one by keeping their namespaces distinct.

Compilation Instructions:
1. Compile the object files:
   g++ -c min.cc -o min.o
   g++ -c max.cc -o max.o

2. Create the library:
   ar rcs libMinMax.a min.o max.o

3. Compile the main program:
   g++ ex2.4.cc -L. -lMinMax -o ex2.4

4. Run the program:
   ./ex2.4
*/

int min(int a, int b) {
    return a + b; // Dummy version to test override
}

int main() {
    int a = 3, b = 7;
    int arr[5] = {4, 2, 8, 1, 5};
    double x = 2.5, y = 4.1;

    cout << "mylib::min(a, b): " << mylib::min(a, b) << endl;
    cout << "mylib::max(a, b): " << mylib::max(a, b) << endl;

    cout << "mylib::min(x, y): " << mylib::min(x, y) << endl;
    cout << "mylib::max(x, y): " << mylib::max(x, y) << endl;

    cout << "mylib::min(arr, 5): " << mylib::min(arr, 5) << endl;
    cout << "mylib::max(arr, 5): " << mylib::max(arr, 5) << endl;

    cout << "local min (a + b): " << min(a, b) << endl;
    return 0;
}
