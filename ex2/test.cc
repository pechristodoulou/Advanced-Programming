#include <iostream>
using namespace std;

// above must be a parameter otherwise it wont work since 
// arrays become a pointer in a function

// void square(int len, int array[]);

// int main() {
//     int array[3] = {0, 1, 2};
//     int len = sizeof(array)/sizeof(int); 
        
//     // cout << len << endl;
//     square(len, array);
//     for (int i=0; i < len; ++i){
//         cout << array[i] << endl;
//     }
    
//     return 0;
// }

// void square(int len, int array[]){
//     while (--len >= 0) {   // or (len-- > 0)
//         array[len] *= array[len];
//     }
// }
// namespace foo {
//     int zap = 0 ;
//     namespace bar {
//     int foobar = 0 ; 
//     }
// }
//     int main() {
//     cout << foo::zap << endl ;
//     cout << foo::bar::foobar << endl ;
//     }
