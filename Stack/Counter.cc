#include <iostream>
using namespace std;

/*
Why are we doing this?
→ To track how many Counter objects exist at any time, using static data.
→ This shows how static members behave across different instances.
*/

class Counter {
public:
    Counter() {
        ++count;
        cout << "Counter created. Now " << count << " alive." << endl;
    }

    ~Counter() {
        --count;
        cout << "Counter destroyed. Now " << count << " alive." << endl;
    }

    static int getCounter() {
        return count;
    }

private:
    static int count; // Shared between all instances
};

// Must define the static member outside the class!
int Counter::count = 0;

int main() {
    cout << "Initial count: " << Counter::getCounter() << endl;

    Counter a;
    Counter b;
    cout << "There are now " << Counter::getCounter() << " Counter objects." << endl;

    if (true) {
        Counter c;
        cout << "And now: " << Counter::getCounter() << " Counter objects." << endl;
    } // c goes out of scope here, destructor is called

    cout << "After block ends: " << Counter::getCounter() << " Counter objects." << endl;

    return 0;
}
