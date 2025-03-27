#include <iostream>
using namespace std;

/* 
We overload min() for int, double, and int array inputs.
We also fix the double+int issue with extra overloads.
c) Why doesn't min(double, int) work by default?
→ Because both int and double can be promoted, the compiler gets confused and doesn’t know which version to choose.
*/

int min(int a, int b) {
    return (a < b) ? a : b;
}

double min(double a, double b) {
    return (a < b) ? a : b;
}

int min(int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] < m)
            m = arr[i];
    return m;
}

// Fix mixed-type overloads
double min(int a, double b) {
    return (a < b) ? a : b;
}

double min(double a, int b) {
    return (a < b) ? a : b;
}

int main() {
    cout << "min(int, int): " << min(4, 9) << endl;
    cout << "min(double, double): " << min(3.5, 2.1) << endl;

    int arr[] = {4, 2, 8, 1, 5};
    cout << "min(int[], n): " << min(arr, 5) << endl;

    cout << "min(int, double): " << min(3, 4.5) << endl;
    cout << "min(double, int): " << min(2.2, 5) << endl;

    return 0;
}
