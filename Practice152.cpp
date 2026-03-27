#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Animal (Base Class)
// ----------------------------------------------------------------------
// Represents a base class with common properties.
//
// MEMBERS:
//   • age, weight → data members
//   • eat()       → behavior
// ======================================================================
class Animal {
public:
    int age;
    int weight;

    void eat() {
        cout << "Eating..." << endl;
    }
};

// ======================================================================
// CLASS: Dog (Public Inheritance)
// ----------------------------------------------------------------------
// Public members of Animal remain PUBLIC in Dog.
// ======================================================================
class Dog : public Animal {
    // age, weight → public
    // eat() → public
};

// ======================================================================
// CLASS: Cat (Protected Inheritance)
// ----------------------------------------------------------------------
// Public members of Animal become PROTECTED in Cat.
//
// Cannot access directly outside the class,
// but accessible inside class methods.
// ======================================================================
class Cat : protected Animal {
public:
    void print() {
        cout << "Cat: " << this->age << " " << this->weight << endl;
    }
};

// ======================================================================
// CLASS: Chimpanzee (Private Inheritance)
// ----------------------------------------------------------------------
// Public members of Animal become PRIVATE in Chimpanzee.
//
// Accessible only inside the class.
// ======================================================================
class Chimpanzee : private Animal {
public:
    void print() {
        cout << "Chimpanzee: " << this->age << " " << this->weight << endl;
    }
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // --------------------------------------------------
    // PUBLIC INHERITANCE
    // --------------------------------------------------
    Dog d1;
    d1.age = 5;       // ✅ accessible
    d1.weight = 20;   // ✅ accessible
    d1.eat();         // ✅ accessible

    // --------------------------------------------------
    // PROTECTED INHERITANCE
    // --------------------------------------------------
    Cat c1;
    // c1.age ❌ NOT accessible
    // c1.eat() ❌ NOT accessible
    c1.print();       // ✅ accessible via public method

    // --------------------------------------------------
    // PRIVATE INHERITANCE
    // --------------------------------------------------
    Chimpanzee ch1;
    // ch1.age ❌ NOT accessible
    // ch1.eat() ❌ NOT accessible
    ch1.print();      // ✅ accessible via public method

    return 0;
}