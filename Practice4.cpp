#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;  // Input the size (number of rows or levels for the patterns)
    int c = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << c;  // Print the current number
            c++;
        }
        cout << endl;  // Move to the next row
    }

    int start = c - n;
    for(int i=0; i<n; i++) {
        int k = start;
        for(int j=0; j<=n-i-1; j++) {
            cout << k;  // Print the current number
            k++;
        }
        start = start - (n - i - 1);  // Update start for the next row
        cout << endl;  // Move to the next row
    }
}