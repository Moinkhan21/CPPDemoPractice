#include <iostream>   // For standard input/output
using namespace std;

// Function to calculate the nth Fibonacci number using recursion
int fib(int n) {
    // Base case 1: If n == 1, return the first term of Fibonacci series
    if (n == 1) {
        return 0;  // First Fibonacci number is 0
    }

    // Base case 2: If n == 2, return the second term of Fibonacci series
    if (n == 2) {
        return 1;  // Second Fibonacci number is 1
    }

    // Recursive relation:
    // fib(n) = fib(n-1) + fib(n-2)
    // Meaning: nth Fibonacci number is the sum of the (n-1)th and (n-2)th numbers
    int ans = fib(n - 1) + fib(n - 2);

    // Return the calculated result
    return ans;
}

int main() {
    int n;

    // Ask the user which Fibonacci term they want
    cout << "Enter the term you want to see: ";
    cin >> n;

    // Call the recursive Fibonacci function
    int ans = fib(n);

    // Print the result
    cout << "The " << n << "th term of the Fibonacci sequence is: " << ans << endl;

    return 0; // Program ends successfully
}
