#include <iostream>
using namespace std;

// ---------------- CLASS: abc ----------------
// Purpose: Demonstrates the concept of **Deep Copy Constructor** in C++.
//
// Explanation:
// When a class dynamically allocates memory (like pointer `y` here),
// the default copy constructor only performs a **shallow copy**, 
// which means both objects share the same memory address for `y`.
// 
// This can cause problems (e.g., double deletion or unwanted data overwrite).
// To fix that, we define a **custom deep copy constructor**, which allocates 
// new memory and copies the content, not the address.
class abc
{
    public:
        int x;   // Simple integer variable (copied directly)
        int *y;  // Pointer variable (requires deep copy)

        // ---------- PARAMETERIZED CONSTRUCTOR ----------
        // Initializes `x` with `_x` and allocates dynamic memory for `y`
        // using `new int(_y)`, which stores `_y` in the newly allocated memory.
        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        // ---------- COPY CONSTRUCTOR (DEEP COPY) ----------
        // Called when a new object is created as a copy of another object.
        //
        // For example: `abc b = a;` or `abc b(a);`
        //
        // Steps performed here:
        // 1. Copy the value of `x` directly.
        // 2. Allocate **new memory** for `y` (to prevent sharing).
        // 3. Copy the content (*obj.y) instead of the pointer (obj.y).
        //
        // This ensures that both objects have independent copies of `y`.
        abc(const abc &obj) {
            x = obj.x;              // Copy the simple data
            y = new int(*obj.y);    // Allocate new memory and copy value
        }

        // ---------- MEMBER FUNCTION: print ----------
        // Displays:
        // - The value of `x`
        // - The memory address stored in `y` (pointer address)
        // - The actual value stored at that address (*y)
        //
        // Used to verify whether two objects share or have separate memory.
        void print() const
        {
            printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
        }

        // ---------- DESTRUCTOR ----------
        // Called automatically when an object goes out of scope or is deleted.
        //
        // Responsible for releasing the dynamically allocated memory (`y`),
        // preventing memory leaks.
        ~abc() {
            delete y; // Deallocate memory assigned by constructor
        }
};

int main()
{
    // ---------- OBJECT CREATION ----------
    // Creates object `a` using parameterized constructor.
    // x = 1, and dynamically allocates memory for y with value 2.
    abc a(1, 2);

    cout << "Print int a\n";
    a.print();  // Displays x, address of y, and value of *y

    // ---------- COPY CONSTRUCTOR CALL ----------
    // Two equivalent ways to call the copy constructor:
    // abc b(a);     // Direct initialization syntax
    // abc b = a;    // Copy initialization syntax
    //
    // Both invoke the copy constructor, creating `b` as a deep copy of `a`.
    //abc b(a);
    abc b = a; // Call hota hai, Copy constructor

    cout << "Print int b\n";
    b.print();  // Prints values of b (should be identical to a, but separate memory)

    // ---------- MODIFYING COPIED OBJECT ----------
    // Changing *b.y will NOT affect a.y because of deep copy.
    // If shallow copy were used, both would change.
    *b.y = 20;

    cout << "Print int b\n";
    b.print();  // b’s *y changed → affects only b’s memory block

    cout << "Print int a\n";
    a.print();  // a’s *y remains unchanged, proving deep copy works

    return 0;   // End of program; destructors of both objects are called
}
