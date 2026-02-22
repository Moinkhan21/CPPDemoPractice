#include <iostream>
using namespace std;

int countSetBitsFast(int n) {
    int count = 0;
    while(n != 0) {
        //remove last set bit
        n = (n & (n - 1));
        count++;
    }
    return count;
}

int main() {

    cout << "Number of set bits: " << countSetBitsFast(15) << endl;
    return 0;
}