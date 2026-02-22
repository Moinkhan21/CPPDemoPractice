#include <iostream>
using namespace std;

bool checkPowerOf2(int n) {
    if((n & (n - 1)) == 0)
        return true;
    else
        return false;
}

int main() {

    cout << "Power of 2 ans: " << checkPowerOf2(16) << endl;
    return 0;
    
}