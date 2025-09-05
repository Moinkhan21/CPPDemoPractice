#include <iostream>   // For standard input/output (cin, cout)
using namespace std;

// Recursive function to print numbers in decreasing order from n to 1
void printCounting(int n) {
    // Base case: if n reaches 0, stop the recursion
    if (n == 0) {
        return;  // Exit the function
    }

    // Processing: print the current value of n
    cout << n << " ";

    // Recursive call: call the same function with (n-1)
    // This reduces the problem size and moves towards the base case
    printCounting(n - 1);
}

int main() {
    int n;

    // Ask user for input
    cout << "Enter a number: ";
    cin >> n;

    // Call the recursive function
    printCounting(n);

    return 0; // End of program
}
