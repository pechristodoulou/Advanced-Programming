#include <iostream>
using namespace std;
/*
e) Line 33) is the call of the reimplemented function order --> order_ptr
with pointers instead of references. The reference version is much better in notation
to avoid extra symbols.
*/
// Declaration
void sort(int n, int array[]);
void order(int& a, int& b);
void order_ptr(int* a, int* b);


int main() {
    int len = 10;
    int num_arr[len] = {0, 5, 7, 8, 3, 6, 2, 2, 4, 9};
    sort(sizeof(num_arr)/sizeof(int), num_arr);
    cout << "Sorted elements: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << num_arr[i];
        if (i == 9) break; 
        cout << ", ";
    }
    cout << "\n";
    return 0;
}

// Definition
void sort(int n, int array[]){

    // times run, no swapping at all
    // n-1 since last is auto sorted then
    for (int i=0; i<n-1; i++){  
        for (int j=0; j<n-1-i; j++){  // last elements of i is sorted
                                      // avoiding unnecessary comparisons
            order(array[j+1], array[j]); //  swap A[j] with A[j+1]
            // order_ptr(&array[j+1], &array[j]);  // e) implementation
        }
    }
}

void order(int& a, int& b){  
    if (b > a){
        int tmp = a;
        a = b;
        b = tmp;
    } 
}

void order_ptr(int* a, int* b){
    if (*b > *a){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
