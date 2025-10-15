#include <iostream>
using namespace std;

int main() {
    const int x = 5;
    // *-> is not working => int *p = &x;
    // *p = 10;

    cout << x << endl;

    return 0;
}