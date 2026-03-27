#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Fruit (Base Class - Level 1)
// ----------------------------------------------------------------------
// Represents basic fruit properties.
//
// DATA MEMBER:
//   • name → name of the fruit
// ======================================================================
class Fruit {
public:
    string name;
};

// ======================================================================
// CLASS: Mango (Derived from Fruit - Level 2)
// ----------------------------------------------------------------------
// Inherits properties of Fruit and adds its own.
//
// INHERITS:
//   • name
//
// ADDS:
//   • weight
// ======================================================================
class Mango : public Fruit {
public:
    int weight;
};

// ======================================================================
// CLASS: Alphanso (Derived from Mango - Level 3)
// ----------------------------------------------------------------------
// Demonstrates MULTILEVEL INHERITANCE.
//
// INHERITS:
//   • name (from Fruit)
//   • weight (from Mango)
//
// ADDS:
//   • sugarLevel
// ======================================================================
class Alphanso : public Mango {
public:
    int sugerLevel;  // (typo kept same as your code)
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // Object of most derived class
    Alphanso a;

    // Access all inherited members
    a.name = "Alphanso Mango";
    a.weight = 300;
    a.sugerLevel = 10;

    cout << a.name << " " << a.weight << " " << a.sugerLevel << endl;

    return 0;
}