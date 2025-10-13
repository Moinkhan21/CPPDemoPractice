#include <iostream> // Header file for input/output operations
using namespace std; // Allows direct use of cout, cin, etc., without std::

// Class definition
class Maths {
public:

    // ✅ Function 1: Takes 2 integer parameters
    // Demonstrates function overloading - same function name, different parameter list
    int sum(int a, int b) {
        cout << "I am in first signature" << endl; // Identifies which function is being called
        return a + b; // Returns the sum of two integers
    }

    // ✅ Function 2: Takes 3 integer parameters
    // Different number of parameters → valid overload
    int sum(int a, int b, int c) {
        cout << "I am in second signature" << endl; // Identifies which overloaded version is used
        return a + b + c; // Returns sum of three integers
    }

    // ✅ Function 3: Takes one int and one float parameter
    // Different data types → another valid overload
    int sum(int a, float b) {
        cout << "I am in third signature" << endl; // Identifies which function runs
        return a + b + 10; // Returns result of adding int + float + 10
    }
};

// Main function
int main() {
    Maths obj; // Create an object of class Maths

    // Call 1: Matches (int, int) → first function executes
    cout << obj.sum(1, 3) << endl; // Output: "I am in first signature" → 4

    // Call 2: Matches (int, int, int) → second function executes
    cout << obj.sum(1, 3, 5) << endl; // Output: "I am in second signature" → 9

    // Call 3: Matches (int, float) → third function executes
    cout << obj.sum(1, 3.5f) << endl; // Output: "I am in third signature" → 14.5 (implicitly cast to int → 14)

    return 0; // Program ends successfully
}
