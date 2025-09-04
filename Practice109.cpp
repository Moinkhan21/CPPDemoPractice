#include <iostream>
using namespace std;

void printDigits(int n){
    //Base case
    if(n == 0){
        return;
    }

    int newValueOfN = n / 10;

    //Recursive call
    printDigits(newValueOfN);

    //Solve only one case
    int digit = n % 10;
    cout << digit << " ";
}

int main(){
    int n = 0;

    if(n == 0){
        cout << 0 << endl;
    }
    printDigits(n);

    return 0;
}