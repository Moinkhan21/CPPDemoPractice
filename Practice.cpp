#include <iostream>
using namespace std;

// Method 1: Convert decimal to binary using division method
int decimalToBinaryMethod1(int n) {
    int binaryno = 0;      // Stores the final binary number
    int place = 1;         // Place value (1, 10, 100...) for constructing the binary number

    while(n > 0) {
        int bit = n % 2;               // Get the last binary bit (0 or 1)
        binaryno += bit * place;       // Add the bit at the correct decimal place
        place *= 10;                   // Increase the place value (1 -> 10 -> 100 ...)
        n = n / 2;                     // Divide the number by 2 for the next bit
    }
    return binaryno;  // Return the final binary number in decimal format
}

// Method 2: Convert decimal to binary using bitwise method
int decimalToBinaryMethod2(int n) {
    int binaryno = 0;      // Stores the final binary number
    int place = 1;         // Place value (1, 10, 100...) for constructing the binary number

    while(n > 0) {
        int bit = (n & 1);             // Get the last binary bit using bitwise AND
        binaryno += bit * place;       // Add the bit at the correct decimal place
        place *= 10;                   // Increase the place value (1 -> 10 -> 100 ...)
        n = n >> 1;                    // Right shift to divide by 2
    }
    return binaryno;  // Return the final binary number in decimal format
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    // Store binary results using both methods
    int binary1 = decimalToBinaryMethod1(n);
    int binary2 = decimalToBinaryMethod2(n);

    // Print both binary representations
    cout << "Binary representation of " << n << " using division method is: " << binary1 << endl;
    cout << "Binary representation of " << n << " using bitwise method is: " << binary2 << endl;

    return 0;
}
