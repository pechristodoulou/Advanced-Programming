#include <iostream>
#include <list>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// #define USE_LIST // comment this line to use vector

#ifdef USE_LIST
#define Container list<int>
#else
#define Container vector<int>
#endif

int main() {
    const int N = 100000;

    Container data;
    for (int i = 0; i < N; ++i)
        data.push_back(i);

    auto start = high_resolution_clock::now();

    typename Container::iterator it = data.begin();
    int count = 0;

    while (it != data.end()) {
        ++count;
        if (count == 3) {
            it = data.erase(it);
            count = 0;
        } else {
            ++it;
        }
    }
}