#include "min.hh"

namespace mylib {

    // Find minimum between two integers
    int min(int a, int b) {
        return (a < b) ? a : b;
    }

    // Find minimum between two doubles
    double min(double a, double b) {
        return (a < b) ? a : b;
    }

    // Find minimum in an array of integers
    int min(int arr[], int n) {
        int m = arr[0];
        for (int i = 1; i < n; ++i)
            if (arr[i] < m)
                m = arr[i];
        return m;
    }

}
