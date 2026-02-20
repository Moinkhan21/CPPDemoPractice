#include <iostream>
using namespace std;

void setIthBit(int n, int i) {

    int mask = 1 << i;
    int ans = n | mask;
    cout << "After setting: " << ans << endl;
    
}

int main() {

    cout << "Enter integer value: " << endl;
    int n;
    cin >> n;

    cout << "Enter value of i for bit masking: " << endl;
    int i;
    cin >> i;
 
    setIthBit(n, i);

    return 0;
}