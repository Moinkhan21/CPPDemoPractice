#include <iostream> // Header file for input-output operations (cout, cin, etc.)
using namespace std; // Allows us to use standard library objects without std:: prefix

// Class definition
class Param {
public:
    int val; // Data member to store an integer value

    // Operator overloading function for '+' operator
    // This function customizes how the '+' operator works for Param objects
    void operator+(Param obj2) {
        // 'this->val' refers to the value of the current object (left operand)
        int value1 = this->val;

        // 'obj2.val' refers to the value of the second object (right operand)
        int value2 = obj2.val;

        // Instead of performing normal addition, we are printing the difference
        // The logic prints (value2 - value1)
        cout << (value2 - value1) << endl;
    }
};

int main() {
    // Create two objects of class Param
    Param obj1, obj2;

    // Assign values to both objects
    obj1.val = 7; // obj1 holds 7
    obj2.val = 9; // obj2 holds 9

    // Using the overloaded '+' operator
    // Internally calls obj1.operator+(obj2)
    // Expected output: 9 - 7 = 2
    obj1 + obj2;

    return 0; // End of program
}
