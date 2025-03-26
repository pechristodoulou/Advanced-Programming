#include <iostream>
#include "CaloCell.hh"
#include "Point.hh"
#include "CaloGrid.hh"
#include "Calorimeter.hh"
using namespace std;

/*
Why are we doing this?
→ To create a simple building block of the calorimeter — a cell that holds energy and an ID.
→ This lets us test object construction, access, and modification.
*/

int main() {
    // CaloCell cell(12.5, 42);

    // cout << "Initial energy: " << cell.getEnergy() << endl;
    // cout << "Initial ID: " << cell.getID() << endl;

    // cell.setEnergy(99.9);
    // cell.setID(100);

    // cout << "Updated energy: " << cell.getEnergy() << endl;
    // cout << "Updated ID: " << cell.getID() << endl;

    // Point p;

    // cout << "Initial position: (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")" << endl;

    // p.setX(1.1);
    // p.setY(2.2);
    // p.setZ(3.3);

    // cout << "After individual set: (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")" << endl;

    // p.setXYZ(4.4, 5.5, 6.6);
    // cout << "After setXYZ(): (" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")" << endl;

    // ---------------------------------------
    // CaloGrid grid(3, 2);

    // // Set values at some positions
    // CaloCell* c = grid.cell(1, 0);
    // if (c) {
    //     c->setEnergy(42.0);
    //     c->setID(101);
    // }

    // // Test out-of-bounds
    // if (grid.cell(-1, 0) == nullptr)
    //     cout << "Correctly caught out-of-bounds (negative x)" << endl;

    // if (grid.cell(5, 1) == nullptr)
    //     cout << "Correctly caught out-of-bounds (too large x)" << endl;

    // // Copy grid and check value
    // CaloGrid copy = grid;
    // const CaloCell* cc = copy.cell(1, 0);
    // if (cc)
    //     cout << "Copied cell at (1,0): energy = " << cc->getEnergy() << ", ID = " << cc->getID() << endl;
    // --------------------------------
    Calorimeter cal(4, 3, Point(1.0, 2.0, 3.0));

    cout << "Calorimeter position: ("
         << cal.position().getX() << ", "
         << cal.position().getY() << ", "
         << cal.position().getZ() << ")" << endl;

    CaloCell* c = cal.grid().cell(2, 1);
    if (c) {
        c->setEnergy(77.7);
        c->setID(999);
    }

    const CaloCell* c2 = cal.grid().cell(2, 1);
    if (c2) {
        cout << "Cell at (2,1): energy = " << c2->getEnergy()
             << ", ID = " << c2->getID() << endl;
    }

    return 0;
}
