#include <iostream>
using namespace std;

int main() {
    // 3. CONST Pointer, but NON-CONST data
    int *const a = new int(2);
    cout << *a << endl;
    *a = 20; //Chal jayega
    cout << *a << endl;
    int b = 50;
    // -> a = &b; // Nahi chalega, CONST pointer
}