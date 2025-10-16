#include <iostream>
using namespace std;

int main() {

    //CONST pointer, CONST data
    const int *const a = new int(10);
    cout << *a << endl;
    // -> *a = 50;
    int b = 100;
    // -> a = &b;
    return 0;
}