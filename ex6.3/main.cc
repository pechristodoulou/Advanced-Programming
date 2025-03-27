#include "Stack.hh"
using namespace std;

/*
Why are we doing this?
→ To make Stack generic and use the smart memory management from our Array<T>.
→ This reduces code duplication and increases flexibility.
*/

int main() {
    Stack<int> s1;
    for (int i = 0; i < 5; ++i)
        s1.push(i * i);

    cout << "Integer stack:\n";
    s1.inspect();

    Stack<const char*> s2;
    s2.push("apple");
    s2.push("banana");
    s2.push("kiwi");

    cout << "\nString stack:\n";
    s2.inspect();

    return 0;
}
