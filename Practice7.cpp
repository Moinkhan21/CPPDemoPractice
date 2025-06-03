#include <iostream>
using namespace std;

bool checkPrime(int n) {
    int i = 2;  // Start checking from 2
    for(i=2; i<n; i++) {
        if(n % i == 0) {  // Check if n is divisible by i
            return false;  // If divisible, n is not prime
        }
    }
    return true;  // If no divisors found, n is prime
}

int main() {
    int n;
    cout << "Enter a number to check if it is prime: ";
    cin >> n;  // Read the number from user input

    bool isPrime = checkPrime(n);  // Check if the number is prime

    if (isPrime) {
        cout << n << " is a prime number." << endl;  // Output if the number is prime
    } else {
        cout << n << " is not a prime number." << endl;  // Output if the number is not prime
    }

    return 0;  // Return success
}