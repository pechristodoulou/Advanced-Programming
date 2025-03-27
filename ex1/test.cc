// First program in this 
#include <iostream>
using namespace std;

int main() {
    // std::cout << "Hello World!" << std::endl;
    // return 0;

    // -------------------
    // int j;
    // j = 1;
    // auto m = j + 2;
    // const float pi = 3.1415 ; // constants read only
    // std::cout << "pi = " << pi << m << std::endl;

    // --------------------------
    // const int n=3;
    // float x[n];
    // float y[2][2] = {0.0, 1.0, 2.0, 3.0};
    // cout << y << endl;

    // ----Pointers--------
    // int x=3, y=4;
    // int* px;  // also int* px = &x
    // px = &x;
    // cout << *px << endl;
    // *px = 5;
    // cout << *px << endl;

    // ----Pointers with Arrays---
    // int a[3] = {1, 2, 3};
    // int* pa = &a[0];
    // cout << *(pa+1) << endl;
    // cout << a[1] << endl;

    // -----Char strings------
    // const char* blah = "querty";
    // int strlen(const char* blah);

    // ----Operators-------
    // int x, y, z;
    // x = y = z = 5;
    // cout << ++x << endl;  // prints 6

    // cout << x + y / z << endl; // prints 6 again
    // cout << (x == z) << endl;


    // Conversion operators/casts
    // static_cast<int>(variable)
    // float f = 3.1;
    // const float& g = f;
    // float& h = const_cast<float&>(g);
    // cout << h << endl;
    // h = 5.3; // can be changed not a const
    // const float f = 3.1 ;
    // int i = static_cast<int>( const_cast<float>(f)); # issue float, no issue in lecture
    
    // ---If/else control flow---
    // int h = 5.3, f = 3.1 ;
    // if (h > f) {
    //     cout << "h larger" << endl;
    // } else if  (h < f) {
    //     cout << "f larger" << endl;
    // } else {
    //     cout << "h f equal" << endl;
    // }

    // ----Loops control flow-----
    // int i,j;
    // for (i=0,j=0 ; i<3 ; i++,j+=2) {
    // // execute with i=0,j=0, i=1,j=2, i=2,j=4
    // }
    // break and continue are the same as in python for
    //  innermost loop

    // ----Switch-----
//     int len;
//     char str[len];
//     enum color { red=1, green=2, blue=4 };
//     color paint = getcolor(); // function not programmed that gives color
//     switch (paint) {
//         case red:
//         case green:
//         case blue:
//             cout << "primary color" << endl;
//             break ;
//     case red+green:
//         cout << "yellow" << endl ; 
//         break ;
//     case red+blue:
//         cout << "magenta" << endl ; 
//         break;
//     case blue+green:
//         cout << "cyan" << endl ; 
//         break ;
//     default:
//         cout << "white" << endl ;
//         break ;
//     }
   
}   