#include <iostream>
#include <climits>  // Required for INT_MAX and INT_MIN
using namespace std;

// Function to reverse digits of an integer
int reverse(int x) {
    int ans = 0;           // Will hold the final reversed number
    int rem = 0;           // rem (remainder) will store the last digit in each step
    bool isNegative = false;  // Flag to mark if number is negative

    // Handle edge case for minimum integer value
    if (x == INT_MIN) {
        return 0; // Cannot convert INT_MIN to positive safely
    }

    // If number is negative, mark it and convert to positive
    if (x < 0) {
        isNegative = true;
        x = -x;
    }

    // Loop to reverse the digits of the number
    while (x > 0) {
        rem = x % 10;  // Get the last digit of the number

        // Check for integer overflow before multiplying by 10
        if (ans > (INT_MAX - rem) / 10) {
            return 0;  // Overflow will occur, return 0 safely
        }

        ans = ans * 10 + rem;  // Add digit to reversed number
        x = x / 10;            // Remove the last digit
    }

    // Return the result, correcting the sign if needed
    return isNegative ? -ans : ans;
}

int setKthBit(int n, int k) {
    int mask = 1 << k;  // Create a mask with the k-th bit set
    int ans = n | mask;   // Set the k-th bit in n
    return ans;  // Return the modified number
}

int main() {
    int num;
    cout << "Enter an integer to reverse: ";
    cin >> num;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int reversed = reverse(num);
    cout << "Reversed number: " << reversed << endl;

    int maskedNumber = setKthBit(n, 1);
    cout << "Number after setting the 2nd bit: " << maskedNumber << endl;

    return 0;
}
