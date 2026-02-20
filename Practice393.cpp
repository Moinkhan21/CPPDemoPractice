#include <iostream>
using namespace std;

int getIthBit(int n, int i) {
    int mask = 1 << i;
    int ans = n & mask;
    if(ans == 0)
        return 0;
    else
        return 1;
}

int main() {

    cout << "Enter integer value: " << endl;
    int n;
    cin >> n;

    cout << "Enter value of i for bit masking: " << endl;
    int i;
    cin >> i;
 
    int ans = getIthBit(n, i);
    cout << "After performing operation of bit masking the answer is: " << endl;
    cout << ans << endl;

    return 0;
}