#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Animal
// ----------------------------------------------------------------------
// Demonstrates ENCAPSULATION in C++
//
// ENCAPSULATION:
//   • Wrapping data + functions into a single unit (class)
//   • Restricting direct access to data using access modifiers
//
// ACCESS LEVELS USED:
//   • private  → data hiding
//   • public   → controlled access via methods
// ======================================================================
class Animal {

private:
    int age;      // Hidden from outside world
    int weight;   // Hidden (not directly accessible)

public:

    // --------------------------------------------------
    // FUNCTION: eat()
    // --------------------------------------------------
    // Behavior of Animal
    void eat() {
        cout << "Eating..." << endl;
    }

    // --------------------------------------------------
    // GETTER: getAge()
    // --------------------------------------------------
    // Provides READ access to private variable
    int getAge() {
        return this->age;
    }

    // --------------------------------------------------
    // SETTER: setAge()
    // --------------------------------------------------
    // Provides CONTROLLED WRITE access
    void setAge(int age) {
        this->age = age;
    }
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    Animal a;

    // Setting age using setter
    a.setAge(10);

    // Accessing age using getter
    cout << "Age: " << a.getAge() << endl;

    // Calling behavior
    a.eat();

    return 0;
}