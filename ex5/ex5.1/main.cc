#include <iostream>
#include <iomanip>
using namespace std;

/*
a–i) Formatting integers and floating points with iostream manipulators.
→ This teaches clean output formatting, useful for both user-facing programs and debugging.
*/

int main() {
    int num;
    cout << "Enter an integer (decimal): ";
    cin >> num;

    // b) Display in decimal, hex, octal
    cout << "Decimal: " << dec << num << endl;
    cout << "Hex:     " << hex << num << endl;
    cout << "Octal:   " << oct << num << endl;

    // c) Read hex instead
    cout << "\nEnter a hex number (e.g. 1f): ";
    cin >> hex >> num;
    cout << "You entered (in decimal): " << dec << num << endl;

    // d) Floating point formatting
    float f1, f2, f3;
    cout << "\nEnter 3 float values: ";
    cin >> f1 >> f2 >> f3;

    // e) Scientific notation
    cout << "\nScientific format:\n";
    cout << scientific << f1 << " " << f2 << " " << f3 << endl;

    // f) Field width with setw()
    cout << "\nScientific with field width 20:\n";
    cout << setw(20) << f1 << setw(20) << f2 << setw(20) << f3 << endl;

    // g) Fixed precision, 3 decimals, left aligned
    cout << "\nFixed precision, left-aligned:\n";
    cout << fixed << setprecision(3) << left;
    cout << setw(20) << f1 << setw(20) << f2 << setw(20) << f3 << endl;

    // h) Print headers
    cout << "\n" << setw(20) << "ValueA" << setw(20) << "ValueB" << setw(20) << "ValueC" << endl;

    // i) Print dashed separator with correct single dash
    cout << setfill('-') << setw(60) << "" << endl;
    cout << setfill(' '); // Reset to default fill

    // Reprint numbers under the header
    cout << fixed << setprecision(3) << left;
    cout << setw(20) << f1 << setw(20) << f2 << setw(20) << f3 << endl;

    return 0;
}
