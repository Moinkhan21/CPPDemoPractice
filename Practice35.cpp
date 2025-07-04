#include <iostream>
#include <vector>
#include <algorithm> // For using reverse() function
using namespace std;

/**
 * Function to multiply a large number represented as a vector of digits (least significant digit first)
 * with a single integer multiplier. It returns the result as a new vector.
 *
 * @param num - The large number stored in reverse order (least significant digit at index 0)
 * @param multiplier - The integer to multiply with
 * @return A new vector storing the result in reverse order
 */
vector<int> multiplyVector(const vector<int>& num, int multiplier) {
    vector<int> result; // Vector to store the result
    int carry = 0;      // Carry for multiplication

    // Traverse each digit of the large number
    for (int digit : num) {
        int product = digit * multiplier + carry; // Multiply and add carry
        result.push_back(product % 10);           // Store the last digit of product
        carry = product / 10;                     // Update carry with the remaining part
    }

    // Handle any remaining carry
    while (carry) {
        result.push_back(carry % 10); // Store each digit of carry
        carry /= 10;
    }

    return result; // Return the final result vector (still in reverse order)
}

/**
 * Function to compute the factorial of a number using digit-by-digit vector multiplication.
 * It handles large results by storing each digit in a vector.
 *
 * @param n - The number to compute factorial of
 * @return A vector of digits representing the factorial in correct order
 */
vector<int> computeFactorial(int n) {
    vector<int> result = {1}; // Initialize result as 1 (0! = 1, 1! = 1)

    // Multiply result by each number from 2 to n
    for (int i = 2; i <= n; ++i) {
        result = multiplyVector(result, i); // Reuse multiply logic
    }

    // Final result is in reverse order, so reverse it to get correct number
    reverse(result.begin(), result.end());
    return result; // Return the result vector with most significant digit first
}

/**
 * Utility function to print the number represented by a vector.
 * The vector contains each digit of the number in correct order.
 *
 * @param number - The vector representing the number to print
 */
void printNumber(const vector<int>& number) {
    for (int digit : number) {
        cout << digit; // Print each digit without space
    }
    cout << endl; // Move to next line after printing the number
}

// ---------- MAIN FUNCTION ----------
int main() {
    int n;

    // Prompt the user for a number
    cout << "Enter a number to compute factorial: ";
    cin >> n;

    // Compute the factorial using vector-based logic
    vector<int> factorialResult = computeFactorial(n);

    // Display the result
    cout << "Factorial of " << n << " is: ";
    printNumber(factorialResult);

    return 0; // Successful program termination
}
