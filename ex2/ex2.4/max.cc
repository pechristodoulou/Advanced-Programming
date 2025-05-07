#include "max.hh"

namespace mylib {

    // Find maximum between two integers
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Find maximum between two doubles
    double max(double a, double b) {
        return (a > b) ? a : b;
    }

    // Find maximum in an array of integers
    int max(int arr[], int n) {
        int m = arr[0];
        for (int i = 1; i < n; ++i)
            if (arr[i] > m)
                m = arr[i];
        return m;
    }

}
