#include <iostream>
#include <vector>
using namespace std;

// Function to generate prime numbers up to 'n' using Sieve of Eratosthenes
vector<bool> Sieve(int n) {
    // Step 1: Initialize a boolean vector of size n+1 (so index goes from 0 → n)
    // Initially, assume all numbers are prime (true)
    vector<bool> sieve(n + 1, true);

    // Step 2: Mark 0 and 1 as NOT prime (since primes are >= 2)
    sieve[0] = sieve[1] = false;

    // Step 3: Start checking from 2 up to sqrt(n)
    // If a number is prime, mark all its multiples as NOT prime
    for (int i = 2; i * i <= n; i++) {  
        // If i is still marked as prime
        if (sieve[i] == true) {
            // Optimization: Start marking multiples from i*i
            // Explanation:
            // All smaller multiples (like 2*i, 3*i, ..., (i-1)*i) 
            // would have already been marked by smaller primes.
            int j = i * i;

            // Step 4: Mark all multiples of i as NOT prime
            while (j <= n) {
                sieve[j] = false;  // j is divisible by i → not prime
                j += i;            // Move to the next multiple of i
            }
        }
    }

    // Step 5: Return the sieve array, where
    // true = prime, false = not prime
    return sieve;
}

int main() {
    int limit = 25;  // Upper limit for prime search
    vector<bool> sieve = Sieve(limit);

    cout << "Prime numbers up to " << limit << ": ";

    // Loop through sieve and print all numbers marked prime
    for (int i = 0; i <= limit; i++) {
        if (sieve[i]) {   // If true, i is prime
            cout << i << " ";
        }
    }

    return 0;
}
