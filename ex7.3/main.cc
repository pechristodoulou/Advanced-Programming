#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Switch between list and vector
#define USE_LIST

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

    typename Container::iterator it = data.begin();
    int count = 0;

    while (it != data.end()) {
        ++count;
        if (count == 3) {
            it = data.erase(it); // returns new iterator
            count = 0;
        } else {
            ++it;
        }
    }

    cout << "Done erasing every 3rd element." << endl;

    return 0;
}
