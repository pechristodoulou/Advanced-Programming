#include <iostream>
#include <cstring>

using namespace std;

// Dictionary to understand:
// Unsigned Integer → A whole number (no negatives).
// Base-32 System → Uses 0-9 and A-V to represent numbers.
// To Convert to Base-32 → Divide repeatedly by 32 and store remainders.

// Base-32 lookup table (0-9, A-V)
const char base32_lookup[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

void convertToBase32(unsigned int num) {
    // Step (b) - Determine how many bits there are in an integer and required Base-32 digits
    int num_bits = sizeof(unsigned int) * 8; // Total bits in an unsigned int (4)
    int max_digits = (num_bits + 4) / 5;     // Maximum Base-32 digits needed = 7 
    // + 4 for proper rounding up (multiple of 5 bits to represent 31->35)

    // Step (c) - Allocate temporary storage array for Base-32 digits
    short int base32_digits[max_digits]; // gives decimal back
    int index = 0;

    // Step (d) & (e) - Extract Base-32 digits using bitwise AND and shift
    while (num > 0) {
        base32_digits[index++] = num & 31; // Extract rightmost 5 bits (mask with 0x1F: binary 0001 1111)
        num >>= 5; // Shift right by 5 bits, since base-32 has 5 bits per digit (2^5 =32)
    }

    // Edge case: if input was 0, manually add a single digit (Base-32 for 0 is '0')
    if (index == 0) {
        base32_digits[index++] = 0;
    }

    // Step (f) - Print the Base-32 representation
    cout << "Base-32 representation: ";
    
    // Step (g) - Print digits in reverse order (MSD to LSD)
    for (int i = index - 1; i >= 0; i--) {
        cout << base32_lookup[base32_digits[i]];
    }
    
    cout << endl;
    cout << "Decimal association: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << base32_digits[i] << ',';
    }
    cout << endl;
}

int main() {
    // Step (a) - Read an unsigned integer
    unsigned int num;
    cout << "Enter an unsigned integer: ";
    cin >> num;

    // Convert to Base-32
    convertToBase32(num);

    return 0;

// Index (base32_digits[i])	|Stored Value (Decimal)|Base-32 Digit
// 0	0	0
// 1	24	O
// 2	18	I
// 3	3	3
}
