#include <iostream>
using namespace std;

// ---------------- CLASS: A ----------------
// Purpose: This class stores a private integer `x` and provides 
// access to it through getter/setter functions.
// It also demonstrates the concept of **friend classes** and 
// **friend functions**, which allow specific external entities 
// to access private members of this class.
class A 
{
    int x; // Private data member (not accessible outside directly)

    public:
        // ---------- PARAMETERIZED CONSTRUCTOR ----------
        // Initializes `x` using an initializer list.
        // Example: A a(5);  →  sets x = 5
        A(int _val) : x(_val){};

        // ---------- GETTER FUNCTION ----------
        // Returns the value of private variable `x`.
        // Declared `const` because it does not modify the object.
        int getX() const { return x; }

        // ---------- SETTER FUNCTION ----------
        // Updates the value of `x` with the provided parameter `_val`.
        void setX(int _val) { x = _val; }

        // ---------- FRIEND DECLARATIONS ----------
        // 1️⃣ friend class B;
        //     → Allows all member functions of class `B` to access 
        //       private and protected members of class `A` directly.
        //
        // 2️⃣ friend void print(const A &);
        //     → Grants access to a specific global function (print) 
        //       so it can access `x` directly, even though it’s private.
        //
        // These declarations demonstrate controlled access — 
        // only the specified class and function gain private access.
        friend class B;
        friend void print(const A &);
};

// ---------------- CLASS: B ----------------
// Purpose: Demonstrates **friend class** behavior.  
// Since `B` is declared as a friend of `A`, it can access
// private members of `A` directly.
class B
{
    public:
        // ---------- MEMBER FUNCTION: print ----------
        // Prints the value of `x` from an object of class `A`.
        // Normally this would not be allowed (since `x` is private),
        // but because `B` is a **friend class**, it can access `x` directly.
        void print(const A &a) 
        {
            // The following line is commented out because it uses 
            // a non-existent function name (`get` instead of `getX`):
            // cout << a.get() << endl;   // ❌ would cause an error if uncommented

            // ✅ Directly access private member `x` from A (allowed via friendship)
            cout << a.x << endl;
        }
};

// ---------------- GLOBAL FUNCTION: print ----------------
// Purpose: A **friend function** of class `A`.
// Because it is declared as `friend void print(const A &);` inside class `A`,
// it can access the private member `x` directly.
// Demonstrates **friend function** concept.
void print(const A &a)
{
    // ✅ Allowed: this global function can access `a.x` directly
    // because it was declared as a friend inside class `A`.
    cout << a.x << endl;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    // Step 1️⃣: Create an object of class A with value 5.
    // This calls the parameterized constructor A(int _val)
    A a(5);

    // Step 2️⃣: Create an object of class B.
    // This will be used to access class A’s data.
    B b;

    // Step 3️⃣: Call B’s print() function and pass object `a`.
    // Since B is a friend of A, it can directly access private `x`.
    b.print(a);

    // ✅ Output:
    // 5
    //
    // Note: The global function `print(a)` (defined below) can also
    // access `x` because it’s declared as a friend function.
    // However, it’s not called here in main().
    return 0;
}
