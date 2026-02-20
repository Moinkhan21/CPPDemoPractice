#include <iostream>
using namespace std;

void clearIthBit(int n, int i) {
    int mask = ~(1 << i);
    int ans = n & mask;
    cout << "After clearing: " << ans << endl;
}

int main() {

    cout << "Enter integer value: " << endl;
    int n;
    cin >> n;

    cout << "Enter value of i for clearing bit (masking): " << endl;
    int i;
    cin >> i;
 
    clearIthBit(n, i);

    return 0;
}