#include <iostream>
using namespace std;

void clearIthBit(int& n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int& n, int i, int target) {
    clearIthBit(n, i);
    int mask = target << i;
    n = n | mask;
    cout << "After updating: " << n << endl;
}

int main() {

    cout << "Enter integer value: " << endl;
    int n;
    cin >> n;

    cout << "Enter value of i for clearing bit (masking): " << endl;
    int i;
    cin >> i;

    cout << "Targeting the value: " << endl;
    int target;
    cin >> target;
 
    updateIthBit(n, i, target);

    return 0;
}