#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to count number of primes less than n
int countPrimes(int n) {
    if (n <= 2) return 0; // No primes less than 2

    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    int ans = 0;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            ans++;

            // Start crossing out multiples from i*i
            // (as smaller multiples would already be marked)
            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of primes less than " << n << " = " << countPrimes(n) << endl;
    return 0;
}
