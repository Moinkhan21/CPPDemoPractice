#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
-------------------------------------------------------------
 Function: Sieve
 Purpose:  Generates prime numbers up to 'n' using the Sieve
           of Eratosthenes algorithm.
 Input:    Integer n (upper bound)
 Output:   A boolean vector 'sieve' where
           sieve[i] = true  → i is prime
           sieve[i] = false → i is NOT prime
-------------------------------------------------------------
*/
vector<bool> Sieve(int n){
    // Create a sieve of size n+1 and initialize all values as true
    // We will later mark non-primes (composite numbers) as false.
    vector<bool> sieve(n+1, true);

    // 0 and 1 are not prime numbers
    sieve[0] = sieve[1] = false;

    // Outer loop: run only up to sqrt(n) for optimization
    for(int i = 2; i * i <= n; i++){ 
        if(sieve[i] == true){ 
            // If i is prime, mark all multiples of i as non-prime
            // Optimization: Start from i*i (since smaller multiples
            // would have already been marked by smaller primes)
            int j = i * i;  
            while(j <= n){
                sieve[j] = false;  // Mark as non-prime
                j += i;            // Jump to the next multiple
            }
        }
    }
    return sieve; // Return the sieve array
}

/*
-------------------------------------------------------------
 Function: segSieve
 Purpose:  Generates prime numbers in a given range [L, R]
           using the Segmented Sieve technique.
 Input:    L (lower bound), R (upper bound)
 Output:   A boolean vector 'segSieve' where
           segSieve[i] = true  → (i + L) is prime
           segSieve[i] = false → (i + L) is NOT prime
-------------------------------------------------------------
*/
vector<bool> segSieve(int L, int R){
    // Step 1: Generate all prime numbers up to sqrt(R)
    // These primes are called "base primes" and will be used
    // to mark non-primes in the [L, R] range.
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for(int i = 0; i < sieve.size(); i++){
        if(sieve[i]){
            basePrimes.push_back(i); // Collect all prime numbers
        }
    }

    // Step 2: Create a boolean array for the segment [L, R]
    // Initially assume all numbers in [L, R] are prime (true)
    vector<bool> segSieve(R - L + 1, true);

    // Edge case: If L = 0 or 1, mark them as non-prime
    if(L == 0 || L == 1){
        segSieve[L] = false; 
    }

    // Step 3: Use base primes to mark non-primes in [L, R]
    for(auto prime : basePrimes){
        // Find the first multiple of 'prime' in the range [L, R]
        int first_mul = (L / prime) * prime; 

        // If this multiple is smaller than L, go to the next multiple
        if(first_mul < L){
            first_mul += prime;
        }

        // Ensure we start marking from max(prime*prime, first_mul)
        // because smaller multiples would have been marked already
        int j = max(first_mul, prime * prime);

        // Mark all multiples of 'prime' within [L, R] as non-prime
        while(j <= R){
            segSieve[j - L] = false; // j-L is the correct index in segSieve
            j += prime;
        }     
    }
    return segSieve; // Return the segmented sieve result
}

/*
-------------------------------------------------------------
 Main Function
 Purpose: Demonstrates how to find primes in a given range
-------------------------------------------------------------
*/
int main() {
    int L = 110; // Lower bound of the range
    int R = 130; // Upper bound of the range

    // Get the segmented sieve for [L, R]
    vector<bool> ss = segSieve(L, R);

    cout << "Prime numbers between " << L << " and " << R << " are:\n";
    for(int i = 0; i < ss.size(); i++){
        if(ss[i]){
            cout << i + L << " "; // Convert index back to actual number
        }
    }
    cout << endl;

    return 0;
}
