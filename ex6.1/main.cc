#include <iostream>
#include <cstring>
using namespace std;

/*
Why are we doing this?
→ To write sorting logic that works for any type using C++ templates.
→ Specializing for char* shows how to handle non-trivial comparisons like strings.
*/

// Template order
template <class T>
void order(T& a, T& b) {
    if (b < a) {
        T tmp = a;
        a = b;
        b = tmp;
    }
}

// Template sort
template <class T>
void sort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            order(arr[j], arr[j + 1]);
}

// Template display
template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Specialize order() for char*
template <>
void order<const char*>(const char*& a, const char*& b) {
    if (strcmp(b, a) < 0) {
        const char* tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {
    int nums[5] = {5, 2, 8, 1, 3};
    cout << "Original int array: ";
    display(nums, 5);
    sort(nums, 5);
    cout << "Sorted int array: ";
    display(nums, 5);

    float floats[5] = {2.5, 0.1, 3.3, 1.1, -5.6};
    cout << "\nOriginal float array: ";
    display(floats, 5);
    sort(floats, 5);
    cout << "Sorted float array: ";
    display(floats, 5);

    const char* words[5] = {"zebra", "apple", "lemon", "banana", "kiwi"};
    cout << "\nOriginal string array: ";
    display(words, 5);
    sort(words, 5);
    cout << "Sorted string array: ";
    display(words, 5);

    return 0;
}
