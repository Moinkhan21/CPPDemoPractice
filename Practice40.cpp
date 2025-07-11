#include <iostream>
using namespace std;

// ==================================================================
// Function: findSqrt
// Purpose : Finds the integer part (floor) of the square root of a number
// Approach: Uses Binary Search to efficiently find the square root
// ==================================================================
int findSqrt(int n) {
    int target = n;
    int s = 0;          // Start of search range
    int e = n;          // End of search range
    int mid = s + (e - s) / 2;  // Midpoint
    int ans = -1;       // Store the answer (default -1 for safety)

    // Binary search loop
    while (s <= e) {
        // If mid squared is exactly the number, return mid
        if (mid * mid == target) {
            return mid;
        }

        // If mid squared is greater than target, move to left half
        if (mid * mid > target) {
            e = mid - 1;
        }
        // If mid squared is less than target, store answer and move to right half
        else {
            ans = mid;         // Update answer to current mid
            s = mid + 1;       // Search in the right half
        }

        // Recalculate mid after updating start or end
        mid = s + (e - s) / 2;
    }

    return ans;  // Return the floor value of square root
}

// ==================================================================
// Main Function
// Purpose: Accepts input number, finds integer & floating sqrt
// ==================================================================
int main() {
    int n;

    // Prompt user to enter the number
    cout << "Enter the number: ";
    cin >> n;

    // Step 1: Find integer part of square root
    int ans = findSqrt(n);
    cout << "Integer part of sqrt is: " << ans << endl;

    // Step 2: Get precision input from user
    int precision;
    cout << "Enter the number of floating digits in precision: ";
    cin >> precision;

    // Step 3: Initialize step for decimal precision (starting from 0.1)
    double step = 0.1;
    double finalAns = ans; // Start with the integer part

    // Loop for the number of digits of precision required
    for (int i = 0; i < precision; i++) {
        // Try incrementing in steps until square exceeds the number
        for (double j = finalAns; j * j < n; j += step) {
            finalAns = j; // Update the final answer
        }

        // Reduce the step size to go to next decimal place
        step /= 10;
    }

    // Print the final square root with floating point precision
    cout << "Final square root (with precision): " << finalAns << endl;

    return 0; // Indicate successful execution
}
