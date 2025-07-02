#include <iostream>
#include <cstring>
#include "String.hh"
using namespace std;

/*
Why are we doing this?
→ To make a custom String class behave like a real string,
   supporting assignment, concatenation, and implicit conversion to const char*.

i) Can you add a string literal to a String using operator+(), as in:

→ Yes, this works because String has a constructor that takes const char*,
and it is not marked 'explicit'. This allows implicit conversion from const char*
to String, so "Blah" is automatically turned into a temporary String object.
That temporary is then passed to operator+= or operator+.
*/

int main() {
    String a("Hello");
    String b("World");

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    a = b;
    cout << "After a = b: " << a << endl;

    String c("C++");
    String d("Rocks");

    String e = c + d;
    cout << "c + d: " << e << endl;

    c += d;
    cout << "After c += d: " << c << endl;

    cout << "Length of c: " << c.length() << endl;
    cout << "Using strlen(c): " << strlen(c) << endl;

    return 0;
}
