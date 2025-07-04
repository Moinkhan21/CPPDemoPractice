#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For reverse function
using namespace std;

string calcSum(int *a, int n, int *b, int m) {

    int carry = 0;
    string ans;
    int i = n - 1, j = m - 1;

    while(i >= 0 && j >= 0){
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0'); // Convert digit to character
        carry = x / 10; // Update carry for next iteration
        i--; j--;
    }

    // If there are remaining digits in either array
    while(i >= 0){
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
    }

    while(j >= 0){
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        j--;
    }

    // If there is a remaining carry
    if(carry){
        ans.push_back(carry + '0');
    }

    // The result is in reverse order
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    // Example arrays to test the sum calculation
    int a[] = {9, 9, 9}; // Represents the number 999
    int b[] = {1, 0, 0, 1}; // Represents the number 1001

    int n = sizeof(a) / sizeof(a[0]); // Size of first array
    int m = sizeof(b) / sizeof(b[0]); // Size of second array

    string result = calcSum(a, n, b, m);
    cout << "The sum is: " << result << endl; // Output should be "2000"

    return 0;
}