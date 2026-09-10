#include "Telephone.hh"

/*
Telephone
├── Cable
├── Housing
│   ├── Chassis
│   └── Shell
├── Dialer
│   └── Button[12]
└── Handset
    ├── Mouthpiece
    ├── Earpiece
    └── Cable

b) The code doesn't compile at first because of missing include guards.
   Example: Cable.hh is included multiple times due to lack of #ifndef/#define.
   Fix: Add include guards to Cable.hh and any other files missing them.

c) Constructor and Destructor order:
   - Constructors:
     First, base class constructors and then members (in the order declared in the class!),
     and finally the body of the constructor.
   - Destructors:
     Opposite of construction order: last constructed gets destroyed first.

d) We create a second Telephone using the copy constructor.
   Observation: Most constructors that are called are *default*, not *copy* constructors.
   That means the default copy constructor of Telephone is doing a **shallow copy**.

e) So no, the copy constructor behavior is not fully correct.
Each subobject's copy constructor should be called — but many aren't.
This hints that we haven't implemented deep copy constructors for member objects yet.

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
