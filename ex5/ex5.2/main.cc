#include <iostream>
#include <fstream>
using namespace std;

/*
Why are we doing this?
→ To practise file reading with ifstream, EOF detection, and error checking.
→ Also to practice breaking out of a loop with a custom stopping condition.
*/

int main() {
    ifstream infile("data1.txt");

    // b) Check if file opened
    if (!infile) {
        cout << "Error: could not open file 'data1.txt'" << endl;
        return 1;
    }

    int val;
    // c) Read and print until EOF or until value == 0
    cout << "Reading values from file:\n";
    while (infile >> val) {
        if (val == 0) {
            cout << "Stopping (value is 0)" << endl;
            break;
        }
        cout << "Read value: " << val << endl;
    }

    infile.close();
    return 0;
}
