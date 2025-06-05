#include <iostream>
using namespace std;

// Function to check whether a number is prime
bool checkPrime(int n) {
    // Edge case: numbers less than 2 are not prime
    if (n < 2) {
        return false;
    }

    // Start checking from 2 up to sqrt(n) for efficiency
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;  // If divisible, not prime
        }
    }
    return true;  // No divisors found, number is prime
}

int main() {
    int n;
    cout << "Enter a number to check if it is prime: ";
    cin >> n;

    // Check and display whether the number is prime
    if (checkPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    // Print all prime numbers from 2 to n
    cout << "\nList of prime numbers from 2 to " << n << ":\n";
    for (int i = 2; i <= n; i++) {
        if (checkPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;  // End line after printing all primes
    return 0;      // Successful execution
}
