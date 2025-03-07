#include <iostream>

using namespace std;

void MemoryLeak() {
    while (true) {
        int* leak_arr = new int[100000]; // 4 MB leak it is immediate
        cout << "Allocated memory" << endl;
    }
}

int main() {
    MemoryLeak(); 
}

/*
From the top commnand we can see that memory usage %
increases as well as CPU%.
The program terminates after the system runs out of 
memory.
Message: Instance of 'std::bad_alloc', Aborted 
With 4 MB leak it is immediate.
*/