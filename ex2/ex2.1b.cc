#include <iostream>
#include <cstring>
using namespace std;

/*
h) We can't use the const char* to compare the strings because 
they are pointers and their values are just addresses.
i) was done from the start since pointers were passed-by-value.
Without all the added symbols and with the pointer method we saw in 
part a) the pointers there are erros since the *a activates the pointer
and they are const so the array can't change.
*/
// Declaration
void sort(int n, const char* words[]);
void order(const char*& a, const char*& b);
// void order_ptr(int* a, int* b);


int main() {
    // int len = 10;
    const char* words[10] = {  // not char* strings but array
        "apple", "banana", "grape", "cherry", "mango",
        "peach", "lemon", "orange", "melon", "kiwi"
    };

    // cout << *words[0] << endl;
    // Check of strcmp function
    // cout << strcmp(words[0], words[0]) << endl;  // 0 same words, 1 a > b, -1 a < b
    
    sort(sizeof(words)/sizeof(words[0]), words); // calling function

    // Printing
    cout << "Sorted words: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << words[i];
        if (i == 9) break; 
        cout << ", ";
    }
    cout << "\n";
    return 0;
}


// Definition
void sort(int n, const char* words[]){

    for (int i=0; i<n-1; i++){  
        for (int j=0; j<n-1-i; j++){  
            order(words[j+1], words[j]); //  swap A[j] with A[j+1]
            // order_ptr(&array[j+1], &array[j]);  // e) implementation
        }
    }
}

// Order swapping for 2 string literals in pointer array
void order(const char*& a, const char*& b){  
    if (strcmp(a, b) < 0){
        const char* tmp = a;
        a = b;
        b = tmp;
    } 
}

