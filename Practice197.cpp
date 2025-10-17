#include <iostream>
using namespace std;

// ---------------- CLASS: A ----------------
// Purpose: Represents a simple class that stores an integer `x`
// and provides getter, setter, and print functionalities.
// Demonstrates encapsulation, access control, and the use of
// friend classes/functions (currently commented out).
class A 
{
    int x;  // Private data member: accessible only inside class A

    public:
        // ---------- PARAMETERIZED CONSTRUCTOR ----------
        // Initializes the data member `x` using an initializer list.
        // The initializer list is more efficient than assignment in the constructor body.
        A(int _val) : x(_val){};

        // ---------- GETTER FUNCTION ----------
        // Returns the value of private data member `x`.
        // Declared as `const` since it doesn't modify the object.
        int getX() const { return x; }

        // ---------- SETTER FUNCTION ----------
        // Updates the private data member `x` with a new value.
        void setX(int _val) { x = _val; }

        // ---------- MEMBER FUNCTION: print ----------
        // Displays the current value of `x` on the console.
        // Declared as `const` because it does not modify the object.
        void print() const
        {
            cout << x << endl;
        }

        // ---------- COMMENTED FRIEND DECLARATIONS ----------
        // Friend declarations allow external classes or functions
        // to access private/protected members of this class.
        //
        // If uncommented, `class B` and the standalone `print()` function
        // would be able to directly access `x` even though it’s private.

        // friend class B;        // Makes class B a friend of class A
        // friend void print(const A &);  // Makes global function `print()` a friend
};

// ---------------- CLASS: B ----------------
// Purpose: Demonstrates how one class interacts with another class.
// The `print()` function here tries to access data from an object of class `A`.
// Without friendship, it can only access public members/methods of `A`.
class B
{
    public:
        // ---------- FUNCTION: print ----------
        // Accepts an object of type `A` (by reference) and prints its value.
        // Since class `A`’s member `x` is private, this function cannot
        // access it directly unless `B` is declared as a friend in class `A`.
        //
        // Therefore, we use the public function `a.print()` instead.
        void print(const A &a) 
        {
            // The following lines are commented because they would cause
            // a compilation error without friendship permission.
            // Uncommenting them requires friend access in class `A`.

            // cout << a.get() << endl;   // ❌ Invalid: No function named get()
            // cout << a.x << endl;       // ❌ Invalid: `x` is private inside class A

            // ✅ Valid: Calls A’s public print() method to display value of x
            a.print();
        }
};

// ---------- GLOBAL FUNCTION (COMMENTED OUT) ----------
// Purpose: A non-member function that could print the private
// value of `x` if it were declared as a friend in class `A`.
//
// Without the `friend` keyword in class `A`, accessing `a.x` here
// would lead to a compilation error.

// void print(const A &a)
// {
//     cout << a.x << endl;
// }

int main() {
    // ---------- MAIN FUNCTION EXECUTION ----------
    // Step 1: Create an object `a` of class A with initial value 5.
    A a(5);

    // Step 2: Create an object `b` of class B.
    B b;

    // Step 3: Call the `print()` function of class B.
    // This prints the value of `x` indirectly using A’s public function.
    b.print(a);

    // Step 4: End of program. Output should display:
    // 5
    return 0;
}
