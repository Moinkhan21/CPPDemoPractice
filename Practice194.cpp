#include <iostream>
using namespace std;

// ===============================
// Class Definition: abc
// Demonstrates Deep Copy Concept in C++
// ===============================
class abc
{
public:
    int x;   // Normal integer variable (stored directly inside the object)
    int* y;  // Pointer variable (stores address of an integer in heap memory)

    // -----------------------------------------------
    // Parameterized Constructor
    // Initializes 'x' directly and allocates memory for 'y' on the heap
    // -----------------------------------------------
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // -----------------------------------------------
    // Deep Copy Constructor
    // Called when one object is initialized from another (copy operation)
    // -----------------------------------------------
    abc(const abc &obj) {
        // Copy simple data members normally
        x = obj.x;

        // Allocate new memory for 'y' and copy the value stored at obj.y
        // This prevents two objects from pointing to the same memory location.
        y = new int(*obj.y);
    }

    // -----------------------------------------------
    // Function to print data members
    // Demonstrates memory address and stored values
    // -----------------------------------------------
    void print() const
    {
        // 'x' — stored directly in the object
        // 'y' — pointer storing the address of an integer in heap
        // '*y' — dereferencing pointer 'y' to print the actual value in heap
        printf("X: %d\nPTR Y: %p\nContent of Y (*y): %d\n\n", x, y, *y);
    }
};

// ===============================
// Main Function
// ===============================
int main()
{
    // -----------------------------------------------
    // Step 1: Create first object 'a' using parameterized constructor
    // 'x' = 1, '*y' = 2
    // -----------------------------------------------
    abc a(1, 2);
    cout << "Print object a\n";
    a.print();

    // -----------------------------------------------
    // Step 2: Create another object 'b' as a copy of 'a'
    // Calls the Copy Constructor (deep copy version)
    // -----------------------------------------------
    // abc b(a);  // Alternative syntax
    abc b = a;   // Copy constructor invoked here
    cout << "Print object b (after copy from a)\n";
    b.print();

    // -----------------------------------------------
    // Step 3: Modify the value pointed by 'y' in object 'b'
    // Since we used deep copy, 'a' and 'b' have different 'y' memory addresses.
    // Changing *b.y will NOT affect *a.y.
    // -----------------------------------------------
    *b.y = 20;

    // -----------------------------------------------
    // Step 4: Print object 'b' again after modification
    // -----------------------------------------------
    cout << "Print object b (after modifying *b.y)\n";
    b.print();

    // -----------------------------------------------
    // Step 5: Print object 'a' again to show that its value is unchanged
    // Confirms that deep copy successfully created separate memory for each object.
    // -----------------------------------------------
    cout << "Print object a (to verify it is unaffected)\n";
    a.print();

    return 0;
}
