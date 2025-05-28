#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinaryMethod1(int n) {

    int binaryno = 0;
    int i = 0;

    // Method 1: Using a while loop, Division Method
    while(n>0) {
        int bit = n % 2;

        binaryno = (bit * pow(10, i++)) + binaryno;
        //cout << bit << endl;
        n = n / 2;
    }
    return binaryno;
}

int main() {
    int n;
    cin >> n;
    int binary = decimalToBinaryMethod1(n);
    cout << "Binary representation of " << n << " is: " << binary << endl;
}