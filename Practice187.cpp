#include <iostream>
using namespace std;

int main() {

    // 2. const with pointers
    const int *a = new int(2); //CONST data, NOT-CONST pointer
    cout << *a << endl;
    //*a = 20; // Can't change the content of pointer
    // cout << *a << endl;
    int b = 20;
    a = &b; //pointer itself can be reassinged
    cout << *a << endl;

    return 0;
}