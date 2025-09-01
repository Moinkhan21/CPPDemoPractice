#include <iostream>
using namespace std;

void printCounting(int n) {
    //Base case
    if(n == 0){
        return;
    }

    //Processing
    cout << n << " ";

    //Recursive call
    printCounting(n - 1);
}

int main() {

    int n;
    cout << "Enter a number: ";
    cin >> n;
    printCounting(n);
    return 0;
}
