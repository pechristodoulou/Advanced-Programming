#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

/*
a) Ill-defined print order:
→ Threads run independently, so output is interleaved or jumbled.

b) Runtime error:
→ Uncomment the unsafe pointer access to crash.

c) Demonstrate clear parallelism using sleep.

d) Pass object by reference using std::ref() — required to modify original.
*/

void printLoop(const string& name) {
    for (int i = 0; i < 5; ++i)
        cout << name << " says " << i << endl;
}

void printSleepy() {
    cout << "[Sleepy] Starting\n";
    this_thread::sleep_for(seconds(2));
    cout << "[Sleepy] Done sleeping\n";
}

void quickPrint() {
    this_thread::sleep_for(milliseconds(500));
    cout << "[Quick] I waited 0.5 seconds\n";
}

void modifyByRef(int& val) {
    this_thread::sleep_for(milliseconds(100));
    val += 10;
    cout << "[modifyByRef] Modified value inside thread: " << val << endl;
}

int main() {
    // a) Threads print in unpredictable order
    thread t1(printLoop, "A");
    thread t2(printLoop, "B");
    t1.join();
    t2.join();

    // b) Dangerous crash example (commented out)
    /*
    int* ptr = nullptr;
    thread crash([](int* p) { *p = 42; }, ptr); // causes segfault
    crash.join();
    */

    // c) Parallel actions
    thread t3(printSleepy);
    thread t4(quickPrint);
    t3.join();
    t4.join();

    // d) Pass by reference with std::ref
    int num = 100;
    thread t5(modifyByRef, ref(num)); // must use std::ref
    t5.join();
    cout << "[main] Final value of num: " << num << endl;

    return 0;
}
