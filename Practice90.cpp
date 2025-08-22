#include <iostream>
using namespace std;

int fastExponentiation(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            //Odd
            ans = ans*a;
        }
        //Even
        a = a*a;
        b >>= 1; // b = b/2
    }
    return ans;
} // 0(logb)

int slowExponentiation(int a, int b){
    int ans = 1;
    for(int i = 0; i < b; ++i){
        ans*=a;
    }
    return ans;
} // 0(b)

int main() {
    cout << slowExponentiation(5, 4) << endl;
    cout << fastExponentiation(5, 4) << endl;
    return 0;
}