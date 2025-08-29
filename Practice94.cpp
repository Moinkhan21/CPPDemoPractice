#include <iostream>
using namespace std;

int main() {
    int a = 5;  
    // Declare an integer variable 'a' and initialize it with value 5.

    // Creating a reference variable
    int& b = a;  
    // 'b' is a reference to 'a'.
    // A reference is like an alias (another name) for an existing variable.
    // So 'b' does not have its own memory — it directly refers to the memory of 'a'.

    cout << a << endl;  
    // Prints value of 'a' → 5
    cout << b << endl;  
    // Prints value of 'b', but since 'b' refers to 'a', this will also print 5.

    a++;  
    // Increment the value of 'a' by 1 → now 'a' becomes 6.

    cout << a << endl;  
    // Prints updated value of 'a' → 6
    cout << b << endl;  
    // Since 'b' is a reference to 'a', this will also print 6.

    b++;  
    // Increment the value of 'b' by 1.
    // But 'b' is a reference to 'a', so this operation increases 'a' as well.
    // Now 'a' becomes 7.

    cout << a << endl;  
    // Prints updated value of 'a' → 7
    cout << b << endl;  
    // Prints updated value of 'b' (same as 'a') → 7

    return 0;
}
