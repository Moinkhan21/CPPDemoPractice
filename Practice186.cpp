#include <iostream>
using namespace std;

int main() {
    // 2. const with pointers
    int *a = new int;
    *a = 2;
    cout << *a << endl;
    delete a;
    int b = 5;
    a = &b;
    cout << *a << endl;

    return 0;
}