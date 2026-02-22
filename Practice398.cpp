#include <iostream>
using namespace std;

void clearLastBits(int n, int i) {
    int mask = (-1 << i);
    n = n & mask;
    cout << "After clearing last i bits: " << n << endl;
}

int main() {
    
    int n = 7;
    clearLastBits(n, 2);

    return 0;
}