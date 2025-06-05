#include <iostream>
#include <climits>  // Required for INT_MAX and INT_MIN
using namespace std;

// ------------------------------------------
// Function to reverse the digits of an integer
// ------------------------------------------
int reverse(int x) {
    int ans = 0;            // Will store the reversed number
    int rem = 0;            // Will hold the last digit in each iteration
    bool isNegative = false; // Track if the original number is negative

    // Handle extreme case where x is INT_MIN (-2^31)
    // Since abs(INT_MIN) > INT_MAX, negating it causes overflow
    if (x == INT_MIN) {
        return 0;
    }

    // If the number is negative, make it positive for reversal logic
    if (x < 0) {
        isNegative = true;
        x = -x;
    }

    // Reverse digits using remainder and division
    while (x > 0) {
        rem = x % 10;  // Extract the last digit

        // Before multiplying ans by 10, check if it would overflow
        if (ans > (INT_MAX - rem) / 10) {
            return 0;  // Return 0 if it overflows
        }

        ans = ans * 10 + rem; // Append the digit
        x = x / 10;           // Remove the last digit
    }

    // If original number was negative, make result negative
    return isNegative ? -ans : ans;
}

// ------------------------------------------
// Function to set the k-th bit (0-based index) of an integer
// ------------------------------------------
int setKthBit(int n, int k) {
    int mask = 1 << k;   // Shift 1 to the left by k positions (only k-th bit is 1)
    int ans = n | mask;  // Use bitwise OR to set the k-th bit
    return ans;
}

// ------------------------------------------
// Main function
// ------------------------------------------
int main() {
    int num;
    cout << "Enter an integer to reverse: ";
    cin >> num;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Call reverse function
    int reversed = reverse(num);
    cout << "Reversed number: " << reversed << endl;

    // Call bit setter function and set 2nd bit (i.e., k=1)
    int maskedNumber = setKthBit(n, 1);
    cout << "Number after setting the 2nd bit: " << maskedNumber << endl;

    return 0;
}
