#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n != 0) {
        int lastBit = n & 1;
        if(lastBit)
            count++;
        //Right shift
        n = n >> 1;
    }
    return count;
}

int main() {

    cout << "Number of set bits: " << countSetBits(15) << endl;
    return 0;

}