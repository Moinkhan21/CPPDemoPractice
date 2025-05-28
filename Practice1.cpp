#include <iostream>
#include <string>
using namespace std;

/*
    Method 1: Multiply each bit by power of 2, starting from rightmost bit.
    We process the string from right to left (LSB to MSB).
*/
int binaryToDecimalMethod1(const string& binaryStr) {
    int decimal = 0;
    int base = 1; // 2^0

    // Loop from last character to first (LSB to MSB)
    for (int i = binaryStr.length() - 1; i >= 0; i--) {
        int bit = binaryStr[i] - '0';    // Convert char to int (e.g., '1' -> 1)
        decimal += bit * base;           // Add bit * 2^position to decimal
        base *= 2;                       // Update base to next power of 2
    }

    return decimal;
}

/*
    Method 2: Bitwise shift method.
    We process the string from left to right (MSB to LSB),
    simulating: decimal = (decimal << 1) | current_bit
*/
int binaryToDecimalMethod2(const string& binaryStr) {
    int decimal = 0;

    for (char ch : binaryStr) {
        int bit = ch - '0';                 // Convert char to int (e.g., '1' -> 1)
        decimal = (decimal << 1) | bit;     // Shift left and add current bit
    }

    return decimal;
}

int main() {
    string binaryInput;

    cout << "Enter a binary number (e.g., 1011): ";
    cin >> binaryInput;   // Accept input as string to preserve correct bit order

    int decimal1 = binaryToDecimalMethod1(binaryInput);
    int decimal2 = binaryToDecimalMethod2(binaryInput);

    cout << "Decimal (using multiplication method): " << decimal1 << endl;
    cout << "Decimal (using shift method): " << decimal2 << endl;

    return 0;
}
