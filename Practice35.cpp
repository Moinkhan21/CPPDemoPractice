#include <iostream>
#include <vector>
#include <algorithm> // For reverse()
using namespace std;

/**
 * Multiply the current result vector with a given integer.
 * This function performs digit-wise multiplication and updates the result vector.
 */
vector<int> multiplyVector(const vector<int>& num, int multiplier) {
    vector<int> result;
    int carry = 0;

    for (int digit : num) {
        int product = digit * multiplier + carry;
        result.push_back(product % 10); // Store single digit
        carry = product / 10;           // Carry forward
    }

    // Add remaining carry as digits
    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

/**
 * Computes the factorial of a number using vector to store large digits.
 */
vector<int> computeFactorial(int n) {
    vector<int> result = {1}; // Start with 1

    for (int i = 2; i <= n; ++i) {
        result = multiplyVector(result, i); // Multiply result by i
    }

    reverse(result.begin(), result.end()); // Reverse to get most significant digit first
    return result;
}

/**
 * Prints the digits stored in a vector as a number.
 */
void printNumber(const vector<int>& number) {
    for (int digit : number) {
        cout << digit;
    }
    cout << endl;
}

// ---------- MAIN FUNCTION ----------
int main() {
    int n;
    cout << "Enter a number to compute factorial: ";
    cin >> n;

    vector<int> factorialResult = computeFactorial(n);

    cout << "Factorial of " << n << " is: ";
    printNumber(factorialResult);

    return 0;
}
