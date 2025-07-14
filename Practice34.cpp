#include <iostream>
#include <string>
#include <algorithm> // For reverse()
using namespace std;

/**
 * Function: calcSum
 * -----------------
 * Adds two large numbers represented as arrays of digits.
 *
 * Parameters:
 *   a[] : First number stored as an array (one digit per element, most significant digit first)
 *   n   : Number of digits in the first number
 *   b[] : Second number stored as an array (one digit per element, most significant digit first)
 *   m   : Number of digits in the second number
 *
 * Returns:
 *   A string representing the sum of the two numbers
 */
string calcSum(int *a, int n, int *b, int m) {
    int carry = 0;               // Carry for digit addition
    string ans;                  // Result will be stored in reverse

    int i = n - 1;               // Start from the last digit of array a
    int j = m - 1;               // Start from the last digit of array b

    // Step 1: Add digits while both arrays have elements
    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + carry;
        int digit = sum % 10;    // Get the last digit of sum
        carry = sum / 10;        // Calculate the carry for next iteration
        ans.push_back(digit + '0'); // Convert digit to character and append to result
        i--;
        j--;
    }

    // Step 2: If digits remain in array 'a'
    while (i >= 0) {
        int sum = a[i] + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans.push_back(digit + '0');
        i--;
    }

    // Step 3: If digits remain in array 'b'
    while (j >= 0) {
        int sum = b[j] + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ans.push_back(digit + '0');
        j--;
    }

    // Step 4: If there's still carry left after all digits are processed
    if (carry) {
        ans.push_back(carry + '0');
    }

    // Step 5: Remove any trailing zeros (in case of leading zeros in input)
    while (ans.size() > 1 && ans.back() == '0') {
        ans.pop_back(); // Remove last character (which is '0')
    }

    // Step 6: Reverse the result to correct the digit order
    reverse(ans.begin(), ans.end());

    return ans; // Return the final result string
}

/**
 * Main function: Demonstrates the usage of calcSum.
 * Inputs are hard-coded for demonstration. You can modify these as needed.
 */
int main() {
    // Input arrays (each digit is an element)
    // Represents number 090035 (interpreted as 90035)
    int a[] = {0, 9, 0, 0, 3, 5};

    // Represents number 227
    int b[] = {2, 2, 7};

    // Calculate sizes of both arrays
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    // Call the addition function
    string result = calcSum(a, n, b, m);

    // Display the result
    cout << "The sum is: " << result << endl; // Expected output: 90262

    return 0; // End of program
}
