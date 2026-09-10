#include "Stack.hh"
using namespace std;

/*
Why are we doing this?
→ We're replacing manual memory management with deque<T>,
   which handles resizing automatically and simplifies stack logic.
*/

int main() {
    Stack<string> s;
    s.push("apple");
    s.push("banana");
    s.push("kiwi");

    s.inspect();

    cout << "Popping: " << s.pop() << endl;
    cout << "Popping: " << s.pop() << endl;

    cout << "\nStack after popping:\n";
    s.inspect();

    return 0;
}
