#include "Telephone.hh"

/*
f) We found that Dialer had a fixed-size array, and its copy constructor wasn't handling dynamic memory.
   So we replaced it with a pointer and implemented proper deep copying.

g) Dialer now allocates Button[12] dynamically using new[] and deletes it in the destructor.

h) We verified that all constructors and destructors are called in the correct order, including copy constructors.
   No memory leaks or shared resources remain.
*/

int main() {
    std::cout << "Creating t1\n";
    Telephone t1;

    std::cout << "\nCopying t1 to t2\n";
    Telephone t2 = t1;

    std::cout << "\nEnd of program (destructors follow)\n";
    return 0;
}
